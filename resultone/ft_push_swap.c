/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakim <sakim@student.seoul42.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 22:03:29 by sakim             #+#    #+#             */
/*   Updated: 2021/12/18 01:23:00 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int n, char **args)
{
	int		*a;
	int		*b;
	int		fr;

	fr = 0;
	if (n < 2)
		return (0);
	if (n == 2)
	{
		args = ft_split(args[1], ' ');
		fr = 1;
		n = ft_count(args) + 1;
	}
	else
		++args;
	a = ft_getintlist((const char **)args, n - 1, CHECKDUP);
	if (!a)
		return (ft_free(args, fr));
	ft_order(a, n - 1);
	b = malloc(sizeof(int) * (n - 1));
	if (ft_checkarray(a, n - 1, -1) != 0)
		ft_pushswap(a, b, n - 1);
	free(b);
	free(a);
	return (ft_free(args, fr));
}
