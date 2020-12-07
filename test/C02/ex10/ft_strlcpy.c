/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 19:23:54 by sakim             #+#    #+#             */
/*   Updated: 2020/12/06 12:34:09 by sakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				str_len(char *str)
{
	unsigned int	x;

	x = 0;
	while (*(str + x))
		x++;
	return (x);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	sizes;
	unsigned int	sizex;

	sizes = 0;
	sizex = str_len(src);
	while (++sizes < size && *src != 0)
		*(dest++) = *(src++);
	*dest = (size > 0) ? 0 : *dest;
	return (sizex);
}
