CC = cc
CFLAGS = -Wall -Wextra -Werror
TARGET = ft_display_file
SRCS = display_file.c

all : $(TARGET)

$(TARGET) : $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean :
	rm -f *.o

fclean : clean
	rm -f $(TARGET)

re : fclean all