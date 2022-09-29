/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:34:09 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/29 14:31:12 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

pthread_mutex_t creat_fork(void)
{
	pthread_mutex_t	fork;

	return (fork);
}

void	creat_forks(t_table	**table)
{
	int	index;
	int	n;

	n = (*table)->nbr_philo;
	(*table)->forks = (pthread_mutex_t *)ft_calloc(sizeof(pthread_mutex_t), n);
	index = -1;
	while (++index < n)
	{
		(*table)->forks[index] = creat_fork();
		if (pthread_mutex_init(&(*table)->forks[index], NULL) != 0)
			printf("Error: initializing mutex\n");
	}
}

t_table	*creat_table(char *argv[])
{
	t_table	*table;

	table = (t_table *)ft_calloc(sizeof(t_table), 1);
	table->nbr_philo = ft_atoi(argv[1]);
	creat_forks(&table);
	return (table);
}
