/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_thread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:55:01 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/22 16:23:13 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

typedef	void *(*start_th)(void *);

t_bool	new_thread(pthread_t *thread, start_th func, t_table *argument)
{
	if (func == NULL || *func == NULL)
		return (FALSE);
	if (thread == NULL)
		return (FALSE);
	if (pthread_create(thread, NULL, func, argument) != 0)
	{
		printf("%s\n", "Erro creating thread\n");
		return (FALSE);
	}
	return (TRUE);
}
