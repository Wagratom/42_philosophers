/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:46:38 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/03 12:31:21 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	settime(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000 + time.tv_usec / 1000) - time_init());
}

void	status_death(int time, int time_die)
{
	if (time > time_die)
		printf("philophers die\n");
}

void	*start_philo(void *_philo)
{
	t_philo			*philo;
	int				time;

	philo = (t_philo *)_philo;
	time = philo->die;
	while(philo->times--)
	{
		printf("%d %d is thinking\n", settime(), philo->position);
		pthread_mutex_lock(philo->fork1);
		pthread_mutex_lock(philo->fork2);
		status_death(settime(), time);
		printf("%d %d is eating\n", settime(), philo->position);
		usleep((philo->eat * 1000));
		pthread_mutex_unlock(philo->fork1);
		pthread_mutex_unlock(philo->fork2);
		status_death(settime(), time);
		printf("%d %d is sleeping\n", settime(), philo->position);
		usleep(philo->sleep);
		status_death(settime(), time);
		time = settime() + philo->die;
	}
}

void	init_th(pthread_t *thread, t_start func, void *argument)
{
	if (pthread_create(thread, NULL, func, argument) != 0)
		printf("Error creating thread\n");
}

void	init_ths(t_table **table)
{
	int		index;

	index = -1;
	while(++index < (*table)->nbr_philo)
		init_th(&(*table)->threads[index], &start_philo, &(*table)->philos[index]);
	index = -1;
	while(++index < (*table)->nbr_philo)
		pthread_join((*table)->threads[index], NULL);
	index = -1;
	while(++index < (*table)->nbr_philo)
		pthread_mutex_destroy(&(*table)->forks[index]);
}

