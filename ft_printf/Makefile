NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

SRC = ft_printf.c \
		ft_putchar.c \
		ft_puthex.c \
		ft_putnbr.c \
		ft_putstr.c \
		ft_putunbr.c \
		ft_putptr.c \
		ft_strlen.c 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all