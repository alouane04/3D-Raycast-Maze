SRC = main.c  parsing_stock.c parsing_utils.c check_map.c check_color_texture.c

NAME = cub3D

CC = cc

FLAGS = -Wall -Wextra -Werror -Imlx -fsanitize=address

OBJ = $(SRC:.c=.o)

$(NAME): cub3D.h  $(OBJ) libft/libft.a
	$(CC) $(FLAGS) -o $(NAME) $(SRC) libft/libft.a -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

%.o : %.c
	${CC} ${FLAGS} -c $<

libft/libft.a:
	make -C Libft all

all: $(NAME)

clean:
	make -C libft fclean
	rm -rf $(OBJ)

fclean:
	make -C libft fclean
	rm -rf $(NAME) $(OBJ)

re: fclean all
