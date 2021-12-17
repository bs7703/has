/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakim <sakim@student.seoul42.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 20:52:29 by sakim             #+#    #+#             */
/*   Updated: 2021/12/17 23:17:33 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_while(const char **str, char toig, int toreturn)
{
	int	i[3];

	if (!str || !*str || ! toig)
		return (FAIL);
	while (**(str) == toig)
		++*(str);
	i[0] = LEVEL_WHILE;
	i[1] = 1;
	while (**(str) && --i[0])
	{
		if (i[1] & toreturn)
			i[2] = ft_check(**(str), i[1] & toreturn);
		if (i[2] != FAIL)
		{
			if (i[2] == MINUS || i[2] == PLUS)
				++*(str);
			return (i[2]);
		}
		i[1] *= 2;
	}
	return (FAIL);
}

void	ft_trim(char *str)
{
	int	i;

	i = -1;
	while (*(str + ++i))
	{
		if (*(str + i) == '\n')
		{
			*(str + i) = 0;
			break ;
		}
	}
}

int	*ft_error(void *p)
{
	free(p);
	write(2, "Error\n", 6);
	return ((int *)NILL);
}
