# Имя финального исполняемого файла
NAME        = so_long

# Компилятор и флаги (добавлен -g для отладки через gdb/valgrind)
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g

# Пути к библиотеке MiniLibX
MLX_DIR     = minilibx-linux
MLX_A       = $(MLX_DIR)/libmlx.a

# Флаги линковки для Linux (библиотеки X11 и математическая библиотека -lm)
# -L указывает путь к библиотеке, -l подключает саму либу
LFLAGS      = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# Список ваших исходных файлов (добавьте сюда ваши файлы парсинга и gnl)
SRCS        = main.c \
              parsing.c \
              utils.c

# Преобразование .c файлов в объектные .o файлы
OBJS        = $(SRCS:.c=.o)

# Основная цель
all: $(NAME)

# Сборка исполняемого файла
$(NAME): $(OBJS) $(MLX_A)
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(NAME)
	@echo "\033[32m[Success] so_long собран для Linux!\033[0m"

# Автоматический запуск сборки MiniLibX, если файла libmlx.a еще нет
$(MLX_A):
	@echo "\033[33m[Compiling] Сборка MiniLibX...\033[0m"
	@make -C $(MLX_DIR)

# Компиляция каждого отдельного файла .c в .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Очистка объектных файлов (ваших и MiniLibX)
clean:
	rm -f $(OBJS)
	@make -C $(MLX_DIR) clean
	@echo "\033[34m[Clean] Объектные файлы удалены.\033[0m"

# Полная очистка (удаление исполняемого файла)
fclean: clean
	rm -f $(NAME)
	@echo "\033[31m[Fclean] Исполняемый файл удален.\033[0m"

# Пересборка проекта с нуля
re: fclean all

# Защита от совпадения имен файлов с целями
.PHONY: all clean fclean re







NAME        = so_long

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g

# Пути к модулям и библиотекам
INC_DIR     = include
SRC_DIR     = src
MLX_DIR     = minilibx-linux
LIBFT_DIR   = libft
GNL_DIR     = get_next_line

# Флаги поиска заголовочных файлов (-I)
IFLAGS      = -I$(INC_DIR) -I$(MLX_DIR) -I$(LIBFT_DIR) -I$(GNL_DIR)

# Библиотеки для линковки (Порядок важен!)
# Сначала ваши библиотеки, затем графические системные библиотеки Linux
LFLAGS      = -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# Список исходных файлов (Логика игры + GNL)
SRCS        = $(SRC_DIR)/main.c \
              $(SRC_DIR)/parsing.c \
              $(SRC_DIR)/flood_fill.c \
              $(SRC_DIR)/render.c \
              $(SRC_DIR)/move.c \
              $(GNL_DIR)/get_next_line.c \
              $(GNL_DIR)/get_next_line_utils.c

OBJS        = $(SRCS:.c=.o)

# Указание статических библиотек для отслеживания зависимостей
LIBFT_A     = $(LIBFT_DIR)/libft.a
MLX_A       = $(MLX_DIR)/libmlx.a

all: $(NAME)

# Сборка основной программы
$(NAME): $(LIBFT_A) $(MLX_A) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(NAME)
	@echo "\033[32m[Success] so_long собран с libft и GNL!\033[0m"

# Автоматический вызов Makefile внутри папки libft
$(LIBFT_A):
	@echo "\033[33m[Compiling] Сборка Libft...\033[0m"
	@make -C $(LIBFT_DIR)

# Автоматический вызов Makefile внутри папки MiniLibX
$(MLX_A):
	@echo "\033[33m[Compiling] Сборка MiniLibX...\033[0m"
	@make -C $(MLX_DIR) > /dev/null 2>&1

# Правило компиляции каждого отдельного .c файла в .o
%.o: %.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean > /dev/null
	@echo "\033[34m[Clean] Объектные файлы удалены.\033[0m"

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "\033[31m[Fclean] Библиотеки и исполняемый файл удалены.\033[0m"

re: fclean all

.PHONY: all clean fclean re
