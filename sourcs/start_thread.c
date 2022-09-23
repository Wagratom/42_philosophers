/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 09:26:28 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/23 18:19:02 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	*start_thread(void *table)
{
	pthread_t			threads[MAX_THREAD];
	t_table				*tmp;
	int					index;

	tmp = (t_table *)table;
	index = 0;
	while(index++ < tmp->number_philo)
		threads[index] = new_thread(&routinee, "running\n");
	index = 0;
	while(index++ < tmp->number_philo)
		pthread_join(threads[index], NULL);

	//i = 0;
	// while(i++ < tmp->times)
	//{
	//	philo_eat(table);
	//	printf("%d\n", tmp->posi_table);
	//}
	//tmp->posi_table++;
}
