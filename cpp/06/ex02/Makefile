CPP = c++
SRC = A.cpp B.cpp C.cpp Base.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
HEADER = A.hpp B.hpp C.hpp Base.hpp
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = Base

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