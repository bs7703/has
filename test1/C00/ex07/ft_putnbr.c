/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 19:50:05 by sakim             #+#    #+#             */
/*   Updated: 2020/11/26 21:37:14 by sakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbc(int nb)
{
	char	c;
	long	d;

	if (nb == 0)
		return ;
	d = nb;
	if (nb < 0)
	{
		c = '-';
		write(1, &c, 1);
		d = d * -1;
	}
	c = '0' + d % 10;
	ft_putnbc((int)(d / 10));
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	char	c;

	c = '0';
	if (nb == 0)
		write(1, &c, 1);
	else
		ft_putnbc(nb);
}
