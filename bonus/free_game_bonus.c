/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:01:27 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/12/08 18:29:33 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

void	free_visited(int **visited, t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_rows)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i] != NULL)
	{
		free (game->map[i]);
		i++;
	}
	free(game->map);
}

void	free_player(t_game *game)
{
	mlx_destroy_image(game->mlx, game->player.player_idle_right_1);
	mlx_destroy_image(game->mlx, game->player.player_idle_right_2);
	mlx_destroy_image(game->mlx, game->player.player_idle_left_1);
	mlx_destroy_image(game->mlx, game->player.player_idle_left_2);
	mlx_destroy_image(game->mlx, game->player.player_idle_top_1);
	mlx_destroy_image(game->mlx, game->player.player_idle_top_2);
	mlx_destroy_image(game->mlx, game->player.player_idle_down_1);
	mlx_destroy_image(game->mlx, game->player.player_idle_down_2);
}

void	free_textures(t_game *game)
{
	mlx_destroy_image(game->mlx, game->textures.coin);
	mlx_destroy_image(game->mlx, game->textures.door);
	mlx_destroy_image(game->mlx, game->textures.ground);
	mlx_destroy_image(game->mlx, game->textures.wall);
}

void	free_zombies(t_game *game)
{
	mlx_destroy_image(game->mlx, game->zombie_idle_front_1);
	mlx_destroy_image(game->mlx, game->zombie_idle_front_2);
	mlx_destroy_image(game->mlx, game->zombie_idle_front_3);
	mlx_destroy_image(game->mlx, game->zombie_idle_front_4);
}
