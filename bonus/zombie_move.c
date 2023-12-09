/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:39:52 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/12/09 16:34:26 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

int	zombie_right(t_game *game, int width, int height)
{
	if (game->map[height][width + 1] == '1' || \
		game->map[height][width + 1] == 'C' || \
		game->map[height][width + 1] == 'Z' || \
		game->map[height][width + 1] == 'E')
		return (1);
	game->map[height][width] = '0';
	game->map[height][width + 1] = 'Z';
	mlx_put_image_to_window(game->mlx, game->window, \
	game->textures.ground, 0 + width * 32, 0 + (height * 32));
	mlx_put_image_to_window(game->mlx, game->window, \
	game->zombie_idle_front_1, (width + 1) * 32, height * 32);
	return (0);
}

int	zombie_left(t_game *game, int width, int height)
{
	if (game->map[height][width - 1] == '1' || \
		game->map[height][width - 1] == 'C' || \
		game->map[height][width - 1] == 'Z' || \
		game->map[height][width - 1] == 'E')
		return (1);
	game->map[height][width] = '0';
	game->map[height][width - 1] = 'Z';
	mlx_put_image_to_window(game->mlx, game->window, \
	game->textures.ground, 0 + width * 32, 0 + (height * 32));
	mlx_put_image_to_window(game->mlx, game->window, \
	game->zombie_idle_front_1, (width - 1) * 32, height * 32);
	return (0);
}

int	zombie_up(t_game *game, int width, int height)
{
	if (game->map[height - 1][width] == '1' || \
		game->map[height - 1][width] == 'C' || \
		game->map[height - 1][width] == 'Z' || \
		game->map[height - 1][width] == 'E')
		return (1);
	game->map[height][width] = '0';
	game->map[height - 1][width] = 'Z';
	mlx_put_image_to_window(game->mlx, game->window, \
	game->textures.ground, 0 + width * 32, 0 + (height * 32));
	mlx_put_image_to_window(game->mlx, game->window, \
	game->zombie_idle_front_1, width * 32, (height - 1) * 32);
	return (0);
}

int	zombie_down(t_game *game, int width, int height)
{
	if (game->map[height + 1][width] == '1' || \
		game->map[height + 1][width] == 'C' || \
		game->map[height + 1][width] == 'Z' || \
		game->map[height + 1][width] == 'E')
		return (1);
	game->map[height][width] = '0';
	game->map[height + 1][width] = 'Z';
	mlx_put_image_to_window(game->mlx, game->window, \
	game->textures.ground, 0 + width * 32, 0 + (height * 32));
	mlx_put_image_to_window(game->mlx, game->window, \
	game->zombie_idle_front_1, width * 32, (height + 1) * 32);
	return (0);
}

void	zombie_move(t_game *game, int width, int height)
{
	int	random;
	int	i;

	i = 0;
	while (i < 4)
	{
		random = rand() % 4;
		if (random == UP && zombie_up(game, width, height) == 0)
			break ;
		else if (random == RIGHT && zombie_right(game, width, height) == 0)
			break ;
		else if (random == LEFT && zombie_left(game, width, height) == 0)
			break ;
		else if (random == DOWN && zombie_down(game, width, height) == 0)
			break ;
		i++;
	}
}
