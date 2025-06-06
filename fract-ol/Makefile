# NAME = fractol
# CC = cc
# RM = rm -f
# FLAGS = -Wall -Wextra -Werror
# # MLX_PATH = /usr/local/include
# MLX_PATH = /mnt/c/c/mlx/include
# # LIBS = -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit
# LIBS = -L$(MLX_PATH) -lmlx -lXext -lX11 -lm -lz
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

# MLX_PATH = /mnt/c/c/mlx
# MLX_INCLUDE = -I$(MLX_PATH)/include
# MLX_LIB = -L$(MLX_PATH) -lmlx -lXext -lX11 -lm -lz

# gcc $(MLX_INCLUDE) votre_fichier.c $(MLX_LIB)


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