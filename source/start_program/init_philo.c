/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:24:32 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/06 10:39:04 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	status_death(t_philo *philo, int time, int time_die, int variavel)
{
	int		status;

	pthread_mutex_lock(&table()->mutex_die);
	if (table()->die == TRUE)
		status = 1;
	else if ((time + variavel) < time_die)
		status = 0;
	else
	{
		usleep((time_die - time) * 1000);
		printf("philosophers %d die %d\n", philo->position, settime());
		table()->die = TRUE;
		status = 1;
	}
	pthread_mutex_unlock(&table()->mutex_die);
	return (status);
}

void	*return_unlock(t_philo *philo)
{
	pthread_mutex_unlock(philo->fork1);
	pthread_mutex_unlock(philo->fork2);
	return (NULL);
}

void	*init_philo(void *_philo)
{
	t_philo			*philo;
	int				time;

	philo = (t_philo *)_philo;
	time = philo->die;
	while(philo->times-- && table()->die == FALSE)
	{
		printf("%d %d is thinking\n", settime(), philo->position);
		pthread_mutex_lock(philo->fork1);
		pthread_mutex_lock(philo->fork2);
		if (status_death(philo, settime(), time, philo->eat))
			return (return_unlock(philo));
		printf("%d %d is eating\n", settime(), philo->position);
		usleep((philo->eat * 1000));
		time = settime() + philo->die;
		pthread_mutex_unlock(philo->fork1);
		pthread_mutex_unlock(philo->fork2);
		if (status_death(philo, settime(), time, philo->eat))
			return (NULL);
		printf("%d %d is sleeping\n", settime(), philo->position);
		usleep(philo->sleep * 1000);
		if (status_death(philo, settime(), time, 0))
			return (NULL);
	}
	return (NULL);
}
