/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:46:30 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/21 18:47:33 by wwallas-         ###   ########.fr       */
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

	struct	s_philo	*next;
	struct	s_philo	*prev;
}	t_table;

t_bool		new_thread(pthread_t *thread, void *(*add_me)(void *));

void		*routinee(void	*print_me);

t_bool		valid_argv(int argc, char **argv);

t_table		*creat_table(char *argv[]);

t_bool		philo_eat(t_table *table, pthread_mutex_t *mutex);

#endif
