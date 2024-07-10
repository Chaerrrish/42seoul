CC = cc
CFLAGS = -Wall -Wextra -Werror
TARGET = ft_cat
SRCS = ft_cat.c main.c

all : $(TARGET)

$(TARGET) : $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean :
	rm -f *.o

fclean : clean
	rm -f $(TARGET)

re : fclean all