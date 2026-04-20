NAME = so_long.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

SRC = ...

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all