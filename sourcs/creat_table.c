/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:39:50 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/25 12:39:58 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	convert_int(char *number)
{
	if (number == NULL)
		//printf("tried to convert a NULL to an integer\n");
		return (-1);
		//die();
	return (ft_atoi(number));

}

creat_philos(int nbr_philos)
{
	t_philo	*philos;
	int		i;

	philos = (t_philo *)ft_calloc(sizeof(t_philo), nbr_philos);
	while()
}

pthread_mutex_t	creat_mutex(void)
{
	pthread_mutex_t mutex;

	return (mutex);
}

pthread_mutex_t	*creat_forks(int nbr_forks)
{
	pthread_mutex_t		*mutex;
	int					i;

	mutex = (pthread_mutex_t *)ft_calloc(sizeof(pthread_mutex_t ), nbr_forks);
	i = -1;
	while(++i < nbr_forks)
	{
		mutex[i] = creat_mutex();
		pthread_mutex_init(&mutex[i], NULL);
	}
	return (mutex);
}

t_table	*creat_table(char *argv[])
{
	t_table	*table;

	if (argv == NULL || *argv == NULL)
		return (NULL);
	table = (t_table *)ft_calloc(sizeof(t_table), 1);
	table->number_philo = convert_int(argv[1]);
	table->forks = creat_forks(table->number_philo);
	//table->philo = creat_philos(&table);
	return (table);
}
