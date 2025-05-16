NAME    := program
CC      := cc
CFLAGS  := -Wall -Wextra -Werror
INCS    := -Ilibft -Iincludes

SRC     := minishell/minishell.c splitters/token.c splitters/lexer.c
OBJ     := $(SRC:.c=.o)

LIBFT_DIR   := libs/libft
LIBFT_A     := $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(LIBFT_A) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_A) -lreadline -o $@

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
