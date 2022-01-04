/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 03:16:17 by gimsang-w         #+#    #+#             */
/*   Updated: 2022/01/04 19:09:07 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PHILO_H

# define FT_PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>

# define N 0
# define EAT 0
# define TTD 1
# define DIE 1
# define TTE 2
# define TTS 3
# define THINK 3
# define NOS 4
# define SLEEP 4

typedef struct s_list
{
	int				*died;
	int				*args;
	struct s_list	*next;
	struct s_list	*prv;
	pthread_mutex_t	mt;
	int				*plock;
	int				fork;
	int				*sn;
	int				hp;
	pthread_mutex_t	*pn;
	pthread_mutex_t	*pnl;
	struct timeval	t;
	struct timeval	stime;
	int				total;
	int				sw;
	int				n;
	int				eat;
}				t_list;

int		ft_atoi(char *args);
void	*ft_return(t_list *tl);
void	*run(void *val);
t_list	*ft_init(int *sn, pthread_mutex_t *pn, int *died, int *args);
void	fork_init(t_list *tl, int *args);
int		ft_atoi(char *str);
long	msec(struct timeval s1, struct timeval s2);
int		is_dead(t_list	*tl);
int		is_locked(t_list *tl);
int		ft_hunger(t_list *tl);
int		ft_sleep(t_list *tl, int us);
void	ft_usleep(t_list *tl);
int		ft_print(char *str, t_list *tl, int state);
int		thread_state(t_list *tl, int state);
int		fork_lock(t_list *tl);
int		fork_unlock(t_list *tl);
#endif
