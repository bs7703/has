/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 19:19:58 by sakim             #+#    #+#             */
/*   Updated: 2020/12/08 13:26:05 by sakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int					ft_sqrt(int nb)
{
	unsigned int	x;

	x = 1;
	while ((x * x) < nb && ++x)
	{
	}
	return (nb == x * x) ? x : 0;
}
