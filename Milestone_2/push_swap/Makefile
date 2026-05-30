NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c stack.c operations.c sort.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all