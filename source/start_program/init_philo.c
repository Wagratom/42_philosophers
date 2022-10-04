/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:24:32 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/03 17:32:21 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	settime(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000 + time.tv_usec / 1000) - time_init());
}

void	status_death(t_philo *philo, int time, int time_die, int variavel)
{
	if ((time + variavel) < time_die)
		return ;
	printf("philosophers %d die\n", philo->position);
	destroy_table(philo->table, 0);
}

void	*init_philo(void *_philo)
{
	t_philo			*philo;
	int				time;

	philo = (t_philo *)_philo;
	time = philo->die;
	while(philo->times--)
	{
		printf("%d %d is thinking\n", settime(), philo->position);
		pthread_mutex_lock(philo->fork1);
		pthread_mutex_lock(philo->fork2);
		status_death(philo, settime(), time, philo->eat);
		printf("%d %d is eating\n", settime(), philo->position);
		usleep((philo->eat * 1000));
		time = settime() + philo->die;
		pthread_mutex_unlock(philo->fork1);
		pthread_mutex_unlock(philo->fork2);
		printf("%d %d is sleeping\n", settime(), philo->position);
		usleep(philo->sleep * 1000);
		status_death(philo, settime(), time, 0);
	}
}
