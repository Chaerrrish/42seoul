CC = cc
CFLAGS =
MLX_FLAGS = -Lmlx -lmlx -framework OpenGl -framework AppKit -Imlx
NAME = so_long
SRCS = key.c main.c map.c show_map.c check_map.c\
		get_next_lines/get_next_line.c get_next_lines/get_next_line_utils.c\
		ft_printf/ft_printf.c ft_printf/ft_putnbr_fd.c ft_printf/print_csdui.c ft_printf/print_hex.c
OBJS = $(SRCS:.c=.o)

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(MLX_FLAGS) -o $(NAME) $(OBJS)

.c.o :
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all