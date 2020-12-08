/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 19:30:36 by sakim             #+#    #+#             */
/*   Updated: 2020/12/03 19:32:55 by sakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int i)
{
	if (i < 0)
		return (-1);
	return ((i > 1) ? ft_fibonacci(i - 1) +
		ft_fibonacci(i - 2) : (((i + 1) / 2) | 1));
}