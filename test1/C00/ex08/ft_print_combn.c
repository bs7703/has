/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 17:50:08 by sakim             #+#    #+#             */
/*   Updated: 2020/11/26 18:06:19 by sakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char *c, int size)
{
	char	a[2];

	a[0] = ',';
	a[1] = ' ';
	write(1, c, size);
	if (c[0] != '9' - size + 1)
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

void	ft_print_combn(int n)
{
	char	a[n];
	int		z;

	z = 0;
	while (z < n)
	{
		a[z] = '0' + z;
		z++;
	}
	ft_print(a, n);
}
