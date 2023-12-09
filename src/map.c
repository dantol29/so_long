/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:35:59 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/12/09 14:52:06 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	print_map(char *line, t_game *game, int index)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '1')
			mlx_put_image_to_window(game->mlx, game->window, \
		game->textures.wall, 0 + i * 32, 0 + (index * 32));
		else if (line[i] == '0')
			mlx_put_image_to_window(game->mlx, game->window, \
		game->textures.ground, 0 + i * 32, 0 + (index * 32));
		else if (line[i] == 'C')
			mlx_put_image_to_window(game->mlx, game->window, \
		game->textures.coin, 0 + i * 32, 0 + (index * 32));
		else if (line[i] == 'E')
			mlx_put_image_to_window(game->mlx, game->window, \
		game->textures.door, 0 + i * 32, 0 + (index * 32));
		else if (line[i] == 'P')
			put_player(game, i, index);
		i++;
	}
}

void	add_graphics(t_game *game)
{
	int		i;

	i = 0;
	game->score = 0;
	while (game->map[i] != NULL)
	{
		print_map(game->map[i], game, i);
		i++;
	}
}

void	fill_map(t_game *game, int lines, char *map)
{
	int	file;
	int	i;

	i = 0;
	file = open(map, O_RDWR);
	game->moves = 0;
	game->player_position = 0;
	game->map = malloc(sizeof(char *) * (lines + 1));
	game->map[0] = get_next_line(file);
	while (i < lines)
	{
		i++;
		game->map[i] = get_next_line(file);
	}
	if (check_map(map, game) == 1)
		exit(EXIT_FAILURE);
	if (valid_path(game) == 1)
	{
		free_map(game);
		write(1, "Error\nNo valid path\n", 20);
		exit(EXIT_FAILURE);
	}
	close(file);
}

int	save_map(char *map, t_game *game)
{
	int		file;
	int		linecount;
	char	*line;

	linecount = 0;
	file = open(map, O_RDWR);
	if (file == -1)
	{
		write(1, "Error\nMap does not exist\n", 25);
		return (1);
	}
	line = get_next_line(file);
	if (line == NULL)
		exit(EXIT_FAILURE);
	while (line)
	{
		free(line);
		line = get_next_line(file);
		linecount++;
	}
	close(file);
	fill_map(game, linecount, map);
	free(line);
	return (0);
}
