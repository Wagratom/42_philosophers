/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:34:09 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/06 08:03:43 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

t_table	*table(void)
{
	static t_table	table;

	return (&table);
}

t_table	*creat_table(char *argv[])
{
	table()->nbr_philo = ft_atoi(argv[1]);
	creat_forks();
	creat_threads();
	creat_philos(argv);
	pthread_mutex_init(&table()->mutex_die, NULL);
	table()->die = FALSE;
	set_time_init(time_start());
	return (table());
}
