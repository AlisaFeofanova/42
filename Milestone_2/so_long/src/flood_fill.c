#include "so_long.h"

// Создание точной копии карты
static char	**duplicate_map(t_game *game)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (game->map_height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < game->map_height)
	{
		// Выделяем память под каждую строку и копируем содержимое
		copy[i] = malloc(sizeof(char) * (game->map_width + 1));
		if (!copy[i])
		{
			free_map(copy);
			return (NULL);
		}
		// Используем стандартное посимвольное копирование строки
		int j = 0;
		while (game->map[i][j])
		{
			copy[i][j] = game->map[i][j];
			j++;
		}
		copy[i][j] = '\0';
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

// Рекурсивная функция заливки
static void	fill(char **map, int x, int y)
{
	// Условия выхода из рекурсии: вышли за границы, врезались в стену ('1') или уже были тут ('X')
	if (map[y][x] == '1' || map[y][x] == 'X')
		return ;

	// Маркируем текущую клетку как проверенную
	map[y][x] = 'X';

	// Рекурсивно идем в 4 стороны: вверх, вниз, влево, вправо
	fill(map, x, y - 1);
	fill(map, x, y + 1);
	fill(map, x - 1, y);
	fill(map, x + 1, y);
}

// Проверка: остались ли недостижимые элементы
static int	check_unreachable(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			// Если после заливки нашли 'C' или 'E', значит игрок не может до них дойти
			if (map[i][j] == 'C' || map[i][j] == 'E')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

// Главная функция модуля
int	check_path(t_game *game)
{
	game->map_copy = duplicate_map(game);
	if (!game->map_copy)
	{
		ft_putstr_fd("Error\nMemory allocation failed for path check\n", 2);
		return (0);
	}

	// Запускаем заливку со стартовой позиции игрока
	fill(game->map_copy, game->player.x, game->player.y);

	// Проверяем результат
	if (check_unreachable(game->map_copy))
	{
		ft_putstr_fd("Error\nNo valid path found to all items or exit\n", 2);
		free_map(game->map_copy);
		game->map_copy = NULL;
		return (0);
	}

	// Очищаем память копии, так как она больше не нужна
	free_map(game->map_copy);
	game->map_copy = NULL;
	return (1);
}
