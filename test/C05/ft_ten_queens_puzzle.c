#include <stdio.h>
#define max 9
int			ff(char *b, int d, int n)
{
	while (++n < d + 1)
		if (*(b + d - n) - n == *(b + d) || *(b + d - n) + n == *(b + d)
			|| *(b + d - n) == *(b + d))
			return (0);
	return (1);
}

int			printAll(char *s)
{
	while (*s)
		write(1, s++, 1);
	write(1, "\n", 1);
	return (1);
}

int			cA(int d, char *s, int r)
{
	while (d <= max && ++*(s + d) <= 57)
		if (ff(s, d, 0))
			r = r + ((d == max) ? printAll(s) : cA(d + 1, s, 0));
	return ((*(s + d) = 47) + r - 47);
}

int			ft_ten_queens_puzzle(void)
{
	char	start[max + 2];
	int		i;

	i = -1;
	while (++i < max + 2)
		start[i] = (i == max + 1) ? 0 : 47;
	return cA(0, start, 0);
}
