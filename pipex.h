/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakim <sakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 13:57:27 by sakim             #+#    #+#             */
/*   Updated: 2021/09/27 13:57:32 by sakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <sys/wait.h>

# define FLAG 16
# define FIRST 3
# define SECOND 12
# define I 0
# define FD 1
# define FDA 2
# define ZERO 0
# define ONE 4
# define WAIT -1
# define CLOSE -2
# define PIPE -3
# define FORK -4
# define MINUS -5
# define SUCCESS 0

int		*ft_a(int i, int set);
void	ft_exec(int cmd1, int *val);
void	ft_exec2(int cmd1, int *val1, int cmd2, int *val2);
char	*ft_trim(const char *str1, char alph);
char	*ft_strcpy(char *str, int size);
char	**ft_split(char *str, char deli);
char	*ft_checkcmd(const char *cmd, char **list);
char	*ft_join(const char *str1, const char *str2);
int		ft_len(void **p);
void	ft_cmd(char *args, int fd1, int fd2, char **env);
int		ft_strlen(char *str, char deli);
void	ft_run(char **args, int *fd, int n, char **env);
void	ft_freeall(char **str, int offset);
int		ft_strstr(char *str, const char *tofind);
char	**ft_getbinlist(char **envs);
void	ft_exit(int num);
int		ft_fileopen(char *filename, int mode);
int		ft_splitsize(char *str, char deli);
#endif
