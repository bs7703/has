/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 19:21:43 by sakim             #+#    #+#             */
/*   Updated: 2020/12/03 19:24:23 by sakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_prime(int nb)
{
	int		x;

	x = 1;
	while (++x && x * x <= nb)
		if (nb % x == 0)
			return (0);
	return ((nb <= 1) ? 0 : 1);
}

int		ft_find_next_prime(int nb)
{
	while (!ft_is_prime(nb) && ++nb);
	return (nb);
}
