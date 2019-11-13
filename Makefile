OBJECTS = *.o
SRC = main.cpp\
		src/Exceptions.cpp\
		src/Operands.cpp\
		src/Operations.cpp\

FLAGS = -Wall -Wextra -Werror -std=c++11
NAME = vm

all: $(NAME)

$(NAME):
	clang++ $(FLAGS) $(SRC) -o $(NAME) 

lldb:
	clang++ $(FLAGS) $(SRC) -o $(NAME) -g

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)
	rm -rf $(NAME).dSYM

re: fclean all
