NAME = fractol
CC = cc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
SRCS = $(wildcard *.c) $(wildcard mlx/*.c)
OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o : %.cc fractol.h 
	$(CC) $(FLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : clean