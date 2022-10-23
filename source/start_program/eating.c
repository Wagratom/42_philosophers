/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:06:08 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/22 23:14:44 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

t_bool	unlock_forks(t_philo *philo, t_bool status)
{
	pthread_mutex_unlock(philo->fork1);
	pthread_mutex_unlock(philo->fork2);
	return (status);
}

t_bool	get_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->fork1);
	if (!print_protect(philo, "has taken a fork"))
		return (pthread_mutex_unlock(philo->fork1), FALSE);
	pthread_mutex_lock(philo->fork2);
	if (!print_protect(philo, "has taken a fork"))
		return (unlock_forks(philo, FALSE));
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

t_bool	check_is_drop_fork(t_philo *philo)
{
	if (*philo->die_table)
		return (unlock_forks(philo, FALSE));
	return (unlock_forks(philo, TRUE));
}

t_bool	philo_eating_or_die(t_philo *philo)
{
	if (!eating(philo))
		return (FALSE);
	if (!check_is_drop_fork(philo))
		return (FALSE);
	return (TRUE);
}
