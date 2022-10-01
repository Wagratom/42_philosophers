/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:13:45 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/30 22:32:49 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

pthread_t	creat_th(void)
{
	pthread_t	new_thread;

	return (new_thread);
}

void	creat_threads(t_table **table)
{
	int		n;
	int		index;

	n = (*table)->nbr_philo;
	(*table)->threads = (pthread_t *)ft_calloc(sizeof(pthread_t), n);
	index = -1;
	while (++index < n)
		(*table)->threads[index] = creat_th();
}
