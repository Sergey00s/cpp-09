NAME= btc
CXX = c++
CPPFLAGS= -Wall -Wextra -Werror
SRC= main.cpp BitcoinExchange.cpp 
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