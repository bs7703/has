/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 20:25:14 by sakim             #+#    #+#             */
/*   Updated: 2020/12/03 17:43:49 by sakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char *result;

	result = dest;
	while (*dest)
		dest++;
	while (*src && (nb-- > 0))
		*(dest++) = *(src++);
	*dest = 0;
	return (result);
}
