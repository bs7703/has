/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_run_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakim <sakim@student.seoul42.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 09:57:52 by sakim             #+#    #+#             */
/*   Updated: 2021/09/27 16:26:55 by sakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_fileopen(char *filename, int mode)
{
	int	fd;

	if (mode == 0)
	{
		if (access(filename, R_OK))
			ft_exit(-1);
		fd = open(filename, O_RDONLY);
		if (fd == -1)
			ft_exit(-1);
	}
	else
	{
		if (access(filename, F_OK))
			fd = open(filename, O_CREAT | O_WRONLY, 0777);
		else
		{
			if (access(filename, W_OK))
				ft_exit(0);
			fd = open(filename, O_TRUNC | O_WRONLY);
		}
		if (fd == -1)
			ft_exit(0);
	}
	return (fd);
}

void	ft_cmd(char *args, int fd1, int fd2, char **env)
{	
	char	**arvs;
	char	**list;
	char	*tmp;

	if (dup2(fd1, 0) < 0 || dup2(fd2, 1) < 0)
		ft_exit(-1);
	close(fd1);
	close(fd2);
	arvs = ft_split(args, ' ');
	list = ft_getbinlist(env);
	tmp = arvs[0];
	arvs[0] = ft_checkcmd(arvs[0], list);
	execve(arvs[0], arvs, env);
	if (tmp != arvs[0])
		free(tmp);
	ft_freeall(list, 0);
	ft_freeall(arvs, 0);
}

void	ft_run(char **args, int *fd, int n, char **env)
{
	if (n == ft_len((void *)args))
		ft_cmd(args[n - 2], fd[0],
			ft_fileopen(args[ft_len((void *)args) - 1], 1), env);
	else if (n == 4)
		ft_cmd(args[2], ft_fileopen(args[1], 0), fd[1], env);
	else
		ft_cmd(args[n - 2], fd[0], fd[1], env);
}
