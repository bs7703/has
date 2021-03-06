/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 19:32:48 by sakim             #+#    #+#             */
/*   Updated: 2020/12/10 13:06:48 by sakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb <= 0)
		return (nb == 0) ? 1 : 0;
	return ((nb > 1) ? ft_iterative_factorial(nb - 1) * nb : nb);
}
