/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 12:26:05 by gimsang-w         #+#    #+#             */
/*   Updated: 2021/12/17 23:14:33 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_v(int type, int value)
{
	static int	val[16];
	int			i;

	i = -1;
	if (type & NUMBER)
		while (++i < 16)
			val[i] = 0;
	else if (type & SET)
		val[type & (NUMBER - 1)] = value;
	else if (type & GET)
		return (val[type & (NUMBER - 1)]);
	return (value);
}

int	ft_square(int a)
{
	int	i;

	i = 0;
	while (i * i <= a)
		++i;
	return (i - 1);
}

void	ft_words(int cmd)
{
	if (cmd & R)
		ft_printf("r", 1);
	else if (cmd & RR)
		ft_printf("rr", 1);
	else if (cmd & S)
		ft_printf("s", 1);
	else if (cmd & P)
		ft_printf("p", 1);
	if (cmd & RRR)
		ft_printf("rr\n", 1);
	else if (cmd & RRRR)
		ft_printf("rrr\n", 1);
	else if (cmd & GETB)
		return ;
	else if (cmd & NUM)
		ft_printf("b\n", 1);
	else
		ft_printf("a\n", 1);
	return ;
}

int	ft_checkarray(int *a, int size, int to)
{
	int	i;

	i = -1;
	while (++i < size - 1)
	{
		if (to >= 0)
		{
			if (a[i] > a[i + 1])
				return (-3);
		}
		else
		{
			if (a[i] <= a[i + 1])
				return (-3);
		}
	}
	return (0);
}

void	ft_order(int *a, int size)
{
	int	*b;
	int	*c;
	int	tmp[3];

	tmp[2] = -1;
	b = malloc(sizeof(int) * size);
	c = malloc(sizeof(int) * size);
	b[0] = -1;
	while (++tmp[2] < size)
	{
		tmp[0] = -1;
		tmp[1] = -1;
		while (++tmp[0] < size)
			if ((tmp[2] != 0 && (a[b[tmp[2] - 1]]
						> a[tmp[0]] && (tmp[1] == -1 || a[tmp[1]] < a[tmp[0]])))
				|| (tmp[2] == 0 && (tmp[1] == -1 || a[tmp[1]] < a[tmp[0]])))
				tmp[1] = tmp[0];
		b[tmp[2]] = tmp[1];
	}
	while (++tmp[2] - size - 1 < size)
		c[b[tmp[2] - size - 1]] = size - tmp[2] + size + 1;
	while (++tmp[2] - size * 2 - 2 < size)
		a[tmp[2] - size * 2 - 2] = c[tmp[2] - size * 2 - 2];
	free(c);
	free(b);
}
