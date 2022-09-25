/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:46:30 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/25 17:41:20 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

typedef	struct s_philo
{
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				posi_table;
	int				times;
}	t_philo;

typedef struct s_table
{
	pthread_mutex_t		*forks;
	t_philo				*philo;
	int					number_philo;
}	t_table;

typedef	void *(*start_th)(void *);

t_bool			valid_argv(int argc, char **argv);

t_table			*creat_table(char *argv[]);

int				convert_int(char *number);

t_philo 		*creat_philos(int nbr_philos, char	*argv[]);

pthread_mutex_t	*creat_forks(int nbr_forks);

void			destroy_table(t_table **table);

pthread_t		new_thread(start_th func, void *argument);

t_bool			philo_eat(t_table *table);

pthread_t		*creat_thread(t_table *table);

void			*routinee(void	*print_me);
void			*start_thread(void	*table);


# define MAX_THREAD 32768
#endif
