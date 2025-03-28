CC      = gcc
CFLAGS  = -Wall -Wextra -Werror
SRC     = algo.c find_min_max.c ft_split.c main.c max_index_utils.c move_to_top.c \
          push.c range_utils.c reverse_rotate.c sort_small.c stack_helpers.c \
          stack_utils.c stack.c swap.c utils.c utils1.c validation.c rotate.c
OBJ     = $(SRC:.c=.o)
NAME    = push_swap

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	del /f /q $(OBJ)

fclean: clean
	del /f /q $(NAME)

re: fclean all
