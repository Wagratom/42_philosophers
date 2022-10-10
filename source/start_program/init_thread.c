/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:46:38 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/10 16:03:04 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	*philo_routine(void *argument)
{
}

void	init_th(pthread_t *thread, t_start func, void *argument)
{
	if (pthread_create(thread, NULL, func, argument) != 0)
		printf("Error creating thread\n");
}

void	start_routine(t_table *table, int nbr_philo)
{
	int		index;

	index = -1;
	while(++index < nbr_philo)
		init_th(&table->threads[index], &philo_routine, &table->philos[index]);
	init_th(&table->threads[index], &guardian, &table->guardion);
}

void	init_ths(t_table *table)
{
	int		index;
	int		nbr_philo;

	index = -1;
	nbr_philo = table->nbr_philo;
	start_routine(table, nbr_philo);
	while(++index < nbr_philo + 1)
		pthread_join(table->threads[index], NULL);
	destroy_table(table, 0);
}

