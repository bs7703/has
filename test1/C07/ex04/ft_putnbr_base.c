/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:13:54 by sakim             #+#    #+#             */
/*   Updated: 2020/12/08 19:15:28 by sakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		pa(int x)
{
	if (x >= 48 && x <= 57)
		return (1);
	if (x >= 65 && x <= 90)
		return (2);
	if (x >= 90 && x <= 122)
		return (3);
	return (0);
}

int		check_ok2(char *b)
{
	int	x;
	int	y;

	x = -1;
	while (*(b + ++x))
	{
		y = -1;
		if (pa(*(b + x)) == 0)
			return (-1);
		while (*(b + x + ++y + 1))
			if (*(b + x) == *(b + x + y + 1))
				return (-1);
	}
	return (x);
}

void	changebase(long nbr, int size, char *base)
{
	if (nbr > 0)
		changebase(nbr / size, size, base);
	write(1, base + nbr % size, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		size;
	long	data;

	data = nbr;
	size = check_ok2(base);
	if (size < 1)
		return ;
	if (data < 0 && (data *= -1))
		write(1, "-", 1);
	changebase(data, size, base);
}
