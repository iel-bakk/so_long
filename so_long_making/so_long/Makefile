SRC = 	get_next_line_utils.c \
		get_next_line.c       \
		so_long.c			  \
		so_long_tools.c 	  \
		so_long_file.c		  \
		so_long_file_one.c    \
		so_long_file_three.c  \
		so_long_file_two.c    \
		start_game.c

HEADER = so_long.h

NAME = so_long

CFLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(OBJ)  $(CFLAGS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all