#include <stdio.h>
#include "ft_putnbr_base.c"
#include "ft_atoi_base.c"
int	main(void)
{
	char test[] = "ABSSLOO";
	char bf[] = "ABSLO";
	char bt[] = "12345";
	int x = ft_atoi_base(test,bf);
	ft_putnbr_base(x,bt);
	//printf("%d",x);
}
