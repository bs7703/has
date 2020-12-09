/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 14:53:16 by sakim             #+#    #+#             */
/*   Updated: 2020/12/08 15:05:09 by sakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*range(int min, int max)
{
	int	*result;
	int	index;

	result = 0;
	index = -1;
	if (max - min > 0)
		result = (int *)malloc(sizeof(int) * (max - min));
	while (++index + min < max)
		result[index] = min + index;
	return (result);
}
