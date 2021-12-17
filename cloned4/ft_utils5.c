/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 12:46:03 by gimsang-w         #+#    #+#             */
/*   Updated: 2021/10/28 12:47:34 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_sp(int *a, int b, int c)
{
	if (*a > 0)
	{
		--*a;
		return (b);
	}
	else
	{
		++*a;
		return (c);
	}
}

int	ft_leastop(int rota, int rotb, int *l)
{	
	int	i[6];

	i[4] = -1;
	i[0] = ft_get(rota, rotb, ABSSUM);
	i[1] = ft_get(rota, rotb - ft_v(2 | GET, 0), ABSSUM);
	i[2] = ft_get(rota - ft_v(1 | GET, 0), rotb, ABSSUM);
	i[3] = ft_get(rota - ft_v(1 | GET, 0), rotb - ft_v(2 | GET, 0), ABSSUM);
	i[5] = 0;
	while (++i[4] < 4)
		if (i[i[4]] < i[i[5]])
			i[5] = i[4];
	if (l)
	{
		if (i[5] <= 1)
			l[0] = rota;
		else
			l[0] = rota - ft_v(1 | GET, 0);
		l[2] = rotb - ft_v(2 | GET, 0) * (i[5] % 2);
		l[1] = ft_get(l[0], l[2], ABSMIN);
		l[0] = ft_get(l[0], l[1], ABSMINUS);
		l[2] = ft_get(l[2], l[1], ABSMINUS);
	}
	return (i[i[5]]);
}

int	ft_find(int *a, int val)
{
	int	j;
	int	x;

	if (ft_v(4 | GET, 0) < 2)
		return (0);
	x = ft_v(2 | GET, 0);
	j = -1;
	while (++j < ft_v(4 | GET, 0))
		if (a[(x + x - ft_v(0 | GET, 0) - j - 1) % x] < val)
			break ;
	return (j + ft_v(0 | GET, 0));
}

void	ft_search(int *a, int *b)
{
	int	j;
	int	i;
	int	y;
	int	rb[4];

	y = ft_v(1 | GET, 0) * 2 - 1;
	j = 0;
	i = 0;
	while (a[(y - j) % (ft_v(1 | GET, 0))] >= ft_v(3 | GET, 0))
		++j;
	rb[0] = ft_find(b, a[(y - j) % (ft_v(1 | GET, 0))]);
	rb[1] = ft_leastop(j, rb[0], 0);
	while (a[(y + i) % (ft_v(1 | GET, 0))] >= ft_v(3 | GET, 0))
		++i;
	rb[2] = ft_find(b, a[(y + i) % (ft_v(1 | GET, 0))]);
	rb[3] = ft_leastop((ft_v(1 | GET, 0) - i), rb[2], 0);
	if (rb[3] > rb[1])
		ft_bingle(a, b, ft_roll(rb[0]), j);
	else
		ft_bingle(a, b, ft_roll(rb[2]), (ft_v(1 | GET, 0) - i));
}
