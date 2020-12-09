/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 18:39:37 by sakim             #+#    #+#             */
/*   Updated: 2020/11/26 16:22:40 by sakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(int a, int b)
{
	char	c[2];
	char	x[2];
	char	y[2];

	c[0] = ',';
	c[1] = ' ';
	x[1] = '0' + (a % 10);
	x[0] = '0' + (a / 10);
	y[0] = '0' + (b / 10);
	y[1] = '0' + (b % 10);
	write(1, x, 2);
	write(1, &c[1], 1);
	write(1, y, 2);
	if (a != 98)
		write(1, c, 2);
}

void	count_numb(int a, int b)
{
	while (a < 98)
	{
		b++;
		if (b > 99)
		{
			a++;
			b = a + 1;
		}
		print(a, b);
	}
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	count_numb(a, b);
}
