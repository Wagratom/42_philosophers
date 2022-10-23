/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:06:08 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/23 16:49:39 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

t_bool	status_protect(t_philo *philo)
{
	t_bool status;

	pthread_mutex_lock(philo->die_protection);
	status = *philo->die_table == FALSE;
	pthread_mutex_unlock(philo->die_protection);
	return (status);
}

t_bool	unlock_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->fork1);
	pthread_mutex_unlock(philo->fork2);
	return (status_protect(philo));
}

t_bool	get_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->fork1);
	if (!print_protect(philo, "has taken a fork"))
		return (pthread_mutex_unlock(philo->fork1), FALSE);
	pthread_mutex_lock(philo->fork2);
	if (!print_protect(philo, "has taken a fork"))
		return (unlock_forks(philo));
	return (TRUE);
}

t_bool	eating(t_philo *philo)
{
	if (!get_forks(philo))
		return (FALSE);
	if (!print_protect(philo, "is eating"))
		return (FALSE);
	usleep((philo->eat * 1000));
	return (TRUE);
}

t_bool	eating_status(t_philo *philo)
{
	if (!eating(philo))
		return (FALSE);
	if (!unlock_forks(philo))
		return (FALSE);
	return (TRUE);
}
