/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:13:45 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/05 11:45:10 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	creat_threads(void)
{
	int		n;

	n = table()->nbr_philo;
	table()->threads = (pthread_t *)ft_calloc(sizeof(pthread_t), n);
}
