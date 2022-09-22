/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:38:35 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/22 16:38:14 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

t_bool		philo_eat(t_table *table)
{
	printf("\n");
	if (table->time_eat < 0)
		return (FALSE);
	if (pthread_mutex_lock(table->mutex) != 0)
		return (FALSE);
	printf("lock\n");
	usleep((table->time_eat * 1000));
	if (pthread_mutex_unlock(table->mutex) != 0)
		return (FALSE);
	//usleep(table->time_sleep);
	printf("unlock\n");
	return (TRUE);
}
