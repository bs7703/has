/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 16:59:31 by sakim             #+#    #+#             */
/*   Updated: 2020/12/06 15:51:10 by sakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	z;

	z = -1;
	while (*(str + ++z))
		*(str + z) -= ((*(str + z) >= 97) && (*(str + z) <= 122)) ? 32 : 0;
	return (str);
}
