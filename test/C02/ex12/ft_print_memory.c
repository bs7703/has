/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:06:49 by sakim             #+#    #+#             */
/*   Updated: 2020/12/08 01:14:35 by sakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char				th(char x)
{
	return (x + ((x < 10) ? 48 : 87));
}

void				print_memory(char *addr)
{
	unsigned long	a;
	int				x;
	char			t;

	x = -1;
	a = (unsigned long)addr;
	while (++x < 16)
	{
		t = th((char)((a >> (60 - 4 * x)) & 15));
		write(1, &t, 1);
	}
	write(1, ": ", 2);
}

void				print_contenthex(char *addr, int size)
{
	int				i;
	char			c;

	i = -1;
	while (++i < size)
	{
		c = th((*(addr + i) >> 4) & 15);
		write(1, &c, 1);
		c = th((*(addr + i) & 15));
		write(1, &c, 1);
		if (i % 2 == 1)
			write(1, " ", 1);
	}
	while (i < 16)
		write(1, " ", (i++ % 2 == 1) ? 2 : 1);
}

int					print_content(char *addr, int size)
{
	int				i;
	int				cond;

	i = -1;
	while (++i < 16 - size || ((i = -1) + 1))
		write(1, " ", 1);
	while (++i < size)
	{
		cond = (*(addr + i) > 31 && *(addr + i) < 127);
		if (cond)
			write(1, addr + i, 1);
		else
			write(1, ".", 1);
	}
	return (0);
}

void				*ft_print_memory(void *addr, unsigned int size)
{
	char			*a;
	unsigned int	i;

	i = 0;
	a = (char *)addr;
	while (i < size)
	{
		print_memory(a + i);
		print_contenthex(a + i, (size < 16 + i) ? size - i : 16);
		print_content(a + i, (size < 16 + i) ? size - i : 16);
		write(1, "\n", 1);
		i += 16;
	}
	return (addr);
}
