MAKEFLAGS += --silent
CC = cc
CFLAGS = -Wall -Wextra -Werror
TARGET = do-op
SRCS = do_op.c calculator.c ft_putnbr.c

all : $(TARGET)

$(TARGET) : $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean :
	rm -f *.o

fclean : clean
	rm -f $(TARGET)

re : fclean all