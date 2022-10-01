/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:46:38 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/30 22:35:29 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	*start_philo(void *_philo)
{
	t_philo		*philo;

	philo = (t_philo *)_philo;
	while(philo->times--)
	{
		pthread_mutex_lock(philo->fork1);
		pthread_mutex_lock(philo->fork2);
		printf("philosophers %d  eating\n", philo->position);
		usleep((philo->eat * 1000));
		pthread_mutex_unlock(philo->fork1);
		pthread_mutex_unlock(philo->fork2);
		printf("philosophers %d  eating\n", philo->position);
		usleep(philo->sleep);
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
}

