/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:41:55 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/12/09 12:35:00 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	validmove(t_game *game, int **visited, int row, int col)
{
	return (game->map[row][col] != '1' && !visited[row][col]);
}

void	floodfill(t_game *game, int row, int col, int **visited)
{
	if (!validmove(game, visited, row, col) || visited[row][col])
		return ;
	if (game->map[row][col] == 'C')
		game->flood_fill_coins += 1;
	visited[row][col] = 1;
	floodfill(game, row - 1, col, visited);
	floodfill(game, row + 1, col, visited);
	floodfill(game, row, col - 1, visited);
	floodfill(game, row, col + 1, visited);
}

void	player_position(t_game *game, int i, int *player_col, int *player_row)
{
	int	j;

	j = 0;
	game->flood_fill_coins = 0;
	game->coins = 0;
	while (game->map[i][j])
	{
		if (game->map[i][j] == 'P')
		{
			*player_row = i;
			*player_col = j;
			break ;
		}
		j++;
	}
}

void	exit_position(t_game *game)
{
	int	j;
	int	i;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'E')
			{
				game->exit_row = i;
				game->exit_col = j;
			}
			if (game->map[i][j] == 'C')
				game->coins += 1;
			j++;
		}
		i++;
	}
}

int	valid_path(t_game *game)
{
	int	i;
	int	p_row;
	int	p_col;
	int	**visited;

	visited = ft_calloc(game->map_rows, sizeof(int *));
	i = 0;
	while (i < game->map_rows)
	{
		visited[i] = ft_calloc(game->map_cols, sizeof(int *));
		i++;
	}
	i = 0;
	while (game->map[i])
	{
		player_position(game, i, &p_col, &p_row);
		i++;
	}
	exit_position(game);
	floodfill(game, p_row, p_col, visited);
	i = visited[p_row][p_col] && visited[game->exit_row][game->exit_col];
	free_visited(visited, game);
	if (game->flood_fill_coins != game->coins || !i)
		return (1);
	return (0);
}
