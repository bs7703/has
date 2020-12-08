/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 19:21:43 by sakim             #+#    #+#             */
/*   Updated: 2020/12/08 13:42:59 by sakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int					ft_is_prime(int nb)
{
	unsigned int	x;

	x = 1;
	if (nb <= 1)
		return (0);
	while (++x && x * x <= nb)
		if (nb % x == 0)
			return (0);
	return (1);
}

int					ft_find_next_prime(int nb)
{
	if (nb <= 1)
		return (2);
	while (!ft_is_prime(nb) && ++nb)
	{
	}
	return (nb);
}
