OBJECTS = *.o
SRC = main.cpp\
		src/Exceptions.cpp\
		src/Operands.cpp\

FLAGS = -Wall -Wextra -Werror -std=c++11
NAME = vm

all: $(NAME)

$(NAME):
	clang++ $(FLAGS) $(SRC) -o $(NAME) 

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
