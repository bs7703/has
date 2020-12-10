/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tail.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 20:22:05 by sakim             #+#    #+#             */
/*   Updated: 2020/12/10 20:22:06 by sakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#include <string.h>

#include <unistd.h>

#define MAX 1000000

void		print_all(int fd)
{
	char	m[MAX];
	int		i;

	i = -1;
	read(fd, m, MAX);
	while (m[++i])
		write(1, &m[i], 1);
	close(fd);
}

void		str_print(char *a)
{
	while(a && *a)
		write(1, a++, 1);
}

int			main(int size, char **args)
{
	int		fd;

	if (size == 1)
		return (0);
	while (*(++args))
	{
		if ((fd = open(*args, O_RDONLY)) != -1)
			print_all(fd);
		else
			str_print(strerror(2));
	}
	return (0);
}
