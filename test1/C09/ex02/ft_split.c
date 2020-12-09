/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 19:40:33 by sakim             #+#    #+#             */
/*   Updated: 2020/12/10 01:08:17 by sakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			ft_strlen(char *str)
{
	int		x;

	x = -1;
	while (*(str + ++x))
	{
	}
	return (x);
}

char		*ft_strstr(char *str, char *to_find)
{
	int		p;
	int		i;

	i = 0;
	if (!*to_find)
		return (0);
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

int			calc(char *str, char *charset)
{
	char	*ct;
	char	*pv;
	int		cs;
	int		size;

	size = 1;
	cs = ft_strlen(charset);
	ct = ft_strstr(str, charset);
	pv = str;
	while (ct)
	{
		if (pv < ct)
			++size;
		if (!*(ct + 1))
			break ;
		pv = ct + cs;
		ct = ft_strstr(ct + 1, charset);
		if (!ct && ++size)
			break ;
	}
	return (size);
}

char		*am(char *a, char *set)
{
	char	*result;

	result = a;
	if (set && *set)
		*set = 0;
	return (result);
}

char		**ft_split(char *str, char *charset)
{
	char	**result;
	char	**two;
	char	*pv;
	char	*ct;
	int		cs;

	cs = ft_strlen(charset);
	result = (char **)malloc(sizeof(char *) * calc(str, charset) + 1);
	two = result;
	ct = ft_strstr(str, charset);
	pv = str;
	while ((ct) || ((*(result++) = am(pv, 0)) &&
			(*result = 0)))
	{
		if (pv < ct)
			*(result++) = am(pv, ct);
		if (!*(ct + 1) && !(*result = 0))
			break ;
		pv = ct + cs;
		ct = ft_strstr(ct + 1, charset);
	}
	return (two);
}
