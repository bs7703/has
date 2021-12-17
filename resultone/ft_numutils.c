/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakim <sakim@student.seoul42.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 20:53:30 by sakim             #+#    #+#             */
/*   Updated: 2021/12/18 01:38:17 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_check(char c, int sign)
{
	if ((sign & NUM) && (48 <= c && c <= 57))
		return (sign);
	else if (sign & PLUS && c == 43)
		return (sign);
	else if (sign & MINUS && c == 45)
		return (sign);
	else if (sign & ALPHB && (65 <= c && c <= 90))
		return (sign);
	else if (sign & ALPHS && (97 <= c && c <= 122))
		return (sign);
	return (FAIL);
}

int	ft_checknum_form(const char **str)
{
	int			i;
	const char	*rs;

	i = ft_while(str, ' ', NUM | PLUS | MINUS);
	if (i == NUM)
		i = PLUS;
	if (i == FAIL || i == SUCCESS)
		return (i);
	rs = *str;
	while (*rs)
		if (ft_check(*rs++, NUM) != NUM)
			return (FAILA);
	return (i);
}

int	*ft_atoi(const char *str, int s)
{
	int	b;
	int	*rs;

	b = DEC;
	if (!str || !*str || (s != 1 && s != -1))
		return (NILL);
	rs = malloc(sizeof(int));
	*rs = 0;
	if (!rs)
		return (0);
	while (*str == 48)
		++str;
	while (*str)
	{
		if (b * *rs + (*str - 48) < *rs
			&& !(*rs == 214748364 && s == -1 && (*str - 48) == 8))
			return (ft_free0(rs));
		*rs = b * *rs + (*str++ - 48);
	}
	if (s == -1)
		*rs *= s;
	return (rs);
}

int	ft_checkdup(int *p, int size)
{
	int	i;

	while (size - 1 > 0)
	{
		i = 0;
		while (++i < size)
			if (*p == *(p + i))
				return (FAIL);
		--size;
		++p;
	}
	return (SUCCESS);
}

int	*ft_getintlist(const char **args, int size, int check)
{
	int			*i;
	int			*rs;
	int			sign;
	int			c;

	c = -1;
	i = malloc(sizeof(int) * size);
	while (*(args + ++c))
	{
		sign = ft_checknum_form(args + c);
		if (sign < SUCCESS)
			return (ft_error(i));
		else if (sign == MINUS)
			sign = -1;
		else
			sign = 1;
		rs = ft_atoi(*(args + c), sign);
		if (rs == NILL)
			return (ft_error(i));
		i[size - c - 1] = *rs;
		free(rs);
	}
	if (check | CHECKDUP && ft_checkdup(i, size) == FAIL)
		return (ft_error(i));
	return (i);
}
