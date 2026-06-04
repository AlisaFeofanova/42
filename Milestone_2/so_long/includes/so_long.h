#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>

#include <X11/X.h>        // Содержит макросы для событий (например, DestroyNotify)
#include <X11/keysym.h>   // Содержит кроссплатформенные коды клавиш (XK_Escape)

/* Системные графические библиотеки Linux */
# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

/* Стандартные системные библиотеки C */
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

/* Подключение ВАШИХ готовых проектов */
# include "libft.h"        // Доступны функции ft_printf, ft_strlen, ft_putstr_fd и др.
# include "get_next_line.h" // Доступна функция get_next_line



# include "../minilibx_opengl_20191021/mlx.h" 
#include "../libft/libft.h"

/* Размеры одной текстуры (например, 32x32 или 64x64 пикселей) */
# define TILE_SIZE 64

/* Коды клавиш для Linux (для Mac замените на 13, 0, 1, 2, 53) */
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307

typedef struct s_data
{
    void    *mlx;        // Указатель на MiniLibX
    void    *win;        // Указатель на окно
    int      win_width;  // Ширина окна (в пикселях)
    int      win_height; // Высота окна (в пикселях)
}   t_data;



#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

/* Размеры одного графического спрайта (плитки) в пикселях */
# define TILE_SIZE 64

/* --- СТРУКТУРЫ ДАННЫХ --- */

/* Структура для хранения координат (используется для игрока и проверок) */
typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

/* Структура для текстур/изображений */
typedef struct s_img
{
	void	*ptr;
	int		width;
	int		height;
}	t_img;

/* Главная структура игры, объединяющая все модули */
typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	char	**map_copy; /* Нужна исключительно для алгоритма Flood Fill */
	int		map_width;  /* Ширина карты в количестве клеток */
	int		map_height; /* Высота карты в количестве строк */
	
	/* Счетчики элементов на карте */
	int		count_p;
	int		count_c;
	int		count_e;
	int		collected;  /* Сколько предметов игрок уже подобрал */
	int		moves;      /* Счетчик сделанных шагов */
	
	t_point	player;     /* Текущая позиция игрока (x, y) */
	
	/* Текстуры игры */
	t_img	wall;
	t_img	floor;
	t_img	player_img;
	t_img	collect;
	t_img	exit_img;
}	t_game;

/* --- ПРОТОТИПЫ ФУНКЦИЙ --- */

/* Инициализация и управление окном (main.c / window.c) */
int		close_window(t_game *game);
int		handle_keypress(int keycode, t_game *game);
void	init_game_struct(t_game *game);

/* Парсинг и валидация карты (parsing.c / map.c) */
int		read_map(t_game *game, char *filepath);
int		validate_map(t_game *game);
void	free_map(char **map);

/* Проверка проходимости (flood_fill.c) */
int		check_path(t_game *game);

/* Графика и отрисовка (render.c) */
void	init_textures(t_game *game);
int		render_map(t_game *game);

/* Логика движения (move.c) */
void	move_player(t_game *game, int dx, int dy);

/* Утилиты (utils.c) */
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*get_next_line(int fd); /* Ваша функция GNL */

#endif






#endif
