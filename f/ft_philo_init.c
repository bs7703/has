/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:37:55 by gimsang-w         #+#    #+#             */
/*   Updated: 2022/01/04 19:52:30 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	ft_atoi(char *str)
{
	int	rs;
	int	n;

	n = 0;
	rs = 0;
	while (*str == 32)
		++str;
	if (*str == 43)
		++str;
	while (*str == 48)
		++str;
	while (*str)
	{
		if ((*str < 48 || *str > 57) && n == 0)
			return (-1);
		else if ((*str < 48 || *str > 57) && n != 0)
			return (rs);
		if (10 * rs + (*str - 48) < rs)
			return (-1);
		rs = 10 * rs + (*str++ - 48);
		++n;
	}
	return (rs);
}

void	*ft_return(t_list *tl)
{
	pthread_mutex_lock(tl->pn);
	++*(tl->sn);
	pthread_mutex_unlock(tl->pn);
	tl->sw = -1;
	return ((void *)0);
}

void	*run(void *val)
{
	t_list			*tl;
	int				re;

	tl = (t_list *)val;
	ft_return(tl);
	tl->sw = 1;
	while (*(tl->sn) < tl->args[N])
		usleep(1);
	gettimeofday(&tl->stime, 0);
	gettimeofday(&tl->t, 0);
	while (1)
	{
		re = 0;
		if (ft_hunger(tl))
			re = 1;
		if (fork_lock(tl))
			re = 1;
		if (thread_state(tl, EAT))
			re = 1;
		if (fork_unlock(tl))
			re = 1;
		if (re)
			return (ft_return(tl));
	}
	return (0);
}

t_list	*ft_init(int *sn, pthread_mutex_t *pn, int *died, int *args)
{
	int				n;
	t_list			*tl;
	pthread_mutex_t	*t;

	t = malloc(sizeof(pthread_mutex_t));
	tl = malloc(sizeof(t_list) * args[N]);
	n = -1;
	pthread_mutex_init(t, 0);
	while (++n < args[N])
	{
		tl[n].sn = sn;
		tl[n].pn = pn;
		tl[n].pnl = t;
		tl[n].n = n + 1;
		tl[n].sw = 1;
		tl[n].eat = 0;
		tl[n].next = tl + (n + 1) % args[N];
		tl[n].prv = tl + (args[N] + n - 1) % args[N];
		tl[n].died = died;
		tl[n].args = args;
		pthread_mutex_init(&tl[n].mt, 0);
	}
	return (tl);
}

void	fork_init(t_list *tl, int *args)
{
	int				n;
	int				died;
	pthread_t		*t;
	int				sn;
	pthread_mutex_t	pn;

	died = 0;
	sn = 0;
	n = -1;
	t = malloc(sizeof(pthread_t) * args[N]);
	pthread_mutex_init(&pn, 0);
	tl = ft_init(&sn, &pn, &died, args);
	while (++n < args[N])
	{
		pthread_create(t + n, 0, run, tl + n);
		pthread_detach(t[n]);
	}
	while (sn < args[N] * 2)
		usleep(100);
	free(tl);
	free(t);
	return ;
}
