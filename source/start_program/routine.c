/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:06:08 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/20 09:59:48 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

t_bool	sleeping_or_die(t_philo *philo)
{
	if (*philo->die_table)
		return (FALSE);
	printf("%d %d is sleeping\n", get_time(), philo->position);
	usleep((philo->sleep * 1000));
	return (TRUE);
}

void	*routine(void *argument)
{
	t_philo	*philo;

	philo = (t_philo *)argument;
	while (*philo->die_table == FALSE && philo->times--)
	{
		printf("%d %d is thinking\n", get_time(), philo->position);
		if (philo_eating_or_die(philo) == FALSE)
			return (NULL);
		if (sleeping_or_die(philo) == FALSE)
			return (NULL);
	}
	return (NULL);
}
