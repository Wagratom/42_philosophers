/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:46:30 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/26 17:58:58 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

typedef	struct s_philo
{
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				posi_table;
	int				times;
	pthread_mutex_t		forks[2];
}	t_philo;

typedef struct s_table
{
	pthread_mutex_t		*forks;
	pthread_t			*threads;
	t_philo				*philo;
	int					number_philo;
}	t_table;

typedef	void *(*start_th)(void *);

t_bool			valid_argv(int argc, char **argv);

t_table			*creat_table(char *argv[]);

t_philo 		*creat_philos(t_table **table, char	*argv[]);

pthread_mutex_t	*creat_forks(int nbr_forks);

void			*start_philo(void *philo);

void			init_philosophers(t_table **table);

void			creat_threads(t_table **table, int nbr_th);

t_bool			philo_eat(t_table *table);

void			destroy_table(t_table **table);

void			*routinee(void	*print_me);
void			*start_thread(void	*table);

# define MAX_THREAD 32768
#endif
