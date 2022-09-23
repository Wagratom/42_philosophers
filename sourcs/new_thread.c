/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_thread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:55:01 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/23 18:35:07 by wwallas-         ###   ########.fr       */
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

pthread_t	*creat_thread(t_table *table)
{
	pthread_t	*threads;
	int			index;

	threads = (pthread_t *)malloc(sizeof(pthread_t) * (table->number_philo + 1));
	index = -1;
	while(index++ < table->number_philo)
		threads[index] = new_thread(&start_thread, table);
	threads[++index] = (pthread_t)NULL;
	return (threads);
}

int	creat_thread_aux_tst(t_table *table)
{
	pthread_t	*threads;
	int			index;

	threads = creat_thread(table);
	index = -1;
	while(threads[++index])
		;
	return (index);
}
