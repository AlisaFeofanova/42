#include "../includes/so_long.h"

i// Функция закрытия программы (чистит память и выходит)
int close_window(t_data *data)
{
    // Важно: в будущем здесь также нужно будет уничтожать текстуры (mlx_destroy_image)
    if (data->win)
        mlx_destroy_window(data->mlx, data->win);
    // На некоторых платформах mlx_destroy_display(data->mlx); free(data->mlx);
    exit(0);
    return (0);
}

int close_window(t_data *data)
{
    // 1. Сначала уничтожаем все созданные картинки/текстуры (когда они появятся)
    // if (data->img_ptr) mlx_destroy_image(data->mlx, data->img_ptr);

    // 2. Затем закрываем само окно графического интерфейса
    if (data->win)
        mlx_destroy_window(data->mlx, data->win);

    // 3. Освобождаем соединение с дисплеем X-сервера Linux
    if (data->mlx)
    {
        mlx_destroy_display(data->mlx);
        free(data->mlx);
    }

    // 4. Завершаем процесс
    exit(0);
    return (0);
}

// Функция обработки нажатия клавиш
int handle_keypress(int keycode, t_data *data)
{
    // 53 — код клавиши ESC на macOS (на Linux это может быть 65307 или XK_Escape)
    if (keycode == 53) 
        close_window(data);
    return (0);
}

int handle_keypress(int keycode, t_data *data)
{
    if (keycode == XK_Escape)
    {
        close_window(data);
    }
    else if (keycode == XK_w || keycode == XK_W || keycode == XK_Up)
    {
        printf("Движение ВВЕРХ\n"); // Здесь будет логика шага
    }
    else if (keycode == XK_s || keycode == XK_S || keycode == XK_Down)
    {
        printf("Движение ВНИЗ\n");
    }
    else if (keycode == XK_a || keycode == XK_A || keycode == XK_Left)
    {
        printf("Движение ВЛЕВО\n");
    }
    else if (keycode == XK_d || keycode == XK_D || keycode == XK_Right)
    {
        printf("Движение ВПРАВО\n");
    }
    return (0);
}

// 1. Обработчик нажатия клавиш (KeyPress)
int handle_keypress(int keycode, t_data *data)
{
    if (keycode == XK_Escape)
        close_window(data);
    
    // Пример логики: меняем координаты в структуре данных игры
    if (keycode == XK_w || keycode == XK_Up)
        move_player(data, 0, -1); // шаг вверх
        
    return (0);
}

// 2. Обработчик перерисовки окна (Expose)
int handle_expose(t_data *data)
{
    // Эта функция вызывается, когда окно свернули/развернули
    // Здесь нужно заново вызвать отрисовку карты, чтобы экран не стал черным
    render_map(data);
    return (0);
}


void	init_game_struct(t_game *game)
{
	// Зануляем основные системные указатели MiniLibX
	game->mlx = NULL;
	game->win = NULL;

	// Зануляем указатели на массивы карты
	game->map = NULL;
	game->map_copy = NULL;

	// Инициализируем размеры карты
	game->map_width = 0;
	game->map_height = 0;

	// Сбрасываем счетчики элементов на карте для будущей валидации
	game->count_p = 0;
	game->count_c = 0;
	game->count_e = 0;

	// Сбрасываем игровые показатели
	game->collected = 0;
	game->moves = 0;

	// Начальные координаты игрока ставим в заведомо некорректные
	game->player.x = -1;
	game->player.y = -1;

	// Строго зануляем указатели на графические текстуры
	// Это спасет от краша, если mlx_destroy_image вызовется до загрузки картинок
	game->wall.ptr = NULL;
	game->floor.ptr = NULL;
	game->player_img.ptr = NULL;
	game->collect.ptr = NULL;
	game->exit_img.ptr = NULL;
}

int main(void)
{
    t_data  data;

    data.win_width = 800;
    data.win_height = 600;

    // 1. Инициализация самой библиотеки MLX
    data.mlx = mlx_init();
    if (!data.mlx)
        return (1);

    // 2. Создание окна
    data.win = mlx_new_window(data.mlx, data.win_width, data.win_height, "so_long");
    if (!data.win)
        return (1); // В идеале тут нужно освободить data.mlx перед выходом



// // Шаблон вызова:
// // mlx_hook(окно, тип_события, маска_события, функция_обработчик, указатель_на_данные);

// mlx_hook(data.win, DestroyNotify, StructureNotifyMask, close_window, &data);




    // 3. Подписка на события (Hooks)
    // Нажатие любой клавиши
    mlx_key_hook(data.win, handle_keypress, &data);
    
    // Нажатие на крестик окна (событие 17 — DestroyNotify)
    mlx_hook(data.win, 17, 0, close_window, &data);

    // 4. Запуск бесконечного цикла ожидания событий
    mlx_loop(data.mlx);

    return (0);
}

// gcc main.c -Lminilibx-linux -lmlx -lXext -lX11 -lm -o so_long


int main(void)
{
    t_data data;
    // ... инициализация mlx и win ...

    // ХУК 1: Нажатие кнопки (Событие 2)
    mlx_hook(data.win, KeyPress, KeyPressMask, handle_keypress, &data);

    // ХУК 2: Нажатие на крестик (Событие 17)
    mlx_hook(data.win, DestroyNotify, StructureNotifyMask, close_window, &data);

    // ХУК 3: Перерисовка окна (Событие 12)
    mlx_hook(data.win, Expose, ExposureMask, handle_expose, &data);

    // Запуск бесконечного цикла обработки ивентов
    mlx_loop(data.mlx);
    return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	// 1. ПЕРВЫМ ДЕЛОМ зануляем структуру
	init_game_struct(&game);

	// 2. Проверяем аргументы командной строки
	if (argc != 2 || !check_extension(argv[1]))
	{
		ft_putstr_fd("Error\nInvalid arguments\n", 2);
		return (1); 
	}

	// 3. Читаем и валидируем карту
	// Если read_map упадет посередине, free_map(game.map) безопасно отработает, 
	// потому что game.map изначально равен NULL
	if (!read_map(&game, argv[1]) || !validate_map(&game))
	{
		close_window(&game); // Безопасно чистит то, что успело выделиться
		return (1);
	}

	// Далее идет Flood Fill и инициализация MLX...
	return (0);
}