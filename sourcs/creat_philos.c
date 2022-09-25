/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_philos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 14:00:43 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/25 17:19:07 by wwallas-         ###   ########.fr       */
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
	position++;
	return (philo);
}

t_philo *creat_philos(int nbr_philos, char	*argv[])
{
	t_philo	*philos;
	int		i;

	philos = (t_philo *)ft_calloc(sizeof(t_philo), nbr_philos);
	i = -1;
	while(++i < nbr_philos)
		philos[i] = creat_philo(argv);
	return (philos);
}
