/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:07:50 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/22 20:34:00 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	destroy_forks(t_table *table, int size)
{
	int	index;

	index = -1;
	while (++index < size)
		pthread_mutex_destroy(&table->forks[index]);
	pthread_mutex_destroy(&table->print_protection);
	pthread_mutex_destroy(&table->die_protection);
}

void	destroy_table(t_table *table, int size)
{
	int	index;

	index = -1;
	destroy_forks(table, size);
	free(table->forks);
	free(table->threads);
	free(table->philos);
	free(table->guardian.die_philos);
}
