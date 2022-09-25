/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:39:50 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/25 17:54:44 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

t_table	*creat_table(char *argv[])
{
	t_table		*table;
	t_philo		*philo;

	if (argv == NULL || *argv == NULL)
		return (NULL);
	table = (t_table *)ft_calloc(sizeof(t_table), 1);
	table->number_philo = ft_atoi(argv[1]);
	table->forks = creat_forks(table->number_philo);
	table->philo = creat_philos(table->number_philo, argv);
	philo = table->philo;
	return (table);
}

void	destroy_table(t_table **table)
{
	if (table == NULL || *table == NULL)
		return ;
	free((*table)->forks);
	free((*table)->philo);
	free(*table);
	*table = NULL;
}
