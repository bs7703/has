CC = gcc -c
TARGET = libft.a
CFLAGS = -Wall -Wextra -Werror
OBJS = srcs/ft_putchar.o srcs/ft_swap.o srcs/ft_putstr.o srcs/ft_strlen.o srcs/ft_strcmp.o
SRCS = $(OBJS:.o=.c)
INCS = -l./includes

all: $(TARGET)

$(TARGET) : $(OBJS)
	ar -cr $@ $(OBJS)
%.o:%.c
	$(CC) $(CFLAGS) $< -o $@ -l includes/ft.h
clean :
	rm -f srcs/*.o
	rm -f $(TARGET)
fclean :
	rm -f srcs/*.o
	rm -f $(TARGET)

re : 
	make $(fclean)
	make
