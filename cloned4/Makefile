CC=gcc
FLAGS= -Wall -Wextra -Werror
SOURCES= ft_memutils.c ft_strutils.c ft_numutils.c ft_utils0.c ft_utils1.c ft_utils2.c ft_utils3.c ft_checkutils.c	ft_utils5.c ft_utils4.c
SOURCES2= get_next_line.c get_next_line_utils.c
SRC_PUSH= ft_push_swap.c
SRC_CHECKER= ft_checker.c
OBJ_PUSH= ft_push_swap.o
OBJ_CHECKER=ft_checker.o
OBJECTS=$(SOURCES:.c=.o)
OBJECTS2=$(SOURCES2:.c=.o)
NAME=push_swap
BONUS=checker

all:$(NAME)

$(NAME): $(OBJECTS) $(OBJ_PUSH)
	$(CC) $(FLAGS) -o $(NAME) $(OBJECTS) $(OBJ_PUSH)
$(BONUS): $(OBJECTS) $(OBJECTS2) $(OBJ_CHECKER)
	$(CC) $(FLAGS) -o $(BONUS) $(OBJECTS) $(OBJECTS2) $(OBJ_CHECKER)
$(OBJECTS): $(SOURCES)
	$(CC) $(FLAGS) -c $(SOURCES)
$(OBJECTS2): $(SOURCES2)
	$(CC) $(FLAGS) -c $(SOURCES2)
$(OBJ_PUSH): $(SRC_PUSH)
	$(CC) $(FLAGS) -c $(SRC_PUSH)
$(OBJ_CHECKER): $(SRC_CHECKER)
	$(CC) $(FLAGS) -c $(SRC_CHECKER)
clean:
	rm -rf $(OBJECTS) $(OBJECTS2) $(OBJ_PUSH) $(OBJ_CHECKER)
fclean:
	make clean
	rm -rf $(NAME) $(BONUS)
re:
	make fclean
	make
