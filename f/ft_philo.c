/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 03:15:59 by gimsang-w         #+#    #+#             */
/*   Updated: 2022/01/04 19:01:47 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	main(int n, char **cargs)
{
	int		args[5];
	int		i;
	t_list	tl;

	i = -1;
	if (n < 5)
		return (0);
	while (++i < 5)
	{
		args[i] = ft_atoi(cargs[i + 1]);
		if (args[i] < 0)
			return (0);
		if (i == 3 && n == 5)
			break ;
	}
	if ((args[4] == 0 && n >= 6) || args[0] == 0)
		return (0);
	if (n == 5)
		args[4] = -1;
	fork_init(&tl, args);
}
