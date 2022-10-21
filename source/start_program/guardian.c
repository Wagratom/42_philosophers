/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guardian.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 11:55:35 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/20 23:44:06 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static void	verify_die(t_guardian *guardian)
{
	int	index;

	index = -1;
	while (++index < guardian->size)
	{
		if (get_time() > *guardian->die_philos[index])
		{
			printf("philosophers %d die %d\n", (index + 1), get_time());
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
		usleep(500);
	}
}
