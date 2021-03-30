NAME = interpret

SRCS = main.cpp \
		Instructions.cpp \
		InstructionFactory.cpp

OBJ = $(subst .cpp,.o,$(SRCS))

CC = clang++

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -o $@ -c $< 

$(NAME): $(OBJ)
	$(CC) -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all