CC=gcc
FLAGS=-Wall -Wextra -Werror
NAME=philo_one
SRCS=ft_philo.c ft_philo_init.c ft_philo_utils0.c ft_philo_utils1.c
OBJS=$(SRCS:.c=.o)

all=$(NAME)

$(NAME): $(OBJS)
	gcc $(FLAGS) -o $(NAME) $(OBJS)
$(OBJS): $(SRCS)
	gcc -c $(SRCS)
clean:
	rm -rf $(OBJS)
fclean:
	rm -rf $(OBJS) $(NAME)
re:
	make fclean
	make
