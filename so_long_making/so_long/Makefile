SRC = 	get_next_line_utils.c \
		get_next_line.c       \
		so_long.c			  \
		so_long_tools.c 	  

HEADER = so_long.h

NAME = so_long
		
CFLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	${CC} $(CFLAGS) $(OBJ) -o ${NAME}

clean: 
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all