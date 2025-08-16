SRCC = main.cpp Bureaucrat.cpp
OBJ = $(SRCC:.cpp=.o)
CFLAGS = -std=c++98 -Wall -Wextra -Werror
NAME = Bureaucrat

%.o: %.cpp
	c++ $(CFLAGS) -c $? -o $@

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(OBJ) $(CFLAGS) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re