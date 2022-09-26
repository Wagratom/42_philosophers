/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:55:01 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/26 11:04:44 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

pthread_t	new_thread(start_th func, void *argument)
{
	pthread_t		_new_thread;

	if (func == NULL || *func == NULL)
		return (FALSE);
	if (pthread_create(&_new_thread, NULL, func, argument) != 0)
	{
		printf("%s\n", "Erro creating thread\n");
		return (FALSE);
	}
	return (_new_thread);
}

void	creat_threads(t_table **table, int nbr_th)
{
	int			i;
	void		*argument;

	(*table)->threads = (pthread_t *)malloc(sizeof(pthread_t) * nbr_th);
	i = -1;
	while(++i < nbr_th)
		(*table)->threads[i] = new_thread(&start_philo, &(*table)->philo[i]);
}

