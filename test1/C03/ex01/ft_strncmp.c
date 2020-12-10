/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakim <sakim@student.42.kr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 18:42:57 by sakim             #+#    #+#             */
/*   Updated: 2020/12/10 18:58:32 by sakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	if (!n)
		return (0);
	while (*s1 && (*(s1) == *(s2))
			&& (n-- > 1) && (*(s1++) && *(s2++)))
	{
	}
	return ((char)((unsigned char)*s1 - (unsigned char)*s2));
}
