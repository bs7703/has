/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakim <sakim@student.seoul42.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 20:52:54 by sakim             #+#    #+#             */
/*   Updated: 2021/12/18 01:23:46 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_result(int n)
{
	if (n == 0)
		ft_printf("OK\n", 1);
	else if (n == -1)
		ft_printf("Error\n", 2);
	else
		ft_printf("KO\n", 1);
}

int	*ft_free0(void *p)
{
	free(p);
	return ((int *)NILL);
}

int	ft_free(char **str, int n)
{
	void	*p;

	if (n == 0)
		return (0);
	p = (void *)str;
	if (!str)
		return (0);
	while (*str)
	{
		free(*str);
		++str;
	}
	free(p);
	return (0);
}

int	ft_count(char **p)
{
	int	i;

	if (!p)
		return (-1);
	i = 0;
	while (*(p + i))
		++i;
	return (i);
}
