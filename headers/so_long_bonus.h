/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtolmaco <dtolmaco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:43:12 by dtolmaco          #+#    #+#             */
/*   Updated: 2023/12/09 15:28:26 by dtolmaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# define WIDTH 32
# define HEIGHT 32
# define RIGHT 0
# define LEFT 1
# define UP 2
# define DOWN 3

# include "mlx.h"
# include "../get_next_line/get_next_line.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdint.h>
# include <time.h>

typedef struct s_player
{
	void	*player_idle_right_1;
	void	*player_idle_right_2;
	void	*player_idle_left_1;
	void	*player_idle_left_2;
	void	*player_idle_down_1;
	void	*player_idle_down_2;
	void	*player_idle_top_1;
	void	*player_idle_top_2;
}	t_player;

typedef struct s_textures
{
	void	*ground;
	void	*coin;
	void	*door;
	void	*wall;
}	t_textures;

typedef struct s_digits
{
	void	*zero;
	void	*one;
	void	*two;
	void	*three;
	void	*four;
	void	*five;
	void	*six;
	void	*seven;
	void	*eight;
	void	*nine;
}	t_digits;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	int			score;
	int			coins;
	int			moves;
	int			width;
	int			height;
	int			x;
	int			y;
	int			map_rows;
	int			map_cols;
	int			exit_row;
	int			exit_col;
	int			flood_fill_coins;
	int			current_frame;
	int			player_position;
	char		**map;
	void		*zombie_idle_front_1;
	void		*zombie_idle_front_2;
	void		*zombie_idle_front_3;
	void		*zombie_idle_front_4;
	t_digits	digits;
	t_textures	textures;
	t_player	player;
}	t_game;

// additional functions
char	*ft_itoa(int n);
int		on_destroy(t_game *game);

// graphics
int		save_map(char *map, t_game *game);
void	open_images(t_game *game);
void	add_graphics(t_game *game);
void	put_player(t_game *game, int width, int height);
void	put_coin(t_game *game, int width, int height);
void	add_zombie(t_game *game);
void	score(t_game *game);
void	open_score(t_game *game);
void	door_locked_up_down(t_game *game, int door_row, int door_col);

// animation
void	left_animation(t_game *game, int width, int height);
void	right_animation(t_game *game, int width, int height);
void	down_animation(t_game *game, int width, int height);
void	top_animation(t_game *game, int width, int height);
void	zombie_animation(t_game *game, int width, int height);
void	zombie_move(t_game *game, int width, int height);

// player controls
void	move_top(t_game *game, int i, int j);
void	move_down(t_game *game, int i, int j);
void	move_right(t_game *game, int i, int j);
void	move_left(t_game *game, int i, int j);

// free memory
void	free_map(t_game *game);
void	free_player(t_game *game);
void	free_textures(t_game *game);
void	free_zombies(t_game *game);
void	free_visited(int **visited, t_game *game);
void	free_digits(t_game *game);

// check map
int		check_playable(t_game *game);
int		check_filename(char *file);
int		check_map(char *map, t_game *game);
int		valid_path(t_game *game);
int		check_char(t_game *game, int *p, int *e, int i);
int		check_last_row_rectan(t_game *game);
void	check_playable_row(t_game *game, int *c, int *p, int *e);

#endif