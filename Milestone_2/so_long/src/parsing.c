#include "../includes/so_long.h"

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}



static int	count_lines(char *filepath)
{
	int		fd;
	int		lines;
	char	*line;

	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		return (-1);
	lines = 0;
	line = get_next_line(fd);
	while (line)
	{
		lines++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (lines);
}

int	read_map(t_game *game, char *filepath)
{
	int		fd;
	int		i;

	game->map_height = count_lines(filepath);
	if (game->map_height <= 0)
		return (0);
	game->map = malloc(sizeof(char *) * (game->map_height + 1));
	if (!game->map)
		return (0);
	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		return (free(game->map), game->map = NULL, 0);
	i = 0;
	while (i < game->map_height)
	{
		game->map[i] = get_next_line(fd);
		// Удаляем символ \n в конце строки, если он есть, для удобства валидации
		if (game->map[i] && game->map[i][ft_strlen(game->map[i]) - 1] == '\n')
			game->map[i][ft_strlen(game->map[i]) - 1] = '\0';
		i++;
	}
	game->map[i] = NULL;
	close(fd);
	game->map_width = ft_strlen(game->map[0]);
	return (1);
}

static int	check_walls_and_geometry(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		if ((int)ft_strlen(game->map[i]) != game->map_width)
			return (0); // Карта не прямоугольная
		j = 0;
		while (game->map[i][j])
		{
			// Проверка верхней и нижней строк
			if ((i == 0 || i == game->map_height - 1) && game->map[i][j] != '1')
				return (0);
			// Проверка левого и правого краев
			if ((j == 0 || j == game->map_width - 1) && game->map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	count_elements(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'P')
			{
				game->count_p++;
				game->player.x = j; // Запоминаем стартовую позицию
				game->player.y = i;
			}
			else if (game->map[i][j] == 'E')
				game->count_e++;
			else if (game->map[i][j] == 'C')
				game->count_c++;
			else if (game->map[i][j] != '0' && game->map[i][j] != '1')
				return (0); // Посторонний символ
		}
	}
	return (game->count_p == 1 && game->count_e == 1 && game->count_c >= 1);
}

int	validate_map(t_game *game)
{
	game->count_p = 0;
	game->count_e = 0;
	game->count_c = 0;
	
	if (!check_walls_and_geometry(game))
	{
		ft_putstr_fd("Error\nInvalid walls or map geometry\n", 2);
		return (0);
	}
	if (!count_elements(game))
	{
		ft_putstr_fd("Error\nInvalid characters or wrong count of P, E, C\n", 2);
		return (0);
	}
	return (1);
}

int validate_map(t_game *game)
{
    if (!check_rectangle(game))
    {
        ft_putstr_fd("Error\nMap is not a rectangle.\n", 2);
        return (0);
    }
    if (!check_walls(game))
    {
        ft_putstr_fd("Error\nMap is not surrounded by walls.\n", 2);
        return (0);
    }
    if (!check_elements(game)) // Считает P, E, C и проверяет символы
    {
        ft_putstr_fd("Error\nInvalid map elements or counts.\n", 2);
        return (0);
    }
    return (1);
}
