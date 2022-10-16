/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:34:09 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/14 11:42:38 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	creat_forks(t_table *table, int size)
{
	int	index;

	table->forks = (pthread_mutex_t *)ft_calloc(sizeof(pthread_mutex_t), size);
	index = -1;
	while (++index < size)
	{
		if (pthread_mutex_init(&table->forks[index], NULL) != 0)
			printf("Error: initializing mutex\n");
	}
}

void	creat_threads(t_table *table, int size)
{
	table->threads = (pthread_t *)ft_calloc(sizeof(pthread_t), size + 1);
}

void	creat_guardion(t_table *table, int size)
{
	int		index;

	table->guardion.die_philos = (int **)ft_calloc(sizeof(int *), size);
	index = -1;
	while(++index < size)
		table->guardion.die_philos[index] = &table->philos[index].die;
	table->guardion.die = &table->die;
	table->guardion.size = size;
}

void	*creat_table(t_table *table, char *argv[])
{
	table->nbr_philo = ft_atoi(argv[1]);
	table->die = FALSE;
	creat_forks(table, table->nbr_philo);
	creat_threads(table, table->nbr_philo);
	creat_philos(table, table->nbr_philo, argv);
	creat_guardion(table, table->nbr_philo);
	set_time_init(time_start());
}
