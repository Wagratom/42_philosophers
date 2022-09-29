/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:32:44 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/29 16:50:35 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

t_philo	creat_philo(char *argv[], pthread_mutex_t *forks)
{
	t_philo		new_philo;
	int static	position = 1;

	new_philo.die = ft_atoi(argv[2]);
	new_philo.eat = ft_atoi(argv[3]);
	new_philo.sleep = ft_atoi(argv[4]);
	new_philo.times = ft_atoi(argv[5]);
	new_philo.forks[0] = *forks;
	new_philo.forks[1] = *(forks + 1);
	new_philo.position= position;
	position++;
}

t_philo	creat_last_philo(char *argv[])
{
	t_philo		new_philo;
	int static	position = 1;

	new_philo.die = ft_atoi(argv[2]);
	new_philo.eat = ft_atoi(argv[3]);
	new_philo.sleep = ft_atoi(argv[4]);
	new_philo.times = ft_atoi(argv[5]);
	new_philo.position= position;
	position++;
}

void	creat_philos(t_table **table, char *argv[])
{
	int		nbr_philo;
	int		index;

	nbr_philo = (*table)->nbr_philo;
	(*table)->philos = (t_philo *)ft_calloc(sizeof(t_philo), nbr_philo);
	index = -1;
	while(++index < nbr_philo - 1)
		(*table)->philos[index] = creat_philo(argv, &(*table)->forks[index]);
	(*table)->philos[index] = creat_last_philo(argv);
	(*table)->philos[index].forks[0] = (*table)->forks[index];
	(*table)->philos[index].forks[1] = (*table)->forks[0];
}
