/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:06:08 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/16 21:34:16 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

t_bool	unlock_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->fork1);
	pthread_mutex_unlock(philo->fork2);
	return (FALSE);
}

t_bool	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->fork1);
	pthread_mutex_lock(philo->fork2);
	if (*philo->lock_die == TRUE)
		return (FALSE);
	printf("%d %d is eating\n", settime(), philo->position);
	usleep((philo->eat * 1000));
	return (TRUE);
}

t_bool	check_drop_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->fork1);
	pthread_mutex_unlock(philo->fork2);
	if (*philo->lock_die == TRUE)
		return (FALSE);
	return (TRUE);
}

t_bool	philo_eating_or_die(t_philo *philo)
{
	if (eating(philo) == FALSE)
		return (FALSE);
	if (check_drop_fork(philo) == FALSE)
		return (FALSE);
	philo->die = settime() + philo->die;
	printf("eu %d\n", philo->die);
	return (TRUE);
}
