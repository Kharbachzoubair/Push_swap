CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c ft_split.c validation.c utils.c stack.c operations.c sorting.c algo.c
OBJ = $(SRC:.c=.o)
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
