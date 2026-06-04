#include "so_long.h"

// Вспомогательная функция для вывода количества шагов в терминал
static void	print_moves(t_game *game)
{
	game->moves++;
	ft_putstr_fd("Moves: ", 1);
	ft_putnbr_fd(game->moves, 1);
	ft_putstr_fd("\n", 1);
}

void	move_player(t_game *game, int dx, int dy)
{
	int	next_x;
	int	next_y;

	// Рассчитываем координаты клетки, в которую хочет наступить игрок
	next_x = game->player.x + dx;
	next_y = game->player.y + dy;

	// Если впереди стена, движение невозможно — просто выходим
	if (game->map[next_y][next_x] == '1')
		return ;

	// Если наступили на коллекционный предмет
	if (game->map[next_y][next_x] == 'C')
		game->collected++;

	// Если наступили на выход
	if (game->map[next_y][next_x] == 'E')
	{
		// Игра завершается, только если собраны ВСЕ предметы
		if (game->collected == game->count_c)
		{
			print_moves(game);
			ft_putstr_fd("Congratulations! You won!\n", 1);
			close_window(game);
		}
		// Если собрано не всё, выход работает как стена или сквозь него нельзя пройти
		return ; 
	}

	// Обновляем массив карты: на старом месте теперь пусто, на новом — игрок
	game->map[game->player.y][game->player.x] = '0';
	game->map[next_y][next_x] = 'P';

	// Обновляем координаты игрока в структуре
	game->player.x = next_x;
	game->player.y = next_y;

	// Увеличиваем и выводим счетчик шагов
	print_moves(game);

	// Перерисовываем карту с изменениями в окне
	render_map(game);
}
