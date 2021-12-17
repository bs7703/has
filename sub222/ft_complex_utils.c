/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:29:55 by gimsang-w         #+#    #+#             */
/*   Updated: 2021/12/17 19:06:00 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	ft_m(t_comp *x, t_comp y)
{
	float	a;
	float	b;

	a = x->real * y.real - x->img * y.img;
	b = x->real * y.img + x->img * y.real;
	x->real = a;
	x->img = b;
}

void	ft_d(t_comp *x, t_comp y)
{
	float	a;
	float	b;

	a = x->real * y.real + x->img * y.img;
	b = x->img * y.real - x->real * y.img;
	x->real = a / (y.real * y.real - y.img * y.img);
	x->img = b / (y.real * y.real - y.img * y.img);
}

float	ft_function(t_comp *x, int n)
{
	t_comp	a;
	t_comp	b;
	int		i;

	if (n == 0)
		n = 1;
	i = n;
	a.real = x->real;
	a.img = x->img;
	b.real = x->real;
	b.img = x->img;
	while (--n >= 0)
		ft_m(&a, *x);
	b.real = a.real;
	b.img = a.img;
	ft_m(&a, *x);
	b.real *= i + 1;
	b.img *= i + 1;
	a.real -= 1;
	ft_d(&a, b);
	x->real -= a.real;
	x->img -= a.img;
	return (sqrt(a.real * a.real + a.img * a.img));
}
