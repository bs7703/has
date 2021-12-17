/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkutils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 20:05:27 by gimsang-w         #+#    #+#             */
/*   Updated: 2021/12/17 03:00:31 by sakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_cmdset(char *cmd)
{
	int	rs;

	rs = 0;
	if (ft_strcmp(cmd, "rb") || ft_strcmp(cmd, "rrb")
		|| ft_strcmp(cmd, "sb"))
		rs = B;
	if (ft_strcmp(cmd, "ra") || ft_strcmp(cmd, "rb"))
		rs |= R;
	else if (ft_strcmp(cmd, "rra") || ft_strcmp(cmd, "rrb"))
		rs |= RR;
	else if (ft_strcmp(cmd, "pa") || ft_strcmp(cmd, "pb"))
		rs |= P;
	else if (ft_strcmp(cmd, "sa") || ft_strcmp(cmd, "sb"))
		rs |= S;
	else if (ft_strcmp(cmd, "ss"))
		rs |= SS;
	else if (ft_strcmp(cmd, "rr"))
		rs |= RRR;
	else if (ft_strcmp(cmd, "rrr"))
		rs |= RRRR;
	return (rs);
}

int	ft_cmd(int *a, int *b, int cmd, int size)
{
	static int	i;
	int			*c;

	if (!(cmd & REINVOKED))
		ft_words(cmd);
	c = ft_selectp(a, b, cmd & NUM);
	if ((cmd & P) && ((i > 0 && c == a) || (
				c == b && size > 0)))
	{
		c[ft_selecti(size, i, cmd & NUM)] = *(ft_selectp(
					b, a, cmd & NUM) + ft_selecti(i - 1, size - 1, cmd & NUM));
		i += ft_selecti(-1, 1, cmd & NUM);
	}
	else if (cmd & GETB)
		return (i);
	else if (cmd & R || cmd & RR)
		ft_rotate(c, ft_selecti(size, i, cmd & NUM), cmd & RR);
	else if (cmd & S && ((c == b && i > 1) || (c == a && size >= 2)))
		ft_swap(c + ft_selecti(size - 1, i - 1, cmd & NUM),
			c + ft_selecti(size - 2, i - 2, cmd & NUM));
	else
		return (ft_which(a, b, cmd, size));
	return (1);
}
