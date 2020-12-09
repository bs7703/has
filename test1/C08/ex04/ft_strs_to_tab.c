#include <stdlib.h>

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	s_stock_str	*st;
	int		y;

	y = -1;
	st = (s_stock_str *)malloc(sizeof(s_stock_str) * (ac + 1));
	if ((!st && !ac))
		return (0);
	while (++y < ac)
	{
		st[y].size = ft_strlen(av[y]);
		st[y].str = av[y];
		st[y].copy = ft_strcopy(av[y]);
	}
	st->str = 0;
	return (st);
}
