/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 16:53:31 by sakim             #+#    #+#             */
/*   Updated: 2020/12/06 12:59:57 by sakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_numeric(char *str)
{
	char	z;
	int		y;

	y = -1;
	while ((z = *(str + ++y)))
		if (!((z >= 48) && (z <= 57)))
			return (0);
	return (1);
}
