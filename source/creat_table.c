/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:34:09 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/30 14:28:35 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

t_table	*creat_table(char *argv[])
{
	t_table	*table;

	table = (t_table *)ft_calloc(sizeof(t_table), 1);
	table->nbr_philo = ft_atoi(argv[1]);
	creat_forks(&table);
	creat_threads(&table);
	creat_philos(&table, argv);
	return (table);
}
