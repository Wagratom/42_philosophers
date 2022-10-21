/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:00:19 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/21 10:25:27 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	handle_one_philo(t_table *table)
{
	t_philo	philo;

	if (table->nbr_philo != 1)
		return ;
	philo = table->philos[0];
	print_protect(&philo, "is thinking");
	pthread_mutex_lock(philo.fork1);
	print_protect(&philo, " has taken a fork");
	while (philo.)
}
