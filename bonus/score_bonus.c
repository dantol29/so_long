/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:00:35 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/12/09 12:00:17 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

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

void	put_digit_2(t_game *game, int digit, int i)
{
	if (digit == 6)
		mlx_put_image_to_window(game->mlx, game->window, \
		game->digits.six, 100 - (i * 16), (game->map_rows + 1) * 32);
	else if (digit == 7)
		mlx_put_image_to_window(game->mlx, game->window, \
		game->digits.seven, 100 - (i * 16), (game->map_rows + 1) * 32);
	else if (digit == 8)
		mlx_put_image_to_window(game->mlx, game->window, \
		game->digits.eight, 100 - (i * 16), (game->map_rows + 1) * 32);
	else if (digit == 9)
		mlx_put_image_to_window(game->mlx, game->window, \
		game->digits.nine, 100 - (i * 16), (game->map_rows + 1) * 32);
}

void	put_digit(t_game *game, int digit, int i)
{
	if (digit == 0)
		mlx_put_image_to_window(game->mlx, game->window, \
		game->digits.zero, 100 - (i * 16), (game->map_rows + 1) * 32);
	else if (digit == 1)
		mlx_put_image_to_window(game->mlx, game->window, \
		game->digits.one, 100 - (i * 16), (game->map_rows + 1) * 32);
	else if (digit == 2)
		mlx_put_image_to_window(game->mlx, game->window, \
		game->digits.two, 100 - (i * 16), (game->map_rows + 1) * 32);
	else if (digit == 3)
		mlx_put_image_to_window(game->mlx, game->window, \
		game->digits.three, 100 - (i * 16), (game->map_rows + 1) * 32);
	else if (digit == 4)
		mlx_put_image_to_window(game->mlx, game->window, \
		game->digits.four, 100 - (i * 16), (game->map_rows + 1) * 32);
	else if (digit == 5)
		mlx_put_image_to_window(game->mlx, game->window, \
		game->digits.five, 100 - (i * 16), (game->map_rows + 1) * 32);
}

void	score(t_game *game)
{
	int	i;
	int	digit;
	int	moves;

	mlx_string_put(game->mlx, game->window, 0, \
	(game->map_rows + 2) * 32 -20, 0xFFFFFF, "Moves :");
	i = 0;
	if (game->moves > 9999)
		game->moves = 0;
	moves = game->moves;
	while (i < 4)
	{
		digit = moves % 10;
		moves = moves / 10;
		if (digit > 5)
			put_digit_2(game, digit, i);
		else
			put_digit(game, digit, i);
		i++;
	}
}

void	free_digits(t_game *game)
{
	mlx_destroy_image(game->mlx, game->digits.zero);
	mlx_destroy_image(game->mlx, game->digits.one);
	mlx_destroy_image(game->mlx, game->digits.two);
	mlx_destroy_image(game->mlx, game->digits.three);
	mlx_destroy_image(game->mlx, game->digits.four);
	mlx_destroy_image(game->mlx, game->digits.five);
	mlx_destroy_image(game->mlx, game->digits.six);
	mlx_destroy_image(game->mlx, game->digits.seven);
	mlx_destroy_image(game->mlx, game->digits.eight);
	mlx_destroy_image(game->mlx, game->digits.nine);
}
