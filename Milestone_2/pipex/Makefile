NAME        = pipex

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

INC         = includes/pipex.h
SRC_DIR     = src/
LIBFT_DIR   = libft/
LIBFT       = $(LIBFT_DIR)libft.a

SRCS_FILES  = pipex.c utils.c check_and_free.c
SRCS        = $(addprefix $(SRC_DIR), $(SRCS_FILES))
OBJS        = $(SRCS:.c=.o)

INCLUDES    = -Iincludes -I$(LIBFT_DIR)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(SRC_DIR)%.o: $(SRC_DIR)%.c $(INC)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

test: all
	@make -C ./tests

.PHONY: all clean fclean re test
