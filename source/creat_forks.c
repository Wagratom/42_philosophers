/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_forks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:32:44 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/30 16:25:49 by wwallas-         ###   ########.fr       */
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
		//printf("%p\n", &(*table)->forks[index]);
		if (pthread_mutex_init(&(*table)->forks[index], NULL) != 0)
			printf("Error: initializing mutex\n");
	}
}
