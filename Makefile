NAME=fractol
CC=cc
C_FLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -Lmlx -lmlx_Linux -lX11 -lXext 
C_FILES = main.c \
			fractol.c
C_OBJ = $(C_FILES:.c=.o)

$(NAME): $(C_OBJ)
	$(CC) $(C_FLAGS) $(C_FILES) $(MLX_FLAGS) -o $(NAME)
all: $(NAME)

clean:
	${RM} ${C_OBJ}

fclean: clean
	$(RM) $(NAME)

re: clean all