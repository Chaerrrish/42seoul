CPP = c++
SRC = main.cpp 
OBJ = $(SRC:.cpp=.o)
HEADER = 
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = Sed_is_for_losers

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CFLAGS) -o $@ $^ 

.o: .c
	$(CPP) $(CFLAGS) -c $< -o $@ -include $(HEADER)
clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re