/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 10:57:29 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/22 14:24:17 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static void	check_err_mutex(int status)
{
	if (status != 0)
		ft_putstr_err("Not creat mutex\n");
}

void	create_mutex(t_table *table, int size)
{
	int	index;

	table->forks = (pthread_mutex_t *)ft_calloc(sizeof(pthread_mutex_t), size);
	index = -1;
	while (++index < size)
		check_err_mutex(pthread_mutex_init(&table->forks[index], NULL));
	check_err_mutex(pthread_mutex_init(&table->print_protection, NULL));
	check_err_mutex(pthread_mutex_init(&table->die_protection, NULL));
}

void	create_threads(t_table *table, int size)
{
	table->threads = (pthread_t *)ft_calloc(sizeof(pthread_t), size + 1);
}

void	create_guardion(t_table *table, int size)
{
	int		index;

	table->guardian.die_philos = (int **)ft_calloc(sizeof(int *), size);
	index = -1;
	while (++index < size)
		table->guardian.die_philos[index] = &table->philos[index].die;
	table->guardian.die_table = &table->die;
	table->guardian.size = size;
	table->guardian.print_protection = &table->print_protection;
	table->guardian.die_protection = &table->die_protection;
}

void	create_table(t_table *table, char *argv[])
{
	if (argv[5] == NULL)
		argv[5] = "-1";
	table->nbr_philo = ft_atoi(argv[1]);
	table->die = FALSE;
	create_mutex(table, table->nbr_philo);
	create_threads(table, table->nbr_philo);
	create_philos(table, table->nbr_philo, argv);
	create_guardion(table, table->nbr_philo);
	set_time_init(time_start());
}
