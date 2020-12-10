/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 19:31:35 by sakim             #+#    #+#             */
/*   Updated: 2020/12/10 20:15:16 by sakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ERRNO1 "File name missing.\n"

#define ERRNO2 "Too many arguments.\n"

#define ERRNO3 "Cannot read file.\n"

#include <fcntl.h>

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
}

int			main(int size, char **args)
{
	int	fd;

	if (size == 1)
		write(1, ERRNO1, 18);
	else if (size != 2)
		write(1, ERRNO2, 18);
	else
	{
		if ((fd = open(*args, O_RDONLY)) == -1)
			{
				write(1, ERRNO3, 16);
				return (0);
			}
		print_all(fd);
		close(fd);
	}
	return (0);
}
