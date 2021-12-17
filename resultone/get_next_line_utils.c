/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 20:59:15 by sakim             #+#    #+#             */
/*   Updated: 2021/12/17 22:01:16 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	check(int fd, t_list *mylist)
{
	if ((mylist->ocp == UNOCP) && ((
				mylist->fd == (fd + 1)) || (mylist->fd == 0)))
	{
		mylist->size = 0;
		mylist->origin.next = 0;
		if (mylist->origin.size == 0)
		{
			mylist->origin.size = read(fd,
					mylist->origin.data, BUFFER_SIZE);
			if (mylist->origin.size == ERR)
				return (TRUE);
		}
		mylist->ocp = OCP;
		mylist->fd = fd + 1;
		mylist->current = &(mylist->origin);
		return (FALSE);
	}
	return (TRUE);
}

int	linecheck(t_list *mylist)
{
	register int	i;

	i = -1;
	while (++i < mylist->current->size)
		if (*(mylist->current->data + i) == DEL)
			break ;
	mylist->size += i;
	if (i < mylist->current->size)
		return (FALSE);
	return (TRUE);
}

int	setlist(t_list *mylist, int size, int off)
{
	int				sign;
	register int	i;

	i = -1;
	if (size == mylist->size)
		sign = EOFF;
	else
		sign = READ;
	size = mylist->current->size - (off + 1);
	while (++off < (mylist->current->size))
		*(mylist->origin.data + ++i) = *(mylist->current->data + off);
	if (size < 0)
		mylist->origin.size = 0;
	else
		mylist->origin.size = size;
	return (sign);
}

void	clean(t_list *mylist)
{
	t_node			*dot;
	t_node			*prev;

	dot = &(mylist->origin);
	dot = dot->next;
	while (dot)
	{
		prev = dot;
		dot = dot->next;
		free(prev);
	}
}

int	lnk(t_list *mylist, char **line)
{
	register int	i;
	int				sign;
	int				size;
	t_node			*dot;

	size = 0;
	dot = &(mylist->origin);
	line[0] = malloc(sizeof(char) * (mylist->size + 1));
	line[0][mylist->size] = 0;
	while (dot)
	{
		i = -1;
		while ((++i < dot->size) && ((size + i) < mylist->size))
			*(*line + size + i) = *(dot->data + i);
		size += dot->size;
		dot = dot->next;
	}
	sign = setlist(mylist, size, i);
	clean(mylist);
	mylist->ocp = UNOCP;
	if (sign == 0)
		mylist->fd = 0;
	return (sign);
}
