SRC = main.c parse/parsing_stock.c parse/parsing_utils.c parse/check_map.c parse/check_color_texture.c bonus/draw_mini_map.c mlx_utils.c data_init.c intersectionxy.c wall_projections.c player_moves.c

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
	rm -rf $(NAME) $(OBJ) draw_mini_map.o check_color_texture.o check_map.o parsing_stock.o parsing_utils.o

re: fclean all
