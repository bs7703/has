/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 19:33:37 by sakim             #+#    #+#             */
/*   Updated: 2020/12/08 13:26:47 by sakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int					ft_is_prime(int nb)
{
	unsigned int	x;

	x = 1;
	while (++x && x * x <= nb)
		if (nb % x == 0)
			return (0);
	return ((nb <= 1) ? 0 : 1);
}
