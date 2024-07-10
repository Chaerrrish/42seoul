CC = cc
CFLAGS = -Wall -Wextra -Werror 
NAME = pipex
SRCS = main.c utils.c
OBJS = $(SRCS:.c=.o)

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	make -C ./Libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) ./Libft/libft.a

.c.o :
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

clean :
	$(MAKE) -C ./Libft clean
	rm -f $(OBJS)

fclean : 
	$(MAKE) -C ./Libft fclean
	$(MAKE) clean
	rm -f $(NAME)

re : fclean all