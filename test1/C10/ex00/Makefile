CC = gcc
CFLAGS = -Wall -Wextra -Werror
TARGET = ft_display_file
OBJS = display_file.o
SRCS = display_file.c

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
