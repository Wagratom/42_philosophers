/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guardian.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 11:55:35 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/21 17:37:43 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	print_protect_guardian(t_guardian *guardian, int index)
{
	pthread_mutex_lock(guardian->die_protection);
	printf("%d %d died\n", index, get_time());
	pthread_mutex_lock(guardian->die_protection);
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
