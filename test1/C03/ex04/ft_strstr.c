/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 20:28:10 by sakim             #+#    #+#             */
/*   Updated: 2020/12/08 13:50:21 by sakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strstr(char *str, char *to_find)
{
	int		p;
	int		i;

	i = 0;
	if (!*to_find)
		return (str);
	while (str[i])
	{
		p = 0;
		while (str[i + p] == to_find[p])
		{
			p++;
			if (!to_find[p])
				return (str + i);
			if (!str[p + i])
				return (0);
		}
		i++;
	}
	return (0);
}
