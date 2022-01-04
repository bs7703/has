/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_utils0.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:32:25 by gimsang-w         #+#    #+#             */
/*   Updated: 2022/01/04 20:00:58 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

long	msec(struct timeval s1, struct timeval s2)
{
	return ((s1.tv_sec - s2.tv_sec) * 1000 * 1000 + (
			s1.tv_usec - s2.tv_usec));
}

int	is_dead(t_list	*tl)
{
	struct timeval	t;
	long			s;
	long			n;

	if (tl->eat == tl->args[NOS])
		return (0);
	gettimeofday(&t, 0);
	n = (tl->args[TTD] - tl->args[TTE]) * 1000;
	s = msec(t, tl->t);
	if (s >= (n - 200))
		return (1);
	return (0);
}

int	is_locked(t_list *tl)
{
	if (tl->next == tl || is_dead(tl->next) || is_dead(tl->prv))
		return (1);
	if (tl->next)
		return (tl->fork + tl->next->fork);
	return (1);
}

int	ft_hunger(t_list *tl)
{
	struct timeval	t;

	while (is_locked(tl) != 0)
	{
		if (*(tl->died))
			return (1);
		gettimeofday(&t, 0);
		if (msec(t, tl->t) >= tl->args[TTD] * 1000)
		{
			thread_state(tl, DIE);
			return (1);
		}
		usleep(50);
	}
	return (0);
}

int	ft_sleep(t_list *tl, int us)
{
	struct timeval	t2;
	struct timeval	t1;

	gettimeofday(&t1, 0);
	while (1)
	{
		gettimeofday(&t2, 0);
		if (msec(t2, tl->t) >= tl->args[TTD] * 1000)
			thread_state(tl, DIE);
		if (*(tl->died))
			return (1);
		if ((msec(t2, t1) >= us))
			break ;
		usleep(50);
	}
	return (0);
}
