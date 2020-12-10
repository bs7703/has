/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 13:53:59 by sakim             #+#    #+#             */
/*   Updated: 2020/12/10 19:03:10 by sakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int						ft_strlen(char *str)
{
	int					x;

	x = -1;
	while (*(str + ++x))
	{
	}
	return (x);
}

char					*str_copy(char *str)
{
	char				*copy;
	int					size;
	int					i;

	if (!str)
		return (0);
	i = -1;
	size = ft_strlen(str);
	copy = (char *)malloc(sizeof(char) * (1 + size));
	while (++i <= size)
		copy[i] = str[i];
	return (copy);
}

struct s_stock_str		*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str			*st;
	int					y;

	y = -1;
	if (ac < 0)
		return (0);
	st = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!st)
		return (0);
	while (++y < ac)
	{
		st[y].size = ft_strlen(av[y]);
		st[y].str = av[y];
		st[y].copy = str_copy(av[y]);
	}
	st[y].str = 0;
	return (st);
}
