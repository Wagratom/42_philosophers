/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guardian.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 11:55:35 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/16 21:09:04 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static void	verify_die(t_guardian *guardian)
{
	int	index;

	index = -1;
	while (++index < guardian->size)
	{
		if (settime() > *guardian->die_philos[index])
		{
			printf("philosophers %d die %d\n", index, settime());
			*guardian->die = TRUE;
		}
	}
}

void	*guardian(void *argument)
{
	t_guardian	*guardian;
	int			index;

	guardian = (t_guardian *)argument;
	while (*guardian->die == FALSE)
		verify_die(guardian);
}
