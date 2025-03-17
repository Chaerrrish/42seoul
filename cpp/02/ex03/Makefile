CPP = c++
SRC = main.cpp Fixed.cpp Fixed.hpp Point.hpp Poin.cpp bsp.cpp
OBJ = $(SRC:.cpp=.o)
HEADER = Fixed.hpp Poin.hpp
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = BSP

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