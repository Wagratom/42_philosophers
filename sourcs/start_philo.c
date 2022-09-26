/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 08:34:43 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/26 11:06:13 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	*start_philo(void *philo)
{
	t_philo	*tmp;

	tmp = (t_philo *)philo;
	printf("%d\n", (*tmp).posi_table);
	usleep(1000000);
}
