/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:06:08 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/21 00:00:54 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

t_bool	sleeping_or_die(t_philo *philo)
{
	if (*philo->die_table)
		return (FALSE);
	print_protect(philo, "is sleeping");
	usleep((philo->sleep * 1000));
	return (TRUE);
}

void	*routine(void *argument)
{
	t_philo	*philo;

	philo = (t_philo *)argument;
	while (*philo->die_table == FALSE)
	{
		print_protect(philo, "is thinking");
		if (philo_eating_or_die(philo) == FALSE)
			return (NULL);
		if (--philo->times == 0)
			break ;
		if (sleeping_or_die(philo) == FALSE)
			return (NULL);
	}
	return (NULL);
}
