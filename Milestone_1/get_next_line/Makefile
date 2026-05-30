NAME = getnextline.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

SRC = get_next_line.c \
		get_next_line_utils.c
		
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ) get_next_line.h 

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
