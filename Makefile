NAME = philosophers
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = actions.c main.c philosophers.c time.c initialize.c threads.c mutex.c
LIBFT = ./printf/libft/libft.a
OBJS = $(SRCS:.c=.o)
LIBFT_DIR = ./printf/libft/

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o philosophers

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all re fclean clean