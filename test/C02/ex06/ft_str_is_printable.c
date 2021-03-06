/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 16:58:15 by sakim             #+#    #+#             */
/*   Updated: 2020/12/06 13:00:45 by sakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_printable(char *str)
{
	char	z;
	int		y;

	y = -1;
	while ((z = *(str + ++y)))
		if ((z < 32) || (z == 127))
			return (0);
	return (1);
}
