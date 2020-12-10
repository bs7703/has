#include <stdio.h>
#include "C04/ex03/ft_atoi.c"
#include "C07/ex05/ft_split.c"
int	main(int size, char **args)
{
	char	**g;

	if (size <= 2)
		return (0);
	g = ft_split(*(args + 2),*(args + 1));
	while (g != 0)
		printf("%s",*(g++));
}
