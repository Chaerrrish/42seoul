CPP = c++
SRC = main.cpp Fixed.cpp
OBJ = $(SRC:.cpp=.o)
HEADER = Fixed.hpp
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = Towards_a_more_useful_fixed-point_number_class

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