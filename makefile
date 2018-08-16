NAME = avm

CC = clang++

FLAGS = -Wall -Werror -Wextra -std=c++11

SRC =	main.cpp\
		src/AVM.cpp\
		src/AVMException.cpp\
		src/Factory.cpp\
		src/Lexer.cpp\
		src/Parser.cpp\
		src/Stack.cpp

HDR = -I ./hdr

all: $(NAME)

$(NAME): $(SRC)
	@$(CC) -o $(NAME) $(SRC) $(HDR) $(FLAGS)
	@echo **compiling

clean:
	@echo **cleaning

fclean: clean
	@rm -rf $(NAME)
	@echo **fcleaning

re: fclean all
	@echo **remake complete


