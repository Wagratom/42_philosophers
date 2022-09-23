/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_thread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:55:01 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/23 10:23:49 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

pthread_t	new_thread(start_th func, void *argument)
{
	pthread_t		_new_thread;

	if (func == NULL || *func == NULL)
		return (FALSE);
	if (pthread_create(&_new_thread, NULL, func, argument) != 0)
	{
		printf("%s\n", "Erro creating thread\n");
		return (FALSE);
	}
	return (_new_thread);
}
