/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 14:53:16 by sakim             #+#    #+#             */
/*   Updated: 2020/12/08 16:00:08 by sakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int			ft_ultimate_range(int **range, int min, int max)
{
	int		index;
	int		result;

	*range = 0;
	if (min >= max)
		return (0);
	result = 0;
	index = -1;
	while (++index + min < max)
	{
		*(range + index) = (int *)malloc(sizeof(int));
		if (!(range + index))
			return (-1);
		**(range + index) = index + min;
		result++;
	}
	return (result);
}
