# so_long
The "so_long" project at 42 is a 2D game developed in C using the MinilibX graphical library, involving tile-based map rendering, player movement, and collision detection, where the engine handles real-time graphics, event handling, and resource management to create a visually engaging and interactive gaming experience.
![Screenshot](game.jpg)

## How to play
1. git clone the project
2. make bonus (or just make for the boring version)
3. ./so_long_bonus maps/map.ber

## Tutorial
### 1. Install minilibx library:
```
git clone https://github.com/42Paris/minilibx-linux.git
```
### 2. Create a Makefile
```
NAME = so_long
CFLAGS = -Wextra -Wall -Werror
SRC = your c code 
GETNEXTLINE := get_next_line/*c
OBJS = $(SRC:.c=.o)
MLX_LIB = mlx/
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

all: $(NAME)

$(NAME): $(OBJS)
	@if [ ! -d "mlx" ]; then \
	git clone https://github.com/42Paris/minilibx-linux.git mlx; \
	fi
	@make -C $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(GETNEXTLINE) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -rf $(OBJS)
	rm -rf $(BONUS_OBJS)

fclean: clean
	@if [ -d "mlx" ]; then \
	make clean -C mlx/; \
	fi
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
```
### 3. Make a struct to store info about the game
```
typedef s_game
{
void *mlx;
void *window;
} t_game
```
### 4. Initialize the game and open the window
```
game->mlx = mlx_init();
game->window = mlx_new_window(game->mlx, WIDTH, HEIGHT, "Your Game Title");
mlx_loop(game->mlx);
```
### 5. ESC and close button

It is done using mlx_destroy_window();
```
// function that you want to call evety time you exit the game
int	on_destroy(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 65307)
		on_destroy(game);
	return (0);
}
mlx_key_hook(game.window, key_hook, &game); //every time a key is pressed key_hook is called
mlx_hook(game.window, 17, 0, on_destroy, &game); //if close button is pressed on_destroy is called
```
### 6. Open images
   
It is done using mlx_xpm_file_to_image();
```
void  open_ground_coins_door(t_game *game)
{
	game->textures.ground = mlx_xpm_file_to_image(game->mlx, \
	"assets/dirt.xpm", &game->width, &game->height);
	game->textures.coin = mlx_xpm_file_to_image(game->mlx, \
	"assets/coin.xpm", &game->width, &game->height);
	game->textures.door = mlx_xpm_file_to_image(game->mlx, \
	"assets/door.xpm", &game->width, &game->height);
	game->textures.wall = mlx_xpm_file_to_image(game->mlx, \
	"assets/wall.xpm", &game->width, &game->height);
}
```
### 7. Where to find and convert image

Use itch.io to find free sprites, assets and convertio.co to convert sprites into .xpm format
![Screenshot](newcharleft1.png) ![Screenshot](zombiefront1.png)
### 8. Free images

To prevent memory leaks you have to free images right before the game is closed
```
void	free_textures(t_game *game)
{
	mlx_destroy_image(game->mlx, game->textures.coin);
	mlx_destroy_image(game->mlx, game->textures.door);
	mlx_destroy_image(game->mlx, game->textures.ground);
	mlx_destroy_image(game->mlx, game->textures.wall);
}
```
### 9. Read and store map

Make a 2d array and fill it
```
void	fill_map(t_game *game, int lines, char *map)
{
	int	file;
	int	i;

	i = 0;
	file = open(map, O_RDWR); // open file
	game->map = malloc(sizeof(char *) * (lines + 1)); // allocate memory to store the map
	game->map[0] = get_next_line(file); // fill each element of the array line by line
	while (i < lines)
	{
		i++;
		game->map[i] = get_next_line(file);
	}
	close(file); // close file
}
```
12. Map rules
13. Error handling
14. Flood fill to find a valid path
15. Player movement
16. Coins and exit
17. Idle animation
18. Rendering
19. Moves counter in the console
20. Moves counter on the screen
21. Makefile adjustment
22. ESC and close button
23. Enemies
24. Enemies movement
25. Go through the exit
