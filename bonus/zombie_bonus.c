/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:38:48 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/12/09 15:39:50 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

void	add_zombie(t_game *game)
{
	int	i;
	int	j;
	int	counter;

	j = 0;
	counter = 0;
	while (game->map[j])
	{
		i = 0;
		while (game->map[j][i])
		{
			if (game->map[j][i] == '0')
			{
				counter++;
				if (counter == 20)
				{
					game->map[j][i] = 'Z';
					counter = 0;
				}
			}
			i++;
		}
		j++;
	}
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

void	check_playable_row(t_game *game, int *c, int *p, int *e)
{
	int	j;
	int	i;

	i = 0;
	while (game->map[i + 1])
	{
		j = 0;
		while (game->map[i][j + 1])
		{
			if (game->map[i][j] == 'C')
				*c = 1;
			if (game->map[i][j] == 'P')
				*p = 1;
			if (game->map[i][j] == 'E')
				*e = 1;
			j++;
		}
		i++;
	}
}
