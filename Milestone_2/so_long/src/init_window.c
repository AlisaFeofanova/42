#include "../includes/so_long.h"

/*
** Функция полного закрытия игры. 
** В будущем здесь БУДЕТ вызываться free для вашей карты
** и mlx_destroy_image для всех текстур.
*/
int	close_game(t_game *game)
{
	if (!game)
		exit(0);
	if (game->win && game->mlx)
	{
		mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
	}
	// Если вы использовали mlx_destroy_display (актуально для Linux-версии mlx):
	// mlx_loop_end(game->mlx); 
	// free(game->mlx);
	
	write(1, "Game closed successfully.\n", 26);
	exit(0);
	return (0);
}

/*
** Функция-обработчик нажатия клавиш.
** Сюда MiniLibX автоматически передает код нажатой клавиши (keysym).
*/
int	handle_keypress(int keysym, t_game *game)
{
	if (keysym == KEY_ESC)
		close_game(game);
		
	// Тестовый вывод в консоль, чтобы вы видели коды клавиш при нажатии:
	// printf("Key pressed: %d\n", keysym); 
	
	return (0);
}

/*
** Основная функция инициализации графики.
** Размеры окна рассчитываются динамически: количество клеток * размер текстуры.
*/
void	init_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		write(2, "Error\nFailed to initialize MiniLibX\n", 36);
		exit(1);
	}
	
	// Временные жесткие размеры 800x600 для тестов Шага 2.
	// Позже вы замените это на: game->map_width * TILE_SIZE
	game->win = mlx_new_window(game->mlx, 800, 600, "so_long");
	if (!game->win)
	{
		write(2, "Error\nFailed to create window\n", 30);
		// free(game->mlx); // Зависит от версии MLX
		exit(1);
	}
	
	/* 
	** Регистрация хуков:
	** 1. Нажатие любой клавиши вызывает handle_keypress.
	** 2. Событие 17 (нажатие на крестик окна в X11) вызывает close_game.
	** Передаем &game третьим аргументом, чтобы функции имели доступ ко всем данным.
	*/
	mlx_key_hook(game->win, handle_keypress, game);
	mlx_hook(game->win, 17, 0, close_game, game);
}
