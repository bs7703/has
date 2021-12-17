/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakim <sakim@student.seoul42.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 20:52:54 by sakim             #+#    #+#             */
/*   Updated: 2021/12/17 12:09:25 by sakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	*ft_free0(void *p)
{
	free(p);
	return ((int *)NILL);
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
