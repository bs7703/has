/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 17:50:08 by sakim             #+#    #+#             */
/*   Updated: 2020/11/26 16:14:16 by sakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char *c, int size)
{
	char a[2];

	a[0] = ',';
	a[1] = ' ';
	write(1, c, size);
	if (c[0] == '7')
		return ;
	else
		write(1, a, 2);
}

void	ft_print(char *c, int size)
{
	int		z;

	z = 0;
	while (0 == 0)
	{
		print(c, size);
		c[size - z - 1] = c[size - z - 1] + 1;
		while (c[size - z - 1] == '9' - z + 1)
		{
			z++;
			if (size - z - 1 < 0)
				return ;
			c[size - z - 1] = c[size - z - 1] + 1;
		}
		while (z > 0)
		{
			z--;
			c[size - z - 1] = c[size - z - 2] + 1;
		}
	}
}

void	ft_print_comb(void)
{
	char	a[3];
	int		size;

	size = 3;
	a[0] = '0';
	a[1] = '1';
	a[2] = '2';
	ft_print(a, size);
}
