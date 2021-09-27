CC= gcc
FLAGS= -Wall -Wextra -Wall
OBJECTS=pipex.o pipex_utils.o pipex_mem_utils.o pipex_run_utils.o pipex_str_utils.o
SOURCES=pipex.c pipex_utils.c pipex_mem_utils.c pipex_run_utils.c pipex_str_utils.c
NAME=pipex

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) -o $@ $^
$(OBJECTS): $(SOURCES)
	$(CC) $(FLAGS) -c $^
clean:
	rm -rf *.o
fclean:
	make clean
	rm -rf $(NAME)
re:
	make fclean
	make
