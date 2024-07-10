CC = cc
CFLAGS = -Wall -Wextra -Werror 
NAME = push_swap
BNAME = checker
SRCS = cmd1.c cmd2.c cmd3.c deque_cmd.c find_pivot.c greedy.c init.c main.c move.c parsing.c partition.c sort.c utils.c
BSRCS = bonus/checker_bonus.c bonus/cmd1_bonus.c bonus/cmd2_bonus.c bonus/cmd3_bonus.c \
		bonus/deque_cmd_bonus.c bonus/find_pivot_bonus.c bonus/init_bonus.c bonus/main_bonus.c \
		bonus/parsing_bonus.c bonus/get_next_line/get_next_line.c bonus/get_next_line/get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)

.PHONY : all clean fclean re bonus

all : $(NAME)

$(NAME) : $(OBJS)
	make -C ./Libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) ./Libft/libft.a

bonus : $(BNAME)

$(BNAME) : $(BOBJS)
	make -C ./Libft
	$(CC) $(CFLAGS) -o $(BNAME) $(BOBJS) ./Libft/libft.a

.c.o :
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

clean :
	$(MAKE) -C ./Libft clean
	rm -f $(OBJS) $(BOBJS)

fclean : 
	$(MAKE) -C ./Libft fclean
	$(MAKE) clean
	rm -f $(NAME) $(BNAME)

re : fclean all