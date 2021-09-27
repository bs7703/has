/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakim <sakim@student.seoul42.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 22:41:20 by sakim             #+#    #+#             */
/*   Updated: 2021/09/27 13:58:12 by sakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strstr(char *str, const char *tofind)
{
	int	i;
	int	n;

	i = 0;
	while (*(str + i))
	{
		n = 0;
		while (*(str + i + n) == *(tofind + n))
		{
			if (!*(tofind + n + 1))
				return (i);
			++n;
		}
		++i;
	}
	return (-1);
}

void	ft_exit(int num)
{
	perror("\033[031mERROR");
	exit(num);
}

char	**ft_getbinlist(char **envs)
{
	int		i;
	char	*path;
	char	**rs;

	i = -1;
	while (*(envs + ++i))
	{
		if (ft_strstr(*(envs + i), "PATH") == 0)
		{
			rs = ft_split(*(envs + i), '=');
			free(rs[0]);
			path = rs[1];
			rs = ft_split(path, ':');
			free (path);
			return (rs);
		}
	}
	perror("ENV_PATH_ERROR");
	exit(-1);
	return (0);
}

char	*ft_checkcmd(const char *cmd, char **list)
{
	char		*tmp;
	char		*path;

	if (!cmd || !*cmd || !list)
		return (0);
	while (*list)
	{
		tmp = ft_join((const char *)*list, "/");
		path = ft_join((const char *)tmp, cmd);
		free(tmp);
		tmp = 0;
		if (!access((const char *)path, X_OK) || !*(list + 1))
			return (path);
		free(path);
		++list;
	}
	return (path);
}
