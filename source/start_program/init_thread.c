/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:46:38 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/16 21:12:34 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	init_th(pthread_t *thread, t_start func, void *argument)
{
	if (pthread_create(thread, NULL, func, argument) != 0)
		printf("Error creating thread\n");
}

void	start_routine(t_table *table, int nbr_philo)
{
	int		index;

	index = -1;
	init_th(&table->threads[nbr_philo], &guardian, &table->guardion);
	while(++index < nbr_philo)
		init_th(&table->threads[index], &routine, &table->philos[index]);
}

void	wait_routine(t_table *table, int size)
{
	int		index;

	index = -1;
	while(++index < size)
		pthread_join(table->threads[index], NULL);
}

void	init_threads(t_table *table, int size)
{
	start_routine(table, size);
	wait_routine(table, (size + 1));
	destroy_table(table, 0);
}
