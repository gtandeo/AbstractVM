NAME = avm

FILES = main IOperand.class Operand.class
FILES_FOLD = srcs/
SRCS = $(addprefix $(FILES_FOLD), $(addsuffix .cpp, $(FILES)))
OBJS = $(SRCS:.cpp=.o)

INC_FILES = IOperand.class Operand.class
INC_FOLDER = includes/
INC_SRCS = $(addprefix $(INC_FOLDER), $(addsuffix .hpp, $(INC_FILES)))
INC = -I $(INC_FOLDER)

CC = @clang++
CFLAGS = -Wall -Wextra -Werror -std=c++11 $(INC)

DEL = @/bin/rm -f
COL0 = \033[0m
COL1 = \033[33m
COL2 = \033[36m

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(SFML)
	@echo "$(COL1)$(NAME)$(COL0) created."

%.o : %.cpp $(INC_SRCS)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(DEL) $(OBJS)

fclean: clean
	$(DEL) $(NAME)
	@echo "$(COL2)$(NAME)$(COL0) removed."

re: fclean all

.PHONY: clean fclean re
