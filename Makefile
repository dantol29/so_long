NAME = so_long
BONUS_NAME = so_long_bonus
CFLAGS = -Wextra -Wall 
SRC = src/main.c src/map.c src/open_images.c src/controllers.c \
		src/extra.c src/check_map.c src/free_game.c src/flood_fill.c src/ft_itoa.c src/put_player.c
BONUS_SRC = bonus/main_bonus.c bonus/map_bonus.c bonus/open_images_bonus.c bonus/controllers_bonus.c bonus/extra_bonus.c \
		bonus/check_map_bonus.c bonus/animation_bonus.c bonus/zombie_bonus.c bonus/free_game_bonus.c \
		bonus/flood_fill_bonus.c bonus/score_bonus.c bonus/zombie_move.c
GETNEXTLINE := get_next_line/*c
OBJS = $(SRC:.c=.o)
BONUS_OBJS = $(BONUS_SRC:.c=.o)
MLX_LIB = mlx/
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11


all: $(NAME)

$(NAME): $(OBJS)
	@if [ ! -d "mlx" ]; then \
	git clone https://github.com/42Paris/minilibx-linux.git mlx; \
	fi
	@make -C $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(GETNEXTLINE) $(MLX_FLAGS) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	@if [ ! -d "mlx" ]; then \
	git clone https://github.com/42Paris/minilibx-linux.git mlx; \
	fi
	@make -C $(MLX_LIB)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(GETNEXTLINE) $(MLX_FLAGS) -o $(BONUS_NAME)

clean:
	rm -rf $(OBJS)
	rm -rf $(BONUS_OBJS)

fclean: clean
	@if [ -d "mlx" ]; then \
	make clean -C mlx/; \
	fi
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re
