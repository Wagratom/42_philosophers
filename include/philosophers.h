/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:34:22 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/29 16:35:33 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

# include <stdio.h>
# include "../libft/libft.h"
# include <pthread.h>

typedef struct s_philo
{
	int	die;
	int	eat;
	int	sleep;
	int	times;
	pthread_mutex_t		forks[2];
	int position;
}	t_philo;

typedef struct s_table
{
	int					nbr_philo;
	pthread_mutex_t		*forks;
	t_philo				*philos;
}	t_table;

t_bool	valid_argv(int argc, char	*argv[]);

t_table	*creat_table(char *argv[]);

void	creat_forks(t_table	**table);

void	creat_philos(t_table **table, char *argv[]);

#endif
