CPP = c++
SRC = main.cpp Animal.cpp Dog.cpp Cat.cpp Brain.cpp
OBJ = $(SRC:.cpp=.o)
HEADER = Animalhpp Dog.hpp Cat.hpp Brain.hpp
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = Polymorphism

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