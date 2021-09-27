/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_mem_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakim <sakim@student.seoul42.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 09:55:07 by sakim             #+#    #+#             */
/*   Updated: 2021/09/27 13:57:43 by sakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_freeall(char **args, int offset)
{
	if (!args || !*(args + offset))
		return ;
	while (*(args + offset))
	{
		free(args + offset);
		++args;
	}
	free(args);
}

int	ft_len(void **p)
{
	int	i;

	i = 0;
	if (!p)
		return (-1);
	if (!(long)*p)
		return (i);
	while ((long)*(p + i))
		++i;
	return (i);
}

int	*ft_a(int i, int set)
{
	static int	val[3][2];

	if (i & FLAG)
		return (*(val + (i & FIRST)) + ((i & SECOND) >> 2));
	else
		*(*(val + (i & FIRST)) + ((i & SECOND) >> 2)) = set;
	return (SUCCESS);
}

void	ft_exec(int cmd1, int *val)
{
	if (cmd1 == PIPE)
	{
		if (pipe(val) != 0)
			ft_exit(-1);
	}
	else if (cmd1 == FORK)
	{
		*val = fork();
		if (*val == -1)
			ft_exit(-1);
	}
	else if (cmd1 == MINUS)
		*val = *val - 1;
	else if (cmd1 == CLOSE)
		close(*val);
	else if (cmd1 == WAIT)
		wait(val);
}

void	ft_exec2(int cmd1, int *val1, int cmd2, int *val2)
{
	ft_exec(cmd1, val1);
	ft_exec(cmd2, val2);
}
