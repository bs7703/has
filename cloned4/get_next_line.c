/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 17:28:54 by sakim             #+#    #+#             */
/*   Updated: 2021/12/17 02:41:59 by sakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_multiplecmd(int *a, int *b, int n)
{
	int		run;
	char	*rs;

	rs = 0;
	while (get_next_line(1, &rs) == 1)
	{
		run = ft_cmdset(rs);
		if (run < 1)
			return (-1);
		run = ft_cmd(a, b, run | REINVOKED, n - ft_cmd(a, b, 4096, 0));
		rs = 0;
	}
	run = ft_cmd(a, b, VAL, n - ft_cmd(a, b, 4096, 0));
	return (run);
}

int	get_next_line(int fd, char **line)
{
	static t_list	mylist;
	t_list			*crlist;

	crlist = &mylist;
	if (check(fd, crlist) || !line)
		return (ERR);
	while (linecheck(crlist))
	{
		crlist->current->next = malloc(sizeof(t_node));
		crlist->current = crlist->current->next;
		crlist->current->next = 0;
		crlist->current->size = read(fd, crlist->current->data, BUFFER_SIZE);
		if (crlist->current->size == ERR)
		{
			clean(crlist);
			return (ERR);
		}
		else if (crlist->current->size == EOFF)
			break ;
	}
	return (lnk(crlist, line));
}
