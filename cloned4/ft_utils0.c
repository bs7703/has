/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 20:09:26 by gimsang-w         #+#    #+#             */
/*   Updated: 2021/10/28 06:21:24 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	int	i;

	i = 0;
	while (*(str1 + i) == *(str2 + i) && *(str1 + i))
		++i;
	if (*(str1 + i) == *(str2 + i))
		return (1);
	return (0);
}

void	ft_rotate(int *i, int size, int p)
{
	int	tmp[2];
	int	n;

	if (p <= 0)
		p = -1;
	else if (p > 0)
		p = 1;
	n = -1;
	tmp[0] = i[0];
	while (++n < size)
	{
		tmp[1] = i[(size - (n + 1) * p) % size];
		i[(size - (n + 1) * p) % size] = tmp[0];
		tmp[0] = tmp[1];
	}
}

int	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	return (1);
}

int	ft_which(int *a, int *b, int cmd, int n)
{
	if (cmd & RRRR)
	{
		ft_cmd(a, b, RR | REINVOKED, n);
		ft_cmd(a, b, RR | B | REINVOKED, n);
	}
	else if (cmd & RRR)
	{
		ft_cmd(a, b, R | REINVOKED, n);
		ft_cmd(a, b, R | B | REINVOKED, n);
	}
	else if (cmd & SS)
	{
		ft_cmd(a, b, S | REINVOKED, n);
		ft_cmd(a, b, S | B | REINVOKED, n);
	}
	else
		return (0);
	return (1);
}
