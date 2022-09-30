/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:46:38 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/30 16:22:17 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	*start_philo(void *teste)
{
	t_philo		*philo;

	philo = (t_philo *)teste;
	// printf("******************address*****************\n");
	// printf("posi = %d\n", philo->position);
	// printf("%p\n", philo->forks[0]);
	// printf("%p\n", philo->forks[1]);
	// printf("******************address*****************\n");
	// printf("\n");
	// sleep(3);
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
	{
		printf("%p\n", (*table)->philos[index].fork1);
		printf("%p\n", (*table)->philos[index].fork2);
		printf("\n");
		//init_th(&(*table)->threads[index], &start_philo, &(*table)->philos[index]);
	}
}

