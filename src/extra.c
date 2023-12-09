/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:35:29 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/12/09 14:51:40 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	check_last_row_rectan(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[game->map_rows][i])
		i++;
	if (i != game->map_cols - 1)
	{
		write(1, "Error\nLast row is incorrect\n", 28);
		return (1);
	}
	return (0);
}

int	check_playable(t_game *game)
{
	int	p;
	int	e;
	int	c;

	e = 0;
	p = 0;
	c = 0;
	check_playable_row(game, &c, &p, &e);
	if (c == 0 || p == 0 || e == 0)
		return (1);
	return (0);
}

int	check_filename(char *file)
{
	int	i;

	i = 0;
	while (file[i])
	{
		if (file[i] == '.')
		{
			if (!(file[i + 1] == 'b' && file[i + 2] == 'e' \
			&& file[i + 3] == 'r' && !(file[i + 4])))
			{
				write(1, "Error\nProgramm accepts only .ber files\n", 39);
				return (1);
			}
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_char(t_game *game, int *p, int *e, int i)
{
	int	j;

	j = 0;
	while (game->map[i][j + 1])
	{
		if ((game->map[i][j] != 'P' && game->map[i][j] != 'E'\
		&& game->map[i][j] != '1' && game->map[i][j] != '0'\
		&& game->map[i][j] != 'C') \
		|| *p > 1 || *e > 1)
			return (1);
		if (game->map[i][j] == 'P')
			*p += 1;
		if (game->map[i][j] == 'E')
			*e += 1;
		j++;
	}
	return (0);
}

void	door_locked_up_down(t_game *game, int door_row, int door_col)
{
	if (game->player_position == UP)
	{
		if (game->map[door_row + 1][door_col] == '1')
			return ;
		if (game->map[door_row + 1][door_col] == 'C')
			game->score += 1;
		game->map[door_row - 1][door_col] = '0';
		game->map[door_row + 1][door_col] = 'P';
		put_player(game, door_col, door_row + 1);
		mlx_put_image_to_window(game->mlx, game->window, \
		game->textures.ground, door_col * 32, (door_row - 1) * 32);
	}
	else if (game->player_position == DOWN)
	{
		if (game->map[door_row - 1][door_col] == '1')
			return ;
		if (game->map[door_row - 1][door_col] == 'C')
			game->score += 1;
		game->map[door_row + 1][door_col] = '0';
		game->map[door_row - 1][door_col] = 'P';
		put_player(game, door_col, door_row - 1);
		mlx_put_image_to_window(game->mlx, game->window, \
		game->textures.ground, door_col * 32, (door_row + 1) * 32);
	}
}
