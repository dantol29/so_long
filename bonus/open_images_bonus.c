/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_images_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:47:30 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/12/09 11:27:54 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

static int	open_ground_coins_door(t_game *game)
{
	game->textures.ground = mlx_xpm_file_to_image(game->mlx, \
	"assets/dirt.xpm", &game->width, &game->height);
	game->textures.coin = mlx_xpm_file_to_image(game->mlx, \
	"assets/coin.xpm", &game->width, &game->height);
	game->textures.door = mlx_xpm_file_to_image(game->mlx, \
	"assets/door.xpm", &game->width, &game->height);
	game->textures.wall = mlx_xpm_file_to_image(game->mlx, \
	"assets/wall.xpm", &game->width, &game->height);
	game->digits.six = mlx_xpm_file_to_image(game->mlx, \
	"assets/six.xpm", &game->width, &game->height);
	game->digits.seven = mlx_xpm_file_to_image(game->mlx, \
	"assets/seven.xpm", &game->width, &game->height);
	game->digits.eight = mlx_xpm_file_to_image(game->mlx, \
	"assets/eight.xpm", &game->width, &game->height);
	game->digits.nine = mlx_xpm_file_to_image(game->mlx, \
	"assets/nine.xpm", &game->width, &game->height);
	return (0);
}

static int	open_zombies(t_game *game)
{
	game->zombie_idle_front_1 = mlx_xpm_file_to_image(game->mlx, \
	"assets/zombie_idle_front_1.xpm", &game->width, &game->height);
	game->zombie_idle_front_2 = mlx_xpm_file_to_image(game->mlx, \
	"assets/zombie_idle_front_2.xpm", &game->width, &game->height);
	game->zombie_idle_front_3 = mlx_xpm_file_to_image(game->mlx, \
	"assets/zombie_idle_front_3.xpm", &game->width, &game->height);
	game->zombie_idle_front_4 = mlx_xpm_file_to_image(game->mlx, \
	"assets/zombie_idle_front_4.xpm", &game->width, &game->height);
	game->digits.zero = mlx_xpm_file_to_image(game->mlx, \
	"assets/zero.xpm", &game->width, &game->height);
	game->digits.one = mlx_xpm_file_to_image(game->mlx, \
	"assets/one.xpm", &game->width, &game->height);
	game->digits.two = mlx_xpm_file_to_image(game->mlx, \
	"assets/two.xpm", &game->width, &game->height);
	game->digits.three = mlx_xpm_file_to_image(game->mlx, \
	"assets/three.xpm", &game->width, &game->height);
	game->digits.four = mlx_xpm_file_to_image(game->mlx, \
	"assets/four.xpm", &game->width, &game->height);
	game->digits.five = mlx_xpm_file_to_image(game->mlx, \
	"assets/five.xpm", &game->width, &game->height);
	return (0);
}

void	open_images(t_game *game)
{
	game->height = HEIGHT;
	game->width = WIDTH;
	game->current_frame = 0;
	game->player.player_idle_right_1 = mlx_xpm_file_to_image(game->mlx, \
	"assets/player_idle_right_1.xpm", &game->width, &game->height);
	game->player.player_idle_right_2 = mlx_xpm_file_to_image(game->mlx, \
	"assets/player_idle_right_2.xpm", &game->width, &game->height);
	game->player.player_idle_left_1 = mlx_xpm_file_to_image(game->mlx, \
	"assets/player_idle_left_1.xpm", &game->width, &game->height);
	game->player.player_idle_left_2 = mlx_xpm_file_to_image(game->mlx, \
	"assets/player_idle_left_2.xpm", &game->width, &game->height);
	game->player.player_idle_top_1 = mlx_xpm_file_to_image(game->mlx, \
	"assets/player_idle_top_1.xpm", &game->width, &game->height);
	game->player.player_idle_top_2 = mlx_xpm_file_to_image(game->mlx, \
	"assets/player_idle_top_2.xpm", &game->width, &game->height);
	game->player.player_idle_down_1 = mlx_xpm_file_to_image(game->mlx, \
	"assets/player_idle_down_1.xpm", &game->width, &game->height);
	game->player.player_idle_down_2 = mlx_xpm_file_to_image(game->mlx, \
	"assets/player_idle_down_2.xpm", &game->width, &game->height);
	open_zombies(game);
	open_ground_coins_door(game);
}

void	put_coin(t_game *game, int width, int height)
{
	mlx_put_image_to_window(game->mlx, game->window, \
	game->textures.coin, 0 + width * 32, 0 + (height * 32));
}

void	put_player(t_game *game, int width, int height)
{
	if (game->player_position == RIGHT)
		right_animation(game, width, height);
	else if (game->player_position == LEFT)
		left_animation(game, width, height);
	else if (game->player_position == UP)
		down_animation(game, width, height);
	else if (game->player_position == DOWN)
		top_animation(game, width, height);
	game->x = width;
	game->y = height;
}
