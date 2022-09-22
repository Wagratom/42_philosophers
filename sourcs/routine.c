/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:58:14 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/22 17:33:22 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	*routinee(void	*print_me)
{
	printf("\nn%s\n", (char *)print_me);
	return (NULL);
}

void	*start_thread(void *table)
{
	t_table	*tmp;

	tmp = (t_table *)table;
	philo_eat(table);
	printf("%d\n", tmp->posi_table);
	tmp->posi_table++;
}
