/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 01:42:16 by sakim             #+#    #+#             */
/*   Updated: 2021/12/17 12:30:05 by sakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int n, char **args)
{
	int	*i;
	int	rs;
	int	*b;

	if (n < 2)
		return (0);
	if (n == 2)
	{
		args = ft_split(args[1], ' ');
		n = ft_count(args) + 1;
	}
	else
		++args;
	i = ft_getintlist((const char **)args, n - 1, CHECKDUP);
	b = malloc(sizeof(int) * (n - 1));
	if (!i)
		return (FAIL);
	rs = ft_multiplecmd(i, b, n - 1);
	if (rs == 0)
		ft_printf("OK\n");
	else if (rs == -1)
		ft_printf("error\n");
	else
		ft_printf("KO\n");
	free(i);
	free(b);
	return (0);
}
