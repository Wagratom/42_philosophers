/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 09:26:28 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/23 11:38:17 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	*start_thread(void *table)
{
	pthread_t threads[MAX_THREAD];
	t_table		*tmp;
	int			i;

	tmp = (t_table *)table;
	i = 0;
	while(i++ < tmp->number_philo)
	{
		printf("crieu\n");
	}
	//i = 0;
	// while(i++ < tmp->times)
	//{
	//	philo_eat(table);
	//	printf("%d\n", tmp->posi_table);
	//}
	//tmp->posi_table++;
}
