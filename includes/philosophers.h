/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:46:30 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/19 13:06:45 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_philo
{
	int				number_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				times;

	struct	s_philo	*next;
	struct	s_philo	*prev;
}	t_philo;

t_bool		new_thread(pthread_t *thread, void *(*add_me)(void *));

void		*routinee(void	*print_me);

t_bool		valid_argv(int argc, char **argv);

#endif
