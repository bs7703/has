/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:06:49 by sakim             #+#    #+#             */
/*   Updated: 2020/12/03 19:05:16 by sakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char				th(char x)
{
	return (x + ((x < 10) ? 48 : 87));
}

void				print_memory(char *addr)
{
	long			a;
	int				x;
	char			t;

	x = -1;
	a = (long)addr;
	while (++x < 16)
	{
		t = th((char)((a >> (60 - 4 * x)) & 15));
		write(1, &t, 1);
	}
	write(1, ": ", 2);
}

void				print_contenthex(char *addr)
{
	int				i;
	char			c;

	i = -1;
	while (++i < 16)
	{
		c = th((*(addr + i) >> 4) & 15);
		write(1, &c, 1);
		c = th((*(addr + i) & 15));
		write(1, &c, 1);
		if (i % 2 == 1)
			write(1, " ", 1);
		if (!*(addr + i))
			break ;
	}
}

void				print_content(char *addr)
{
	int				i;
	int				z;
	int				cond;

	i = 0;
	while (*(addr + i) && i < 16)
		i++;
	z = 15 - i;
	i = -1;
	while (++i < z)
		write(1, " ", 1);
	i = -1;
	while (++i < 16)
	{
		cond = (*(addr + i) > 31 && *(addr + i) < 127);
		if (cond)
			write(1, addr + i, 1);
		else
			write(1, ".", 1);
		if (*(addr + i) == 0)
			break ;
	}
}

void				*ft_print_memory(void *addr, unsigned int size)
{
	char			**add;
	unsigned int	index;

	index = -1;
	add = (char **)addr;
	while (++index < size)
	{
		print_memory(*(add));
		print_contenthex(*(add));
		print_content(*(add++));
		write(1, "\n", 1);
	}
	return (addr);
}
