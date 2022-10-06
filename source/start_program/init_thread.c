/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:46:38 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/06 09:56:03 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>


void	init_th(pthread_t *thread, t_start func, void *argument)
{
	if (pthread_create(thread, NULL, func, argument) != 0)
		printf("Error creating thread\n");
}

void	init_ths(void)
{
	int		index;
	int		nbr_philo;

	index = -1;
	nbr_philo = table()->nbr_philo;
	while(++index < nbr_philo)
		init_th(&table()->threads[index], &init_philo, &table()->philos[index]);
	index = -1;
	while(++index < nbr_philo)
		pthread_join(table()->threads[index], NULL);
	destroy_table(0);
}
