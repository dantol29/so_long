/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:21:11 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/12/08 18:29:06 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

void	zombie_animation(t_game *game, int width, int height)
{
	if (game->current_frame == 0)
		mlx_put_image_to_window(game->mlx, game->window, \
		game->zombie_idle_front_1, 0 + width * 32, 0 + (height * 32));
	else if (game->current_frame == 1)
		mlx_put_image_to_window(game->mlx, game->window, \
		game->zombie_idle_front_2, 0 + width * 32, 0 + (height * 32));
	else if (game->current_frame == 2)
		mlx_put_image_to_window(game->mlx, game->window, \
		game->zombie_idle_front_3, 0 + width * 32, 0 + (height * 32));
	else if (game->current_frame == 3)
		mlx_put_image_to_window(game->mlx, game->window, \
		game->zombie_idle_front_4, 0 + width * 32, 0 + (height * 32));
}

void	left_animation(t_game *game, int width, int height)
{
	if (game->current_frame == 0 || game->current_frame == 1)
		mlx_put_image_to_window(game->mlx, game->window, \
		game->player.player_idle_left_1, 0 + width * 32, 0 + (height * 32));
	else if (game->current_frame == 2 || game->current_frame == 3)
		mlx_put_image_to_window(game->mlx, game->window, \
		game->player.player_idle_left_2, 0 + width * 32, 0 + (height * 32));
}

void	right_animation(t_game *game, int width, int height)
{
	if (game->current_frame == 0 || game->current_frame == 1)
		mlx_put_image_to_window(game->mlx, game->window, \
		game->player.player_idle_right_1, 0 + width * 32, 0 + (height * 32));
	else if (game->current_frame == 2 || game->current_frame == 3)
		mlx_put_image_to_window(game->mlx, game->window, \
		game->player.player_idle_right_2, 0 + width * 32, 0 + (height * 32));
}

void	top_animation(t_game *game, int width, int height)
{
	if (game->current_frame == 0 || game->current_frame == 1)
		mlx_put_image_to_window(game->mlx, game->window, \
		game->player.player_idle_top_1, 0 + width * 32, 0 + (height * 32));
	else if (game->current_frame == 2 || game->current_frame == 3)
		mlx_put_image_to_window(game->mlx, game->window, \
		game->player.player_idle_top_2, 0 + width * 32, 0 + (height * 32));
}

void	down_animation(t_game *game, int width, int height)
{
	if (game->current_frame == 0 || game->current_frame == 1)
		mlx_put_image_to_window(game->mlx, game->window, \
		game->player.player_idle_down_1, 0 + width * 32, 0 + (height * 32));
	else if (game->current_frame == 2 || game->current_frame == 3)
		mlx_put_image_to_window(game->mlx, game->window, \
		game->player.player_idle_down_2, 0 + width * 32, 0 + (height * 32));
}
