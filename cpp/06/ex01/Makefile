CPP = c++
SRC = main.cpp Serializer.cpp
OBJ = $(SRC:.cpp=.o)
HEADER = Serializer.hpp
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = Serialization

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