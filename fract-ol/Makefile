NAME = fractol
MLX = libmlx.dylib
CC = cc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
SRCS = $(wildcard *.c)
OBJ = $(SRCS:.c=.o)

all : $(MLX) $(NAME) 

$(MLX) :
	@make -C mlx/

$(NAME) : $(OBJ)
	$(CC) $(OBJ) mlx/libmlx.dylib -o $(NAME)

%.o : %.cc fractol.h /mlx/mlx.h
	$(CC) $(FLAGS) -c $< -o $@

clean :
	@make clean -C mlx/
	$(RM) $(OBJ)

fclean : clean
	@make fclean -C mlx/
	$(RM) $(NAME)

re : fclean all

.PHONY : clean