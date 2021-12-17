/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 20:21:26 by gimsang-w         #+#    #+#             */
/*   Updated: 2021/10/28 12:06:22 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_splitsize(char *str, char deli)
{
	int	btn;
	int	cnt;

	if (!*str || !str || !deli)
		return (0);
	cnt = 0;
	btn = 0;
	while (*str)
	{
		if (*str != deli && btn == 0)
			btn = ++cnt;
		else if (*str == deli && btn != 0)
			btn = 0;
		++str;
	}
	return (cnt);
}

int	ft_strlen(char *str, char deli)
{
	int	i;

	i = 0;
	while ((str[i] - deli) && str[i])
		++i;
	return (i);
}

char	*ft_strcpy(char *str, int size)
{
	int		i;
	char	*rs;

	i = -1;
	rs = malloc(sizeof(char) * (size + 1));
	if (!rs)
		return (0);
	while (str[++i] && (i < size))
		rs[i] = str[i];
	rs[i] = 0;
	return (rs);
}

void	ft_printf(char *str)
{
	write(1, str, ft_strlen(str, 0));
}
