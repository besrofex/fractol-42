NAME = fractol
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror
CC = cc
MLX = -lmlx -framework OpenGL -framework AppKit

all:$(NAME)

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $(MLX) $(OBJS)  -o $(NAME)

%.o: %.c fractol.h
	$(CC) $(CFLAGS) -Imlx -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:fclean all