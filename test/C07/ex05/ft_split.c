/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 19:40:33 by sakim             #+#    #+#             */
/*   Updated: 2020/12/08 19:54:33 by sakim            ###   ########.fr       */
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

char		*ft_strstr(char *str, char *to_find)
{
	int		p;
	int		i;

	i = 0;
	if (!*to_find)
		return (str);
	while (str[i])
	{
		p = 0;
		while (str[i + p] == to_find[p])
		{
			p++;
			if (!to_find[p])
				return (str + i);
			if (!str[p + i])
				return (0);
		}
		i++;
	}
	return (0);
}

char		**ft_split(char *str, char *charset)
{

}
