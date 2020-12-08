/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 16:00:33 by sakim             #+#    #+#             */
/*   Updated: 2020/12/08 19:05:12 by sakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			ft_strlen(char **str, int size)
{
	int		x;
	int		re;
	int		y;

	y = -1;
	re = 0;
	x = -1;
	while ((++y < size) && str[y])
	{
		while (*(*(str + y) + ++x) || !(x = -1))
			re++;
	}
	return (re);
}

int			ft_strlen2(char *str)
{
	int		x;

	x = 0;
	while (*(str + +x))
		++x;
	return (x);
}

char		*ft_strcate(char *dest, char *src)
{
	int		i;

	i = -1;
	while (*(src + ++i))
		*(dest + i) = *(src + i);
	return (dest + i);
}

char		*ft_strjoin(int size, char **strs, char *sep)
{
	char	*re;
	int		i;
	int		j;
	char	*f;

	i = 0;
	j = -1;
	f = (char *)malloc(sizeof(char));
	*f = 0;
	if (!*strs || size <= 0)
		return (f);
	re = (char *)malloc(1 + ft_strlen(strs, size)
			+ (size - 1) * ft_strlen2(sep));
	f = re;
	while ((i < size) && strs[i])
	{
		while (strs[i][++j] || !(j = -1))
			*(re++) = strs[i][j];
		if ((++i < size) && strs[i])
			re = ft_strcate(re, sep);
		else
			*re = 0;
	}
	return (f);
}
