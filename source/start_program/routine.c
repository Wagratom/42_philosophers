/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:06:08 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/15 12:16:52 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

t_bool sleeping_or_die(t_philo *philo)
{
	if (philo->die == TRUE)
		return (FALSE);
	usleep((philo->sleep * 1000));
	return (FALSE);
}

void	*routine(void *argument)
{
	t_philo	*philo;

	philo = (t_philo *)argument;
	while(philo->die == FALSE)
	{
		printf("%d %d is thinking\n", settime(), philo->position);
		if (philo_eating_or_die(philo) == FALSE);
			return (NULL);
		if (sleeping_or_die(philo) == FALSE);
			return (NULL);
	}
	return (NULL);
}
