/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_protect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:06:08 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/22 22:18:17 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

t_bool	print_protect(t_philo *philo, char *msg)
{
	if (*philo->die_table)
		return (FALSE);
	pthread_mutex_lock(philo->print_protection);
	printf("%d %d %s\n", get_time(), philo->position, msg);
	pthread_mutex_unlock(philo->print_protection);
	return (TRUE);
}
