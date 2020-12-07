/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:35:12 by sakim             #+#    #+#             */
/*   Updated: 2020/12/08 01:10:38 by sakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			getin(char *s, char x)
{
	int		n;

	n = -1;
	if (x == '-' || x == '+')
		return (x == '-') ? (2) : (3);
	if (x == 32 || (x >= 9 && x <= 13))
		return (1);
	while (s != 0 && *(s + ++n))
		if (*(s + n) == x)
			return (4 + n);
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
		if (getin(0, *(b + x)))
			return (-1);
		while (*(b + x + ++y + 1))
			if (*(b + x) == *(b + x + y + 1))
				return (-1);
	}
	return (x);
}

int			re(char *b, int t, char *base, int size)
{
	return ((getin(base, *b) >= 4) ?
			re(b + 1, size * t + (getin(base, *b) - 4), base, size) : t);
}

int			ft_atoi(char *str, char *base, int size)
{
	int		c;
	char	*s;
	int		n;

	c = 0;
	s = str;
	while (*str)
	{
		c = getin(base, *str);
		c = (c >= 4) ? 4 : c;
		if (((!((n & 1) - 1) && c <= 1) || !c) || (!(c - 4) && *(s = str)))
			break ;
		if ((c >= 2) && (n |= 1)
				&& !(c - 2) && (n += (n & 2) ? -2 : +2))
		{
		}
		str++;
	}
	return (((n & 2) ? -1 : 1) * re(s, 0, base, size));
}

int			ft_atoi_base(char *str, char *base)
{
	int		size;

	size = check_ok(base);
	if (size < 1)
		return (0);
	return (ft_atoi(str, base, size));
}
