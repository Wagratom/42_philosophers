/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:46:38 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/25 10:26:29 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	init_th(pthread_t *thread, t_start func, void *argument)
{
	if (pthread_create(thread, NULL, func, argument) != 0)
		ft_putstr_err("Error creating thread\n");
}

void	start_routine(t_table *table, int n_thread)
{
	int		index;

	index = -1;
	while (++index < n_thread)
		init_th(&table->threads[index], &routine, &table->philos[index]);
	init_th(&table->threads[index], &guardian, &table->guardian);
}

int	wait_routine(t_table *table, int n_thread)
{
	int		index;
	int		status;

	status = 0;
	index = -1;
	while (++index < n_thread)
		pthread_join(table->threads[index], NULL);
	if (table->die == TRUE)
		status = 1;
	table->die = TRUE;
	pthread_join(table->threads[index], NULL);
	return (status);
}

void	init_threads(t_table *table, int n_thread)
{
	start_routine(table, n_thread);
	wait_routine(table, n_thread);
}
