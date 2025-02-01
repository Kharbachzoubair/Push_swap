CC=gcc
CFLAGS=-Wall -Wextra -Werror
SRC= main.c split.c validation.c utils.c 
OBJ=$(SRC:.c=.o)
NAME= push_swap

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
clean :
	rm -f $(OBJ)
fclean :
	rm -f $(NAME)
re: fclean all