/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:46:30 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/18 01:03:03 by wwallas-         ###   ########.fr       */
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
	int number_philo;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	times;
}	t_philo;

t_bool		new_thread(pthread_t *thread, void *(*add_me)(void *));

void		*routinee(void	*print_me);

#endif
