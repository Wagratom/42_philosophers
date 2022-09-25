/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_mutex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 14:06:43 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/25 14:07:35 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

pthread_mutex_t	creat_mutex(void)
{
	pthread_mutex_t mutex;

	return (mutex);
}

pthread_mutex_t	*creat_forks(int nbr_forks)
{
	pthread_mutex_t		*mutex;
	int					i;

	mutex = (pthread_mutex_t *)ft_calloc(sizeof(pthread_mutex_t ), nbr_forks);
	i = -1;
	while(++i < nbr_forks)
	{
		mutex[i] = creat_mutex();
		pthread_mutex_init(&mutex[i], NULL);
	}
	return (mutex);
}
