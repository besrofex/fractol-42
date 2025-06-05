# NAME = fractol
# CC = cc
# RM = rm -f
# FLAGS = -Wall -Wextra -Werror
# MLX_PATH = /usr/local/include
# LIBS = -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit
# SRCS = $(wildcard *.c)
# OBJ = $(SRCS:.c=.o)

# all : $(NAME) 

# $(NAME) : $(OBJ)
# 	$(CC) $(OBJ) -o $(NAME) $(LIBS)

# %.o : %.cc fractol.h 
# 	$(CC) $(FLAGS) -I$(MLX_PATH) -c $< -o $@

# clean :
# 	$(RM) $(OBJ)

# fclean : clean
# 	$(RM) $(NAME)

# re : fclean all

# .PHONY : clean


NAME = fractol.exe
CC = gcc
RM = del /Q
FLAGS = -Wall -Wextra -Werror
MLX_PATH = C:\MinGW\include\mlx
LIBS = -LC:\MinGW\lib -lmlx -lopengl32 -lgdi32 -luser32
SRCS = $(wildcard *.c)
OBJ = $(SRCS:.c=.obj)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LIBS)

%.obj: %.c fractol.h
	$(CC) $(FLAGS) -I$(MLX_PATH) -c $< -o $@

clean:
	$(RM) $(OBJ) 2>nul || true

fclean: clean
	$(RM) $(NAME) 2>nul || true

re: fclean all

.PHONY: clean fclean re all