/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakim <sakim@student.42.kr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 01:01:22 by sakim             #+#    #+#             */
/*   Updated: 2020/12/08 19:25:08 by sakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			check_in(char str)
{
	if ((str >= 48 && str <= 57) || (str >= 9 && str <= 13) || str == 32)
		return ((str >= 48) ? 2 : 1);
	else if (str == '-' || str == '+')
		return ((str == '-') ? 3 : 4);
	return (0);
}

int			re(char *b, int t)
{
	return ((check_in(*b + 1) == 2) ?
			re(b + 1, *(b) - 48 + t * 10) : t);
}

int			ft_atoi(char *str)
{
	int		c;
	char	*s;
	int		n;

	n = 0;
	s = str;
	while (*str)
	{
		c = check_in(*str);
		if (((!((n & 1) - 1) && c <= 1) || !c) || (!(c - 2) && *(s = str)))
			break ;
		if ((c > 2) && (n |= 1)
				&& !(c - 3) && (n += (n & 2) ? -2 : +2))
		{
		}
		str++;
	}
	return (((n & 2) ? -1 : 1) * re(s, 0));
}
