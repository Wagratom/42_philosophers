/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:43:41 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/16 22:30:12 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

int main()
{
	pthread_t	t1;

	t1 = NULL;
	new_thread(&t1, &routinee);
	pthread_join(t1, NULL);
	return (0);
}
