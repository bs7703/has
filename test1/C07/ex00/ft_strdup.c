/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakim <sakim@student.42.kr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 01:43:11 by sakim             #+#    #+#             */
/*   Updated: 2020/12/08 01:47:18 by sakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strdup(char *src)
{
	int		x;
	char	*copy;

	x = -1;
	while (src[++x])
	{
	}
	copy = (char *)malloc(sizeof(char) * (x + 1));
	if ((x = -1) && !copy)
		return (0);
	while (src[++x] || (copy[x] = 0))
		copy[x] = src[x];
	return (copy);
}
