/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 09:26:28 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/23 09:26:42 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	*start_thread(void *table)
{
	t_table	*tmp;

	tmp = (t_table *)table;
	philo_eat(table);
	printf("%d\n", tmp->posi_table);
	tmp->posi_table++;
}
