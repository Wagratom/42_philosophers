/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_thread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:55:01 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/16 14:15:51 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <philosophers.h>

t_bool		new_thread(pthread_t *thread, void *(*add_me)(void *))
{
	if (add_me == NULL || *add_me == NULL)
		return (FALSE);
	if (thread == NULL)
		return (FALSE);
	if (pthread_create(thread, NULL, add_me, "running") != 0)
	{
		printf("%s\n", "Erro creating thread\n");
		//die()
		return (FALSE);
	}
	return(TRUE);
}
