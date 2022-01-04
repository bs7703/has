/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_utils1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:36:14 by gimsang-w         #+#    #+#             */
/*   Updated: 2022/01/04 20:01:04 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	ft_usleep(t_list *tl)
{
	struct timeval	t2;
	struct timeval	t1;
	long			us;

	t1 = tl->t;
	us = tl->args[TTE] * 1000;
	while (1)
	{
		gettimeofday(&t2, 0);
		if (msec(t2, t1) >= us)
			break ;
		usleep(50);
	}
	++(tl->eat);
}

int	ft_print(char *str, t_list *tl, int state)
{
	int				re;
	struct timeval	t;

	re = 0;
	if (*(tl->died))
		return (1);
	gettimeofday(&t, 0);
	pthread_mutex_lock(tl->pnl);
	printf(str, msec(t, tl->stime) / 1000, tl->n);
	pthread_mutex_unlock(tl->pnl);
	if (state == SLEEP)
	{
		pthread_mutex_unlock(&tl->mt);
		pthread_mutex_unlock(&tl->next->mt);
		tl->fork = 0;
		tl->next->fork = 0;
		re = ft_sleep(tl, tl->args[TTS] * 1000);
	}
	else if (state == EAT)
	{
		tl->t.tv_usec = t.tv_usec;
		tl->t.tv_sec = t.tv_sec;
		ft_usleep(tl);
	}
	return (re);
}

int	thread_state(t_list *tl, int state)
{
	int				re;
	struct timeval	t;

	if (*(tl->died))
		return (1);
	if (state == THINK)
		re = ft_print("%ld %d is thinking\n", tl, state);
	else if (state == EAT)
		re = ft_print("%ld %d is eating\n", tl, state);
	else if (state == DIE)
	{
		*(tl->died) = 1;
		tl->sw = -1;
		gettimeofday(&t, 0);
		pthread_mutex_lock(tl->pnl);
		printf("%ld %d died\n", msec(t, tl->stime) / 1000, tl->n);
		pthread_mutex_unlock(tl->pnl);
		return (1);
	}
	else if (state == SLEEP)
	{
		re = ft_print("%ld %d is sleeping\n", tl, state);
		thread_state(tl, THINK);
	}
	return (re);
}

int	fork_lock(t_list *tl)
{
	struct timeval	t;
	long			time;

	if (*(tl->died))
		return (1);
	tl->fork = 1;
	tl->next->fork = 1;
	tl->sw = 1;
	if (tl->next->sw != -1)
		tl->next->sw = 0;
	pthread_mutex_lock(&tl->mt);
	pthread_mutex_lock(&tl->next->mt);
	gettimeofday(&t, 0);
	time = msec(t, tl->stime) / 1000;
	pthread_mutex_lock(tl->pnl);
	printf("%ld %d has taken a fork\n", time, tl->n);
	printf("%ld %d has taken a fork\n", time, tl->n);
	pthread_mutex_unlock(tl->pnl);
	return (0);
}

int	fork_unlock(t_list *tl)
{
	int				n;
	struct timeval	t;

	n = 0;
	if (tl->args[NOS] == tl->eat)
		n = 1;
	if (*(tl->died) == 0)
	{
		if (n == 0)
			thread_state(tl, SLEEP);
		else
		{
			gettimeofday(&t, 0);
			pthread_mutex_lock(tl->pnl);
			printf("%ld %d is sleeping\n", msec(t, tl->stime) / 1000, tl->n);
			pthread_mutex_unlock(tl->pnl);
			tl->fork = 0;
			tl->next->fork = 0;
			pthread_mutex_unlock(&tl->mt);
			pthread_mutex_unlock(&tl->next->mt);
		}
	}
	return (n);
}
