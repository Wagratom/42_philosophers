/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_forks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:32:44 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/05 11:44:48 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	creat_forks(void)
{
	int	index;
	int	n;

	n = table()->nbr_philo;
	table()->forks = (pthread_mutex_t *)ft_calloc(sizeof(pthread_mutex_t), n);
	index = -1;
	while (++index < n)
	{
		if (pthread_mutex_init(&table()->forks[index], NULL) != 0)
			printf("Error: initializing mutex\n");
	}
}
