#include "ex01/ft_strncmp.c"

int	main(int size, char **args)
{
	char	*a = args[1];
	char	*b = args[2];
	printf("str:%d,ft:%d",strncmp(a,b,4),ft_strncmp(a,b,4));
}

