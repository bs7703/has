/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 01:42:16 by sakim             #+#    #+#             */
/*   Updated: 2021/12/17 22:52:56 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int n, char **args)
{
	int		*i;
	int		*b;
	char	**f;

	f = 0;
	if (n < 2)
		return (0);
	if (n == 2)
	{
		args = ft_split(args[1], ' ');
		f = args;
		n = ft_count(args) + 1;
	}
	else
		++args;
	i = ft_getintlist((const char **)args, n - 1, CHECKDUP);
	b = malloc(sizeof(int) * (n - 1));
	if (!i)
		return (ft_free(f, n - 1));
	ft_order(i, n - 1);
	ft_multiplecmd(i, b, n - 1);
	free(i);
	free(b);
	return (ft_free(f, n - 1));
}
