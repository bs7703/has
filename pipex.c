/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakim <sakim@student.seoul42.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 17:45:59 by sakim             #+#    #+#             */
/*   Updated: 2021/09/27 14:00:12 by sakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int n, char **args, char **env)
{
	int	status;

	if (n < 5)
		exit(0);
	while (n > 3)
	{
		ft_a(I | ONE, *(ft_a(FLAG | I | ZERO, 0)));
		ft_a(FDA | ONE, *(ft_a(FLAG | FD | ONE, 0)));
		if (n > 4)
			ft_exec2(PIPE, ft_a(FLAG | FD | ZERO, 0),
				FORK, ft_a(FLAG | I | ZERO, 0));
		if (*(ft_a(FLAG | I | ONE, 0)) == *(ft_a(FLAG | I | ZERO, 0)) && n != 4)
			ft_exec2(CLOSE, ft_a(FLAG | FD | ZERO, 0), MINUS, &n);
		else
		{
			ft_a(FDA | ZERO, *(ft_a(FLAG | FD | ZERO, 0)));
			if (n != 4)
				ft_exec2(CLOSE, ft_a(FLAG | FD | ONE, 0), WAIT, &status);
			ft_run(args, ft_a(FLAG | FDA | ZERO, 0), n, env);
			break ;
		}
	}
	return (SUCCESS);
}
