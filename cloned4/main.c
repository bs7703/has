

#include <stdio.h>

int	main(int n, char **args)
{
	int	i;

	i = -1;
	while (++i < n)
		printf("%s\n", args[i]);
}
