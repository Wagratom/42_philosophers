/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:06:08 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/16 21:32:23 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

t_bool sleeping_or_die(t_philo *philo)
{
	if (*philo->lock_die == TRUE)
		return (FALSE);
	printf("%d %d is sleeping\n", settime(), philo->position);
	usleep((philo->sleep * 1000));
	return (TRUE);
}

void	*routine(void *argument)
{
	t_philo	*philo;

	philo = (t_philo *)argument;
	while(*philo->lock_die == FALSE)
	{
		printf("%d %d is thinking\n", settime(), philo->position);
		if (philo_eating_or_die(philo) == FALSE)
			return (NULL);
		if (sleeping_or_die(philo) == FALSE)
			return (NULL);
	}
	return (NULL);
}
