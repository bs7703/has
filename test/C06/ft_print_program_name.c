#include <unistd.h>
int	main(int size, char **args)
{
		while(size && **(args)) 
			write(1, *((*args)++), 1);
	return (0);
}
