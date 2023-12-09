/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:43:18 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/12/09 15:24:14 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

static int	check_last_row(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
		{
			write(1, "Error\nLast row has to contain only walls\n", 41);
			return (1);
		}
		i++;
	}
	return (0);
}

static int	check_rows(t_game *game, int linecount)
{
	int	row_len;
	int	i;

	row_len = 0;
	while (game->map[0][row_len + 1])
	{
		if (game->map[0][row_len] != '1')
			return (1);
		row_len++;
	}
	if (row_len < 3)
		return (1);
	i = 0;
	while (game->map[i + 1])
	{
		if ((int)ft_strlen(game->map[i]) < game->map_cols || \
		(game->map[i][row_len] && i + 1 == linecount))
			return (1);
		if (game->map[i][row_len + 1] || !(game->map[i][row_len - 1]))
			return (1);
		if (game->map[i][0] != '1' || game->map[i][row_len - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

static int	check_elements(t_game *game)
{
	int	i;
	int	p;
	int	e;

	i = 0;
	p = 0;
	e = 0;
	while (game->map[i])
	{
		if (check_char(game, &p, &e, i) == 1)
			return (1);
		i++;
	}
	return (0);
}

static int	advanced_checks(t_game *game, int linecount, char *map)
{
	if (check_filename(map) == 1)
		return (1);
	if (check_last_row(game->map[linecount - 1]) == 1)
		return (1);
	if (check_rows(game, linecount) == 1)
	{
		write(1, "Error\nThe map must be surrounded by walls/ectangular\n", 58);
		return (1);
	}
	if (check_elements(game) == 1)
	{
		write(1, "Error\nThe map does not have all components\n", 57);
		return (1);
	}
	if (check_playable(game) == 1)
	{
		write(1, "Error\nThe map is not playable\n", 30);
		return (1);
	}
	if (check_last_row_rectan(game) == 1)
		return (1);
	return (0);
}

int	check_map(char *map, t_game *game)
{
	int		linecount;
	int		colcount;

	linecount = 0;
	while (game->map[linecount])
		linecount++;
	colcount = 0;
	while (game->map[0][colcount])
		colcount++;
	game->map_cols = colcount;
	game->map_rows = linecount - 1;
	if (advanced_checks(game, linecount, map) == 1)
	{
		free_map(game);
		return (1);
	}
	return (0);
}
