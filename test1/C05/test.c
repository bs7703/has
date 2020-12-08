#include <stdio.h>
#include "ft_sqrt.c"
#include "ft_is_prime.c"
#include "../C04/ex03/ft_atoi.c"
int	main(int size, char **args)
{
	int (*fp)(int);
	fp=(*args[1] == 48) ? ft_sqrt : ft_is_prime;
	int x = ft_atoi(args[2]);
	printf("%d,%d",x,fp(x));
}
