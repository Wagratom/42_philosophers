/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:46:30 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/22 17:07:12 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_table
{
	int				number_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				times;
	int				*forks;
	int				posi_table;
	pthread_mutex_t		*mutex;
}	t_table;

typedef	void *(*start_th)(void *);
t_bool	new_thread(pthread_t *thread, start_th func, t_table *argument);

t_bool		valid_argv(int argc, char **argv);

t_table		*creat_table(char *argv[]);

t_bool		philo_eat(t_table *table);

void		*routinee(void	*print_me);
void		*start_thread(void	*table);

#endif
