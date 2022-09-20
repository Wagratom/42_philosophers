/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:39:50 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/20 16:05:06 by wwallas-         ###   ########.fr       */
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

int	*creat_forks(int nbr)
{
	int	*forks;

	forks	=	(int *)malloc(sizeof(int) * nbr);
	if (forks == NULL)
	{
		printf("Error: Unallocated memory\n");
		return (NULL); //die();
	}
	while(nbr--)
		forks[nbr] = '0';
	return (forks);

}

t_table	*creat_table(char *argv[])
{
	t_table	*table;

	if (argv == NULL || *argv == NULL)
		return (NULL);
	table = (t_table *)ft_calloc(sizeof(t_table), 1);
	table->number_philo = convert_int(argv[1]);
	table->time_die = convert_int(argv[2]);
	table->time_eat = convert_int(argv[3]);
	table->time_sleep = convert_int(argv[4]);
	table->times = convert_int(argv[5]);
	table->forks = creat_forks(table->number_philo);
	return (table);
}
