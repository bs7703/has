/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 20:37:44 by sakim             #+#    #+#             */
/*   Updated: 2020/12/03 19:14:17 by sakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				str_len(char *data)
{
	int			x;

	x = 0;
	while (*(data + x))
		x++;
	return (x);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int			i;
	int			ss;
	int			ds;

	i = 0;
	ds = str_len(dest);
	ss = str_len(src);
	while (*src && size - 1 > ds + i)
		*(dest + ds + i)= *(src + i++);
	*(dest + ds + i) = 0;
	return (ds >= size) ? (ss + size) : (ds + ss);
}

