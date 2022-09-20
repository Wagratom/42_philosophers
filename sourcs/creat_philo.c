/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:39:50 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/19 20:51:37 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

t_philo	*creat_philos(char *argv[])
{
	t_philo	*table;

	if (argv == NULL || *argv == NULL)
		return (FALSE);
	table = (t_philo *)malloc(sizeof(t_philo) * 1);
	table->number_philo = ft_atoi(argv[1]);
	table->time_die	=	ft_atoi(argv[2]);
	table->time_eat	=	ft_atoi(argv[3]);
	table->time_sleep	=	ft_atoi(argv[4]);
	table->time_die	=	ft_atoi(argv[5]);
	table->times	=	ft_atoi(argv[6]);

	return (table);
}
