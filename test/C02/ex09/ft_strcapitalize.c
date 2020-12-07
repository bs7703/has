/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 17:08:16 by sakim             #+#    #+#             */
/*   Updated: 2020/12/03 16:24:30 by sakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		checkin(char s)
{
	if ((s >= 'A') && (s <= 'Z'))
		return (1);
	if ((s >= 'a') && (s <= 'z'))
		return (2);
	if ((s >= '0') && (s <= '9'))
		return (3);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int		data;
	char	*r;

	r = str;
	while (*str)
	{
		data = (data & 4) + checkin(*str);
		if ((data & 4) && ((data & 3) == 1))
			*str += 32;
		else if (!(data & 4) && (data |= 4) && ((data & 3) == 2))
			*str -= 32;
		else if (data == 4)
			data = 0;
		str++;
	}
	return (r);
}
