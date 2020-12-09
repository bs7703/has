/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakim <sakim@student.42.kr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 00:56:24 by sakim             #+#    #+#             */
/*   Updated: 2020/12/09 22:00:51 by sakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define MAX 9

int			ff(char *b, int d, int n)
{
	while (++n < d + 1)
		if (*(b + d - n) - n == *(b + d) || *(b + d - n) + n == *(b + d)
				|| *(b + d - n) == *(b + d))
			return (0);
	return (1);
}

int			printall(char *s)
{
	while (*s)
		write(1, s++, 1);
	write(1, "\n", 1);
	return (1);
}

int			ca(int d, char *s, int r)
{
	while (d <= MAX && ++*(s + d) <= 57)
		if (ff(s, d, 0))
			r = r + ((d == MAX) ? printall(s) : ca(d + 1, s, 0));
	return ((*(s + d) = 47) + r - 47);
}

int			ft_ten_queens_puzzle(void)
{
	char	start[MAX + 2];
	int		i;

	i = -1;
	while (++i < MAX + 2)
		start[i] = (i == MAX + 1) ? 0 : 47;
	return (ca(0, start, 0));
}
