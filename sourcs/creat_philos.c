/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_philos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 14:00:43 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/26 18:00:01 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

t_philo creat_philo(char	*argv[])
{
	t_philo	philo;
	static int position = 0;

	philo.time_die = ft_atoi(argv[2]);
	philo.time_eat = ft_atoi(argv[3]);
	philo.time_sleep = ft_atoi(argv[4]);
	philo.times = ft_atoi(argv[5]);
	philo.posi_table = position;
	philo.forks[0];
	philo.forks[0];
	position++;
	return (philo);
}

t_philo *creat_philos(t_table **table, char	*argv[])
{
	t_philo	*philos;
	int			nbr_philos

	(*table)->philo = (t_philo *)ft_calloc(sizeof(t_philo), nbr_philos);
	i = -1;
	while(++i < nbr_philos)
		philos[i] = creat_philo(argv);
	return (philos);
}
