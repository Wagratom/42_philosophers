/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:34:09 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/10 13:32:32 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	creat_forks(t_table *table)
{
	int	index;
	int	n;

	n = table->nbr_philo;
	table->forks = (pthread_mutex_t *)ft_calloc(sizeof(pthread_mutex_t), n);
	index = -1;
	while (++index < n)
	{
		if (pthread_mutex_init(&table->forks[index], NULL) != 0)
			printf("Error: initializing mutex\n");
	}
}

void	creat_threads(t_table *table)
{
	int		n;
	n = table->nbr_philo;
	table->threads = (pthread_t *)ft_calloc(sizeof(pthread_t), n + 1);
}

void	creat_guardion(t_table *table)
{
	int		nbr_philo;
	int		index;

	nbr_philo = table->nbr_philo;
	table->guardion.die_philos = (int **)ft_calloc(sizeof(int *), nbr_philo);
	index = -1;
	while(++index < nbr_philo)
		table->guardion.die_philos[index] = &table->philos[index].die;
	table->guardion.die = &table->die;
	table->guardion.size = nbr_philo;
}

void	*creat_table(t_table *table, char *argv[])
{
	table->nbr_philo = ft_atoi(argv[1]);
	table->die = FALSE;
	creat_forks(table);
	creat_threads(table);
	creat_philos(table, argv);
	creat_guardion(table);
	set_time_init(time_start());
}
