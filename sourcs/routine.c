/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:58:14 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/16 18:00:42 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <philosophers.h>

void	*routinee(void	*print_me)
{
	printf("\nn%s\n", (char *)print_me);
	return ((void*)NULL);
}
