/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 21:36:42 by gimsang-w         #+#    #+#             */
/*   Updated: 2021/12/17 19:02:04 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	ft_printf(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_printerr(void)
{
	ft_printf("choose correct fractal set\n");
	ft_printf("1.type mandelbrot or 1 or mandel to see mandelbrot fractal\n");
	ft_printf("2.type julia or 2 to see julia fractal\n");
	exit(0);
}

int	ft_strstr(char *to, char *find)
{
	int	i;

	while (*to && (*to == *find))
	{
		++to;
		++find;
		if (!*to && !*find)
			return (1);
	}
	return (0);
}

int	ft_decide(char *str, int type)
{
	if (type == 0)
	{
		if (ft_strstr(str, "julia") || ft_strstr(str, "2"))
			return (2);
		else if (ft_strstr(str, "mandelbrot")
			|| ft_strstr(str, "1") || ft_strstr(str, "mandel"))
			return (1);
		else if (ft_strstr(str, "newton") || ft_strstr(str, "3"))
			return (3);
	}
	else
	{
		if (ft_strstr(str, "one") || ft_strstr(str, "1"))
			return (1);
		if (ft_strstr(str, "two") || ft_strstr(str, "2"))
			return (2);
		if (ft_strstr(str, "three") || ft_strstr(str, "3"))
			return (3);
		if (ft_strstr(str, "four") || ft_strstr(str, "4"))
			return (4);
	}
	return (0);
}

void	ft_instruct(void)
{
	ft_printf("-----common instructions-----\n");
	ft_printf("1.scroll-down = zoom-up, scroll-up = zoom-down\n");
	ft_printf("2.press p to reset page and press\n");
	ft_printf("3.use direction keys to move up down and left right\n");
	if (ft_v(G | RENDER, 0) == 1)
		ft_printf("1.you choose mandelbrot\n");
	if (ft_v(G | RENDER, 0) == 2)
	{
		ft_printf("2.you choose julia use AWSD keys to change juliaset\n");
		ft_printf("you can type one to four(1-4) after julia\n");
		ft_printf("WKEY = yvalue 0.01up, SKEY = yvalue 0.01down\n");
		ft_printf("AKEY = xvalue 0.01 down DKEY = xvalue 0.01up\n");
	}
	if (ft_v(G | RENDER, 0) == 3)
	{
		ft_printf("3.you choose newtonset.\n");
		ft_printf("newton set is based on newton method.\n");
		ft_printf("newton set has four types press 1 to 4.\n");
	}
}
