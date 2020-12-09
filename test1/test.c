#include <stdio.h>
#include "ex05/ft_sqrt.c"
#include "ex08/ft_ten_queens_puzzle.c"
#include "../C04/ex03/ft_atoi.c"
int	main(int size, char **args)
{
	int (*fp)(void);
	fp = ft_ten_queens_puzzle;
	printf("%d",fp());
}
