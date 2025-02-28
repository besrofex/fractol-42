NAME = fractol
CC = cc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
MLX_PATH = /usr/local/include
LIBS = -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit
SRCS = $(wildcard *.c)
OBJ = $(SRCS:.c=.o)

all : $(NAME) 

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LIBS)

%.o : %.cc fractol.h 
	$(CC) $(FLAGS) -I$(MLX_PATH) -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : clean