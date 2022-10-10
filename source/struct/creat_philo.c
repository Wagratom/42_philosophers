/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:32:44 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/10 12:58:57 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	creat_philo(char *argv[], t_table *table, int index)
{
	t_philo		new_philo;
	int static	position = 0;

	position++;
	new_philo.die = ft_atoi(argv[2]);
	new_philo.eat = ft_atoi(argv[3]);
	new_philo.sleep = ft_atoi(argv[4]);
	new_philo.times = ft_atoi(argv[5]);
	new_philo.fork1 = &table->forks[index];
	new_philo.fork2 = &table->forks[index + 1];
	new_philo.position = position;
	table->philos[index] = new_philo;
}

void	creat_last_philo(char *argv[], t_table *table, int position)
{
	t_philo		new_philo;

	new_philo.die = ft_atoi(argv[2]);
	new_philo.eat = ft_atoi(argv[3]);
	new_philo.sleep = ft_atoi(argv[4]);
	new_philo.times = ft_atoi(argv[5]);
	new_philo.position = position + 1;
	table->philos[position] = new_philo;
}

void	creat_philos(t_table *table, char *argv[])
{
	int		nbr_philo;
	int		index;

	nbr_philo = table->nbr_philo;
	table->philos = (t_philo *)ft_calloc(sizeof(t_philo), nbr_philo);
	index = -1;
	while (++index < nbr_philo - 1)
		creat_philo(argv, table, index);
	creat_last_philo(argv, table, index);
	table->philos[index].fork1 = &table->forks[index];
	table->philos[index].fork2 = &table->forks[0];
}
