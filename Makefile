SRC = main.c gnl/get_next_line.c gnl/get_next_line_utils.c

NAME = cub3D

CC = cc

FLAGS = -Wall -Wextra -Werror -g

OBJ = $(SRC:.c=.o)

$(NAME): cube3D.h gnl/get_next_line.h $(OBJ) libft/libft.a
	$(CC) $(FLAGS) -o $(NAME) $(SRC) libft/libft.a

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
