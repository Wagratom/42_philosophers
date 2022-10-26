/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:06:08 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/26 15:20:50 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	set_new_time(t_philo *philo)
{
	pthread_mutex_lock(philo->die_protection);
	philo->die = get_time() + philo->die;
	pthread_mutex_unlock(philo->die_protection);
}

t_bool	sleeping_or_die(t_philo *philo)
{
	if (!print_protect(philo, "is sleeping"))
		return (FALSE);
	usleep((philo->sleep * 1000));
	return (TRUE);
}

void	*routine(void *argument)
{
	t_philo	*philo;

	philo = (t_philo *)argument;
	if (philo->position % 2 == 0)
		usleep(10);
	while (1)
	{
		if (eating_status(philo) == FALSE)
			return (NULL);
		set_new_time(philo);
		if (--philo->times == 0)
			return (NULL);
		if (sleeping_or_die(philo) == FALSE)
			return (NULL);
		if (!print_protect(philo, "is thinking"))
			return (NULL);
	}
	return (NULL);
}
