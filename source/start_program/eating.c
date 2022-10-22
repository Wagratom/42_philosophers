/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:06:08 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/22 10:22:19 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void print_protect(t_philo *philo, char *msg)
{
	pthread_mutex_lock(philo->print_protection);
	printf("%d %d %s\n", get_time(), philo->position, msg);
	pthread_mutex_unlock(philo->print_protection);
}

t_bool	unlock_forks(t_philo *philo, t_bool status)
{
	pthread_mutex_unlock(philo->fork1);
	pthread_mutex_unlock(philo->fork2);
	return (status);
}

t_bool	get_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->fork1);
	print_protect(philo, " has taken a fork");
	pthread_mutex_lock(philo->fork2);
	print_protect(philo, " has taken a fork");
	return (TRUE);
}

t_bool	eating(t_philo *philo)
{
	if (!get_fork)
		return (FALSE);
	if (*philo->die_table)
		return (unlock_forks(philo, FALSE));
	printf("%d %d is eating\n", get_time(), philo->position);
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
	philo->die = get_time() + philo->die;
	printf("atualizei %d\n", philo->die);
	return (TRUE);
}
