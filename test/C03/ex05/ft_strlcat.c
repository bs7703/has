/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 13:20:24 by sakim             #+#    #+#             */
/*   Updated: 2020/12/06 20:44:31 by sakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int		str_len(char *data)
{
	unsigned int	x;

	x = 0;
	while (*(data + x))
		x++;
	return (x);
}

unsigned int		ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	ss;
	unsigned int	ds;

	i = 0;
	ds = str_len(dest);
	ss = str_len(src);
	while ((size > ds + i + 1) && *(src + i))
	{
		*(dest + ds + i) = *(src + i);
		i++;
	}
	*(dest + ds + i) = 0;
	return (ds >= size) ? (ss + size) : (ds + ss);
}
