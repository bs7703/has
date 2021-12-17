/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 20:16:18 by gimsang-w         #+#    #+#             */
/*   Updated: 2021/10/27 20:31:08 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

char	*ft_join(char *str1, char *str2)
{
	char	*rs;
	char	*rt;

	if (!*str1 && !*str2)
		return (0);
	if (!str1 || !*str1)
		return ((char *)str2);
	if (!str2 || !*str2)
		return ((char *)str1);
	rs = malloc(sizeof(char) * (ft_strlen(str1, 0) + ft_strlen(str2, 0) + 1));
	if (!rs)
		return (0);
	rt = rs;
	while (*str1)
		*rs++ = *str1++;
	while (*str2)
		*rs++ = *str2++;
	*rs = 0;
	return (rt);
}

int	ft_include(char *str, char c)
{
	while (*str)
		if (*str++ == c)
			return (1);
	return (0);
}

int	ft_selecti(int a, int b, int c)
{
	if (!c)
		return (a);
	return (b);
}

int	*ft_selectp(int *a, int *b, int c)
{
	if (!c)
		return (a);
	return (b);
}

char	**ft_split(char *str, char deli)
{
	int		size;
	char	**rs;
	int		i;

	if (!str || !*str || !deli)
		return (0);
	i = -1;
	size = ft_splitsize(str, deli);
	rs = malloc(sizeof(char *) * (size + 1));
	if (!rs)
		return (0);
	i = -1;
	while (++i < size)
	{
		while (*str == deli)
			++str;
		rs[i] = ft_strcpy(str, ft_strlen(str, deli));
		str += ft_strlen(str, deli);
	}
	rs[i] = 0;
	return (rs);
}
