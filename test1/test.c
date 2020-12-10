#include <stdio.h>
#include "C04/ex03/ft_atoi.c"
#include "C04/ex04/ft_putnbr_base.c"
int	main(int size, char **args)
{
	char a[] = "As";
	a[1] = '\'';
	char b[] = "AD";
	ft_putnbr_base(-10,a);
}
