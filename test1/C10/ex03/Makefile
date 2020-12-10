CC = gcc
CFLAGS = -Wall -Wextra -Werror
TARGET = ft_cat
OBJS = cat.o
SRCS = $(OBJS :.o=.c)

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o : %.c
	$(CC) -c $(CFLAGS) $<

clean :
	rm -rf *.o

fclean :
	rm -rf *.o
	rm -rf $(TARGET)

re :
	make fclean
	make
