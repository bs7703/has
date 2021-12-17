/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 21:46:06 by gimsang-w         #+#    #+#             */
/*   Updated: 2021/11/29 23:52:27 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	ft_move(int key)
{
	float	z;

	z = pow(ZGR, ft_v(G | Z, 0));
	if (key == LK)
		ft_vd(S | X, ft_vd(G | X, 0) - 25.f / ((ft_v(G | WX, 0) / 4) * z));
	else if (key == RK)
		ft_vd(S | X, ft_vd(G | X, 0) + 25.f / ((ft_v(G | WX, 0) / 4) * z));
	else if (key == UK)
		ft_vd(S | Y, ft_vd(G | Y, 0) - 25.f / ((ft_v(G | WY, 0) / 4) * z));
	else if (key == DK)
		ft_vd(S | Y, ft_vd(G | Y, 0) + 25.f / ((ft_v(G | WY, 0) / 4) * z));
	ft_print(ft_vp(G | 0, 0), ft_vp(G | 1, 0));
}

int	ft_key(int key)
{
	if (key == ESC)
		exit(0);
	else if (key == RST)
	{
		ft_init();
		ft_print(ft_vp(G | 0, 0), ft_vp(G | 1, 0));
	}
	else if (ft_v(G | RENDER, 0) == 2
		&& (key == AKS || key == WKS || key == SKS || key == DKS))
	{
		if (key == AKS && (ft_vd(G | JULX, 0) - JULG) >= -2.f)
			ft_vd(S | JULX, ft_vd(G | JULX, 0) - JULG);
		else if (key == DKS && (ft_vd(G | JULX, 0) + JULG) <= 2.f)
			ft_vd(S | JULX, ft_vd(G | JULX, 0) + JULG);
		else if (key == WKS && (ft_vd(G | JULY, 0) + JULG) <= 2.f)
			ft_vd(S | JULY, ft_vd(G | JULY, 0) + JULG);
		else if (key == SKS && (ft_vd(G | JULY, 0) - JULG) >= -2.f)
			ft_vd(S | JULY, ft_vd(G | JULY, 0) - JULG);
		ft_print(ft_vp(G | 0, 0), ft_vp(G | 1, 0));
	}
	else if (key == LK || key == UK || key == DK || key == RK)
		ft_move(key);
	return (0);
}

int	ft_mouse(int button, int x, int y)
{
	float	z;

	if (button == SCUP || (button == SCDN && ft_v(G | Z, 0) > 0))
	{
		z = pow(ZGR, ft_v(G | Z, 0));
		ft_vd(S | X, ft_vd(G | X, 0) + (float)x / ((ft_v(G | WX, 0) / 4) * z));
		ft_vd(S | Y, ft_vd(G | Y, 0) - (float)y / ((ft_v(G | WY, 0) / 4) * z));
		if (button == SCUP)
			ft_v(S | Z, ft_v(G | Z, 0) + 1);
		else
			ft_v(S | Z, ft_v(G | Z, 0) - 1);
		z = pow(ZGR, ft_v(G | Z, 0));
		ft_vd(S | X, ft_vd(G | X, 0) - (float)x / ((ft_v(G | WX, 0) / 4) * z));
		ft_vd(S | Y, ft_vd(G | Y, 0) + (float)y / ((ft_v(G | WY, 0) / 4) * z));
		ft_print(ft_vp(G | 0, 0), ft_vp(G | 1, 0));
	}
	return (0);
}
