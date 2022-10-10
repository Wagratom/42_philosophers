/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guardian.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 11:55:35 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/10 14:44:39 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	*guardian(void *argument)
{
	t_guardian	*guardian;
	int			index;

	printf("guardion size = %d\n", guardian->size);
	guardian = (t_guardian *)argument;
	while (1)
	{
		index = -1;
		while (++index < guardian->size)
		{
			printf("to na função infinita %d\n", *guardian->die_philos[index]);
		}
		printf("exit");
		exit(0);
	}
}
