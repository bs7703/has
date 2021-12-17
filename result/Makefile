CC=gcc
FLAG=-Wall -Wextra -Werror
SOURCES=ft_fractal_utils.c ft_str_utils.c ft_utils.c ft_data_utils.c ft_event_utils.c ft_fractol.c
OBJECTS=$(SOURCES:.c=.o)
NAME=fractol

all:$(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) -o $(NAME) $^ -lmlx -lX11 -l Xext -framework OpenGl -framework AppKit -L. -lz
$(OBJECTS): $(SOURCES)
	$(CC) $(FLAGS) -c $^

clean:
	rm -rf $(OBJECTS)
fclean:
	rm -rf $(OBJECTS) $(NAME)
re:
	make fclean
	make
