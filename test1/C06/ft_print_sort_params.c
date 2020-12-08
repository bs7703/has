/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_sort_params.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakim <sakim@student.42.kr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 00:36:38 by sakim             #+#    #+#             */
/*   Updated: 2020/12/08 00:38:24 by sakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int			ft_strcmp(char *s1, char *s2)
{
	int		x;

	x = 0;
	while (s1[x] && s1[x] == s2[x] && ++x)
	{
	}
	return ((unsigned char)s1[x] - (unsigned char)s2[x]);
}

int			ct(char **args, int a, int b)
{
	char	*temp;

	temp = args[a];
	args[a] = args[b];
	args[b] = temp;
	return (0);
}

void		b_s(char **args)
{
	int		j;
	int		g;
	int		i;

	i = -1;
	while ((j = -1) && args[++i + 1])
		while (args[++j + 1])
			g = (ft_strcmp(args[j], args[j + 1]) > 0) ?
				ct(args, j, j + 1) : 1;
}

int			main(int size, char **args)
{
	if (size < 2)
		return (0);
	b_s(args + 1);
	while (*(++args))
		while (**args || !(write(1, "\n", 1)))
			write(1, (*args)++, 1);
	return (0);
}
