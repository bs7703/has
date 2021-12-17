/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 20:19:25 by gimsang-w         #+#    #+#             */
/*   Updated: 2021/10/28 12:55:50 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_pushswap(int *a, int *b, int size)
{
	int	size2;

	size2 = size;
	while (size > 3)
	{
		ft_pivot(a, b, size, size2 - size + 1);
		size = size - size / ft_square(size);
		ft_v(NUMBER, 0);
	}
	if ((size == 2) && (a[1] > a[0]))
		ft_cmd(a, b, S, 2);
	else if (size == 3)
	{
		if (a[1] > a[0] && a[1] > a[2])
			ft_cmd(a, b, RR, 3);
		else if (a[2] > a[1] && a[2] > a[0])
			ft_cmd(a, b, R, 3);
		if (a[2] > a[1])
			ft_cmd(a, b, S, 3);
	}
	while ((size2 - ++size) >= 0)
		ft_cmd(a, b, P, size - 1);
	return (0);
}

int	ft_roll(int x)
{
	if (ft_v(4 | GET, 0) < 2)
		return (x);
	if (((x + 1) % (ft_v(2 | GET, 0) + 1) - 1)
		% ft_v(2 | GET, 0) == ft_v(0 | GET, 0))
		ft_v(0 | SET, 0);
	else
		ft_v(0 | SET, (ft_v(2 | GET, 0) + ft_v
				(0 | GET, 0) - x) % ft_v(2 | GET, 0) + 1);
	return (x);
}

int	ft_get(int a, int b, int flag)
{
	if ((flag == MIN && a <= b) || (flag == MAX && b <= a))
		return (a);
	if ((flag == MIN && b < a) || (flag == MAX && a < b))
		return (b);
	else if (flag == ABSMINUS && (((a - b >= 0)
				&& (a >= 0)) || (a - b < 0 && a < 0)))
		return (a - b);
	else if (flag == ABSMIN)
	{
		if (a < 0 && b < 0)
			return (ft_get(a, b, MAX));
		else if (a >= 0 && b >= 0)
			return (ft_get(a, b, MIN));
	}
	else if (flag == ABSSUM)
		return (ft_get(ft_get(a, b, ABSMIN), 0, ABS)
			+ ft_get(ft_get(a, ft_get(a, b, ABSMIN), ABSMINUS), 0, ABS)
			+ ft_get(ft_get(b, ft_get(a, b, ABSMIN), ABSMINUS), 0, ABS));
	else if (flag == ABS && a < 0)
		return (a * -1);
	else if (flag == ABS)
		return (a);
	return (0);
}

void	ft_bingle(int *a, int *b, int c, int d)
{
	int	i[4];
	int	x;

	ft_leastop(d, c, i);
	i[3] = -1;
	while (++i[3] < 3)
	{
		x = ((i[3] + 2) % 3) % 2;
		while (i[i[3]] != 0 && i[3] != 1)
			ft_cmd(a, b, ft_sp(i + i[3], R | x, RR | x), ft_v(1 | GET, 0));
		while (i[i[3]] != 0 && i[3] == 1)
			ft_cmd(a, b, ft_sp(i + i[3], RRR, RRRR), ft_v(1 | GET, 0));
	}
}

int	ft_pivot(int *a, int *b, int size, int off)
{
	ft_v(3 | SET, size / ft_square(size) + off);
	ft_v(5 | SET, size / ft_square(size));
	ft_v(1 | SET, size);
	while (ft_v(4 | GET, 0) < ft_v(5 | GET, 0))
	{
		ft_v(2 | SET, ft_cmd(a, b, GETB, 0));
		ft_search(a, b);
		ft_cmd(a, b, P | B, ft_v(1 | GET, 0));
		ft_v(1 | SET, size - ft_v(4 | SET, ft_v(4 | GET, 0) + 1));
		ft_v(2 | SET, ft_cmd(a, b, GETB, 0));
		if ((b[ft_v(2 | GET, 0) - 1] < b
				[ft_v(2 | GET, 0) - 2]) && (ft_v(4 | GET, 0) == 2))
			ft_cmd(a, b, S | B, ft_v(1 | GET, 0));
	}
	ft_bingle(a, b, ft_v(0 | GET, 0), 0);
	return (ft_v(4 | GET, 0));
}
