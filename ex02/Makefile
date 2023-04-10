NAME= PmergeMe
CXX = c++
CPPFLAGS= -Wall -Wextra -Werror -std=c++98
SRC= main.cpp PmergeMe.cpp
OBJ= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME):$(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re