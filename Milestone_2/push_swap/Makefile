NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = 	operations/push.c \
		operations/reverse_rotate.c \
        operations/rotate.c \
        operations/swap.c \
		src/validate_and_convert.c \
		src/utils.c \
		src/ft_split.c \
		src/check_error.c \
		src/simple_sort.c \
		src/k_sort.c \
		src/main.c


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all