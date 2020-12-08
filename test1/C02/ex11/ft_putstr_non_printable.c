/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 19:41:10 by sakim             #+#    #+#             */
/*   Updated: 2020/12/03 16:13:53 by sakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		printable(char c)
{
	if (c > 31 && c < 127)
		return (1);
	return (0);
}

char	geth(char c)
{
	return (c + ((c < 10) ? 48 : 87));
}

void	print_special(char *c)
{
	char	x;

	if (!printable(*c))
	{
		write(1, "\\", 1);
		x = geth((*c >> 4) & 15);
		write(1, &x, 1);
		x = geth((*c) & 15);
		write(1, &x, 1);
	}
	else
		write(1, c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
		print_special(str++);
}
