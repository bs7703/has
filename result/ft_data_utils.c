/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 21:41:09 by gimsang-w         #+#    #+#             */
/*   Updated: 2021/11/29 22:17:17 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int	ft_rgb(int red, int green, int blue, int filter)
{
	if (filter)
	{
		if (red < 0)
			red = 0;
		if (green < 0)
			green = 0;
		if (blue < 0)
			blue = 0;
	}
	return ((red & 255) * 256 * 256 + (green & 255) * 256 + (blue & 255));
}

int	ft_v(int type, int value)
{
	static int	datas[100];

	if (type & G)
		return (datas[type & NUMBER]);
	else if (type & S)
		datas[type & NUMBER] = value;
	return (datas[type & NUMBER]);
}

float	ft_vd(int type, float value)
{
	static float	datas[100];

	if (type & G)
		return (datas[type & NUMBER]);
	else if (type & S)
		datas[type & NUMBER] = value;
	return (datas[type & NUMBER]);
}

void	*ft_vp(int type, void	*value)
{
	static void	*datas[10];

	if (type & G)
		return (datas[type & NUMBER]);
	else if (type & S)
		datas[type & NUMBER] = value;
	return (datas[type & NUMBER]);
}
