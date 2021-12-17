/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 21:49:10 by gimsang-w         #+#    #+#             */
/*   Updated: 2021/11/30 00:07:21 by sakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	ft_jultype(int key)
{
	if (ft_v(G | JULTYPE, 0) == 2)
	{
		ft_vd(S | JULX, -0.42f);
		ft_vd(S | JULY, +0.95f);
	}
	else if (ft_v(G | JULTYPE, 0) == 3)
	{
		ft_vd(S | JULX, +0.315f);
		ft_vd(S | JULY, +0.495f);
	}
	else if (ft_v(G | JULTYPE, 0) == 4)
	{
		ft_vd(S | JULX, +0.39f);
		ft_vd(S | JULY, -0.27f);
	}
	else
	{
		ft_vd(S | JULX, -0.39f);
		ft_vd(S | JULY, -0.62f);
	}
}

void	ft_init(void)
{
	ft_jultype(ft_v(G | JULTYPE, 0));
	ft_v(S | Z, 0);
	ft_v(S | WX, WINX);
	ft_v(S | WY, WINY);
	ft_vd(S | X, -2.0f);
	ft_vd(S | Y, 2.0f);
}

int	ft_color(int depth)
{
	if (depth < 32)
		return (ft_rgb(255, 255, 255, 1));
	else if (depth < 64)
		return (ft_rgb(0, 20 + depth * 4, 255, 1));
	else if (depth < 96)
		return (ft_rgb(255, 20 + depth * 4, 255, 1));
	else if (depth < 128)
		return (ft_rgb(20 + depth * 4, 255, 255, 1));
	else if (depth < 160)
		return (ft_rgb(20 + depth * 4, 0, 255, 1));
	else if (depth < 192)
		return (ft_rgb(20 + depth * 4, 0, 0, 1));
	else if (depth < 228)
		return (ft_rgb(0, 40 + depth * 1, 20 + depth * 4, 1));
	return (ft_rgb(0, 0, 0, 1));
}

void	ft_paint(int x, int y, float z)
{
	int		depth;
	int		color;
	float	mapx;
	float	mapy;

	mapx = ft_vd(G | X, 0) + (float)x / ((ft_v(G | WX, 0) / 4) * z);
	mapy = ft_vd(G | Y, 0)
		- (float)(ft_v(G | WY, 0) - y) / ((ft_v(G | WY, 0) / 4) * z);
	if (ft_v(G | RENDER, 0) == 2)
		depth = ft_cal2(mapx, mapy);
	else
		depth = ft_cal(mapx, mapy);
	color = ft_color(depth);
	mlx_pixel_put(ft_vp(G | 0, 0), ft_vp(G | 1, 0), x, y, color);
}

int	ft_print(void *p, void *q)
{
	int		win[2];
	int		lim[2];
	float	z;

	z = pow(ZGR, ft_v(G | Z, 0));
	win[0] = -1;
	lim[0] = ft_v(G | WX, 0);
	lim[1] = ft_v(G | WY, 0);
	mlx_clear_window(ft_vp(G | 0, 0), ft_vp(G | 1, 0));
	while (++win[0] < lim[0])
	{
		win[1] = -1;
		while (++win[1] < lim[1])
			ft_paint(win[0], win[1], z);
	}
	return (0);
}
