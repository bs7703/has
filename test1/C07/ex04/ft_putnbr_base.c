/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:13:54 by sakim             #+#    #+#             */
/*   Updated: 2020/12/10 18:57:13 by sakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			pa(int x)
{
	if (x >= 48 && x <= 57)
		return (1);
	if (x >= 65 && x <= 90)
		return (2);
	if (x >= 90 && x <= 122)
		return (3);
	return (0);
}

int			check_ok(char *b)
{
	int		x;
	int		y;

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

void		changebase(long nbr, int *size, char *base, char *result)
{
	if (nbr > 0)
	{
		size[1]--;
		changebase(nbr / size[0], size, base, result);
		size[1]++;
		result[size[1] - 1] = base[nbr % size[0]];
	}
	return ;
}

char		*ft_convert_base2(int nbr, char *base)
{
	int		size[2];
	long	data;
	char	*result;

	size[1] = 1;
	if ((size[0] = check_ok(base)) < 1)
		return (0);
	data = nbr / size[0];
	while (data && ++size[1])
		data /= size[0];
	data = nbr;
	data = (data < 0) ? -data : data;
	if (!(result = (char *)malloc(sizeof(char *) * (size[1] +
				((nbr < 0) ? 2 : 1)))))
		return (0);
	if (nbr < 0)
		*(result++) = '-';
	result[size[1]] = 0;
	changebase(data, size, base, result);
	return (result + ((nbr < 0) ? -1 : 0));
}
