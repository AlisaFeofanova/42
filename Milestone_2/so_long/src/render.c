#include "so_long.h"

// Вспомогательная функция для безопасной загрузки одного спрайта
static void	*load_sprite(t_game *game, char *path, t_img *img)
{
	void	*ptr;

	// mlx_xpm_file_to_image конвертирует .xpm файл в понятную для MLX структуру
	ptr = mlx_xpm_file_to_image(game->mlx, path, &img->width, &img->height);
	if (!ptr)
	{
		ft_putstr_fd("Error\nFailed to load texture: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd("\n", 2);
		close_window(game); // Корректно завершаем программу и чистим память
	}
	return (ptr);
}

void	init_textures(t_game *game)
{
	// Загружаем текстуры. Пути к файлам должны соответствовать вашей структуре папок.
	// Размеры картинок (обычно 64x64) запишутся в img.width и img.height автоматически.
	game->wall.ptr = load_sprite(game, "textures/wall.xpm", &game->wall);
	game->floor.ptr = load_sprite(game, "textures/floor.xpm", &game->floor);
	game->player_img.ptr = load_sprite(game, "textures/player.xpm", &game->player_img);
	game->collect.ptr = load_sprite(game, "textures/collect.xpm", &game->collect);
	game->exit_img.ptr = load_sprite(game, "textures/exit.xpm", &game->exit_img);
}


// Функция отрисовки конкретного спрайта в зависимости от символа на карте
static void	put_sprite(t_game *game, char c, int x, int y)
{
	// Каждый шаг мы сначала рисуем пол, чтобы под игроком/предметами не было черного экрана
	mlx_put_image_to_window(game->mlx, game->win, game->floor.ptr, x, y);
	
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall.ptr, x, y);
	else if (c == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->player_img.ptr, x, y);
	else if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->collect.ptr, x, y);
	else if (c == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->exit_img.ptr, x, y);
}

int	render_map(t_game *game)
{
	int	i;
	int	j;

	if (!game->win)
		return (0);
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			// Переводим индексы матрицы в пиксели на экране (например: строка 2 -> y = 128)
			put_sprite(game, game->map[i][j], j * TILE_SIZE, i * TILE_SIZE);
			j++;
		}
		i++;
	}
	return (0);
}
