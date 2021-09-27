/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_str_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakim <sakim@student.seoul42.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 09:42:04 by sakim             #+#    #+#             */
/*   Updated: 2021/09/27 13:57:52 by sakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

char	**ft_split(char *str, char deli)
{
	int		size;
	char	**rs;
	int		i;

	i = -1;
	size = ft_splitsize(str, deli);
	rs = malloc(sizeof(char *) * (size + 1));
	if (!rs || !str || !*str || !deli)
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

char	*ft_join(const char *str1, const char *str2)
{
	char	*rs;
	char	*rt;

	if (!*str1 && !*str2)
		return (0);
	if (!str1 || !*str1)
		return ((char *)str2);
	if (!str2 || !*str2)
		return ((char *)str1);
	rs = malloc(sizeof(char) * (strlen(str1) + strlen(str2) + 1));
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
