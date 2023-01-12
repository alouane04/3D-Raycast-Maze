SRC = main.c  parsing_stock.c parsing_utils.c check_map.c check_color_texture.c bonus/draw_mini_map.c mlx_utils.c data_init.c intersectionxy.c wall_projections.c player_moves.c

NAME = cub3D

CC = cc

FLAGS = -Wall -Wextra -Werror -Imlx -g

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
	rm -rf $(NAME) $(OBJ) draw_mini_map.o cub3D.dSYM

re: fclean all
