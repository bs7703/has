/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractal_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 21:48:14 by gimsang-w         #+#    #+#             */
/*   Updated: 2021/11/29 22:00:22 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int	ft_cal(float x, float y)
{
	register int	i;
	float			temp;
	float			a;
	float			b;

	a = x;
	b = y;
	i = -1;
	while (++i < REPEAT)
	{
		if (a * a + b * b > 2 * 2)
			return (i);
		temp = a * a - b * b + x;
		b = 2 * a * b + y;
		a = temp;
	}
	return (i);
}

int	ft_cal2(float x, float y)
{
	register int	i;
	float			a;
	float			b;
	float			temp;

	i = -1;
	a = x;
	b = y;
	while (++i < 256)
	{
		temp = a * a - b * b + ft_vd(G | JULX, 0);
		b = 2 * a * b + ft_vd(G | JULY, 0);
		a = temp;
		if (a * a + b * b > 4)
			return (i);
	}
	return (i);
}
