/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 08:34:43 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/26 16:21:14 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	*start_philo(void *table)
{
	t_philo	*philo;
	int		i;

	philo = (t_table *)table;
	i = -1;
	while(++i < philo->times)
	{
		get_fork(philo->posi_table);
		printf("%d\n", (*philo).posi_table);
		usleep(1000000);
	}
}


void	*get_fork(t_table **table, int posi)
{
	if (posi == (*table)->number_philo)
	{
		pthread_mutex_lock(&(*table)->forks[0]);
		pthread_mutex_lock(&(*table)->forks[posi]);
	}
	else
	{
		pthread_mutex_lock(&(*table)->forks[posi]);
		pthread_mutex_lock(&(*table)->forks[posi + 1]);
	}
}

void	init_philosophers(t_table **table)
{
	int		i;

	creat_threads(table, (*table)->number_philo);
	while(++i < (*table)->number_philo)
	{
		get_fork((*table)->philo[i]);
	}
}
