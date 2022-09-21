/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:38:35 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/21 20:03:11 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

t_bool	philo_eat(t_table *table, pthread_mutex_t *mutex)
{
	if (table->time_eat < 0)
		return (FALSE);
	if (pthread_mutex_lock(mutex) != 0)
		return (FALSE);
	printf("lock\n");
	usleep(table->time_eat);
	if (pthread_mutex_unlock(mutex) != 0)
		return (FALSE);
	printf("unlock\n");
	return (TRUE);
}
