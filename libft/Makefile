# **************************************************************************** #
#                                   LIBFT                                      #
# **************************************************************************** #

# Имя итоговой библиотеки
NAME = libft.a

# Компилятор и флаги
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Архиватор для создания библиотеки
AR = ar rcs

# Исходники
SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	  ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	  ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	  ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
	  ft_atoi.c ft_calloc.c ft_strdup.c 
# ft_substr.c ft_strjoin.c \
	  ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
	  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c 

# Объектные файлы (.o)
OBJ = $(SRC:.c=.o)

# Правило по умолчанию
all: $(NAME)

# Как собрать библиотеку
$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@echo "✅ libft.a создана!"

# Правило компиляции .c → .o
%.o: %.c libft.h
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiling $<"

# Очистка объектных файлов
clean:
	@rm -f $(OBJ)
	@echo "🧹 Object files cleaned"

# Полная очистка (включая библиотеку)
fclean: clean
	@rm -f $(NAME)
	@echo "🗑  libft.a удалена"

# Пересборка
re: fclean all

# Чтобы make не путал цели с файлами
.PHONY: all clean fclean re
