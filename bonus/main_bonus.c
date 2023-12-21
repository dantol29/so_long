/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:31:16 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/12/09 16:04:11 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

void	draw_frame(t_game *game)
{
	int	i;
	int	j;

	game->current_frame = (game->current_frame + 1) % 4;
	put_player(game, game->x, game->y);
	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'Z')
				zombie_animation(game, j, i);
			j++;
		}
		i++;
	}
	score(game);
	usleep(270000);
}

int	on_destroy(t_game *game)
{
	free_map(game);
	free_player(game);
	free_textures(game);
	free_zombies(game);
	free_digits(game);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}

void	update_player_position(t_game *game, int key)
{
	int		i;
	int		j;

	i = 0;
	srand(time(NULL));
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][++j])
			if (game->map[i][j] == 'Z')
				zombie_move(game, j, i);
		i++;
	}
	i = game->x;
	j = game->y;
	if (key == 115 && game->map[j + 1][i] != '1')
		move_top(game, i, j);
	else if (key == 119 && game->map[j - 1][i] != '1')
		move_down(game, i, j);
	else if (key == 97 && game->map[j][i - 1] != '1')
		move_left(game, i, j);
	else if (key == 100 && game->map[j][i + 1] != '1')
		move_right(game, i, j);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 119 || keycode == 115 \
	|| keycode == 100 || keycode == 97)
		update_player_position(game, keycode);
	else if (keycode == 65307)
		on_destroy(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		if (save_map(argv[1], &game) == 1)
			exit(EXIT_FAILURE);
		game.mlx = mlx_init();
		game.window = mlx_new_window(game.mlx, (game.map_cols - 1) * 32, \
		(game.map_rows + 2) * 32, "so_long");
		open_images(&game);
		add_graphics(&game);
		mlx_key_hook(game.window, key_hook, &game);
		mlx_hook(game.window, 17, 0, on_destroy, &game);
		mlx_loop_hook(game.mlx, (void (*)(t_game *))draw_frame, &game);
		mlx_loop(game.mlx);
	}
	else
		write(1, "Error\nProgramm accepts no more or less than 1 argument\n", 55);
	exit(EXIT_SUCCESS);
}
