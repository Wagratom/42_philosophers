/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_thread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:55:01 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/20 14:34:58 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

t_bool	new_thread(pthread_t *thread, void *(*start)(void *))
{
	if (start == NULL || *start == NULL)
		return (FALSE);
	if (thread == NULL)
		return (FALSE);
	if (pthread_create(thread, NULL, start, "running") != 0)
	{
		printf("%s\n", "Erro creating thread\n");
		return (FALSE);
	}
	return (TRUE);
}
