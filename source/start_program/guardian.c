/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guardian.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 11:55:35 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/22 11:20:45 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	print_protect_guardian(t_guardian *guardian, int index)
{
	pthread_mutex_lock(guardian->print_protection);
	printf("%d %d died\n", get_time(), index);
	pthread_mutex_unlock(guardian->print_protection);
}

static void	verify_die(t_guardian *guardian)
{
	int	index;

	index = -1;
	while (++index < guardian->size)
	{
		if (get_time() > *guardian->die_philos[index])
		{
			print_protect_guardian(guardian, (index + 1));
			*guardian->die_table = TRUE;
			break ;
		}
	}
}

void	*guardian(void *argument)
{
	t_guardian	*guardian;
	int			index;

	guardian = (t_guardian *)argument;
	while (*guardian->die_table == FALSE)
	{
		verify_die(guardian);
		usleep(5000);
	}
}
