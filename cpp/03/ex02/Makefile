CPP = c++
SRC = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
OBJ = $(SRC:.cpp=.o)
HEADER = ClapTrap.hpp ScavTrap.hpp FragTrap.hpp
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = FragTrap

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