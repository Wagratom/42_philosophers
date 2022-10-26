/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guardian.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 11:55:35 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/26 11:03:53 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	print_protect_guardian(t_guardian *guardian, int index)
{
	pthread_mutex_lock(guardian->print_protection);
	if (*guardian->die_table == FALSE)
		printf("%d %d died\n", get_time(), index);
	*guardian->die_table = TRUE;
	pthread_mutex_unlock(guardian->print_protection);
}

static t_bool	verify_die_philo(t_guardian *guardian, int index)
{
	if (get_time() > *guardian->die_philos[index])
	{
		print_protect_guardian(guardian, (index + 1));
		pthread_mutex_unlock(guardian->die_protection);
		return (TRUE);
	}
	pthread_mutex_unlock(guardian->die_protection);
	return (FALSE);
}

static t_bool	verify_die(t_guardian *guardian)
{
	int	index;

	index = -1;
	while (++index < guardian->size)
	{
		pthread_mutex_lock(guardian->die_protection);
		if (*guardian->die_table == TRUE)
			return (TRUE);
		if (verify_die_philo(guardian, index))
			return (TRUE);
	}
	return (FALSE);
}

void	*guardian(void *argument)
{
	t_guardian	*guardian;

	guardian = (t_guardian *)argument;
	while (!verify_die(guardian))
		usleep(50);
	return (NULL);
}
