#include <unistd.h>

int	main(int size, char **args)
{
		while(--size > 0 && *(++args))
			while(**(args + size))
				write(1, *((*args + size)++), 1);
	return (0);
}
