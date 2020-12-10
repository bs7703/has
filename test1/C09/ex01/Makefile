CC = gcc
TARGET = libft.a
CFLAGS = -Wall -Wextra -Werror
SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS = srcs/ft_putchar.o srcs/ft_swap.o srcs/ft_putstr.o srcs/ft_strlen.o srcs/ft_strcmp.o
INCS = -l ./includes

all: $(TARGET)

$(TARGET) : $(OBJS)
	ar -cr $@ $(OBJS)
srcs/%.o:%.c
	$(CC) $(CFLAGS) -c $< -I includes 
clean :
	rm -f srcs/*.o
fclean :
	rm -f srcs/*.o
	rm -f $(TARGET)
re :
	make fclean
	make
