/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 10:27:22 by wwallas-          #+#    #+#             */
/*   Updated: 2022/11/04 13:12:42 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static void	wait_death(t_philo philo)
{
	int		rest_life;

	rest_life = (philo.die - get_time()) * 1000;
	usleep(rest_life);
}

static void	get_fork(t_philo philo)
{
	pthread_mutex_lock(philo.fork1);
	print_protect(&philo, " has taken a fork");
	pthread_mutex_unlock(philo.fork1);
}

void	handle_one_philo(t_table *table, int size)
{
	t_philo		philo;

	if (size != 1)
		return ;
	philo = table->philos[0];
	get_fork(philo);
	wait_death(philo);
	print_protect(&philo, "died");
	destroy_table(table, size);
	exit(0);
}
