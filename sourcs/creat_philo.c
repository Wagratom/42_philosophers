/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:39:50 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/19 13:13:06 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

t_bool	creat_philo(char *argv[])
{
	t_philo	*philo;

	philo	=	malloc(sizeof(philo) * 1);
	ft_bzero(philo, sizeof(t_philo));
	return (philo);
}


t_bool	creat_philos(char *argv[])
{
	int	nbr_philo;

	if (argv == NULL || *argv == NULL)
		return (FALSE);
	nbr_philo = ft_atoi(argv[1]);
	while (nbr_philo--)
	{
		creat_no();
	}
}
