/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 13:54:29 by sakim             #+#    #+#             */
/*   Updated: 2020/12/10 19:04:42 by sakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putnbc(int nb)
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

void		ft_putnbr(int nb)
{
	char	c;

	c = '0';
	if (nb == 0)
		write(1, &c, 1);
	else
		ft_putnbc(nb);
}

void		ft_putstr(char *str)
{
	int		z;

	z = -1;
	while (*(str + ++z) != '\0')
		write(1, (str + z), 1);
	return ;
}

void		ft_show_tab(struct s_stock_str *par)
{
	while (par->str)
	{
		ft_putstr(par->str);
		write(1, "\n", 1);
		ft_putnbr(par->size);
		write(1, "\n", 1);
		ft_putstr(par++->copy);
		write(1, "\n", 1);
	}
}
