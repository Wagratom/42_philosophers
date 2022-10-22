/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:34:09 by wwallas-          #+#    #+#             */
<<<<<<<< HEAD:source/table/create_table.c
/*   Updated: 2022/10/22 10:50:38 by wwallas-         ###   ########.fr       */
========
/*   Updated: 2022/10/21 17:37:29 by wwallas-         ###   ########.fr       */
>>>>>>>> 0d76db7a2eba22cda84b78f5691954ff165b85aa:source/table/creat_table.c
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

<<<<<<<< HEAD:source/table/create_table.c
static void	check_creat_mutex(int status)
{
	if (status != 0)
		ft_putstr_err("Not creat mutex\n");
}

void	create_mutex(t_table *table, int size)
========
void	check_mutex_err(int status)
{
	if (status != 0)
		ft_puterr("Error: initializing mutex\n");
}
void	creat_mutex(t_table *table, int size)
>>>>>>>> 0d76db7a2eba22cda84b78f5691954ff165b85aa:source/table/creat_table.c
{
	int	index;

	table->forks = (pthread_mutex_t *)ft_calloc(sizeof(pthread_mutex_t), size);
	index = -1;
	while (++index < size)
<<<<<<<< HEAD:source/table/create_table.c
		check_creat_mutex(pthread_mutex_init(&table->forks[index], NULL));
	check_creat_mutex(pthread_mutex_init(&table->protection, NULL));
========
		check_mutex_err(pthread_mutex_init(&table->forks[index], NULL));
	check_mutex_err(pthread_mutex_init(&table->print_protection, NULL));
	check_mutex_err(pthread_mutex_init(&table->die_protection, NULL));
>>>>>>>> 0d76db7a2eba22cda84b78f5691954ff165b85aa:source/table/creat_table.c
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
