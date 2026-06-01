NAME        = test_runner

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

# Пути к ресурсам проекта (выходим на уровень выше через ..)
PROJECT_DIR = ..
LIBFT_DIR   = $(PROJECT_DIR)/libft
LIBFT       = $(LIBFT_DIR)/libft.a

# Файлы проекта, необходимые для работы тестов (без главного main() проекта!)
# Добавляем сюда все новые файлы, где лежат функции для обработки кавычек
SRC_FILES   = $(PROJECT_DIR)/src/utils.c \
              $(PROJECT_DIR)/src/utils_bonus.c \
              

# Файлы самих тестов
TEST_SRCS   = test.c
TEST_OBJS   = $(TEST_SRCS:.c=.o)

# Флаги для поиска заголовочных файлов (корневая папка и libft)
INCLUDES    = -I$(PROJECT_DIR) -I$(LIBFT_DIR)

all: $(NAME)
	@./$(NAME)

# Сборка тестового исполняемого файла
$(NAME): $(TEST_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(TEST_OBJS) $(SRC_FILES) $(LIBFT) $(INCLUDES) -o $(NAME)

# Компиляция объектных файлов тестов
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Принудительная сборка Libft
$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	rm -f $(TEST_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
