/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:34:22 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/03 13:16:06 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

# include "../libft/libft.h"
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef void *(*t_start)(void *);
typedef struct s_table t_table;

typedef struct s_philo
{
	int			die;
	int			eat;
	int			sleep;
	int			times;
	int 		position;
	t_table		**table;
	pthread_mutex_t		*fork1;
	pthread_mutex_t		*fork2;

}	t_philo;

typedef struct s_table
{
	int					nbr_philo;
	pthread_mutex_t		*forks;
	t_philo				*philos;
	pthread_t			*threads;
}	t_table;

t_bool	valid_argv(int argc, char	*argv[]);

t_table	*creat_table(char *argv[]);

void	creat_forks(t_table	**table);

void	creat_philos(t_table **table, char *argv[]);

void	creat_threads(t_table **table);

void	set_time_init(int time);

int		time_init(void);

int		time_start(void);

void	init_ths(t_table **table);

void	destroy_table(t_table **table, int status);


int		time_start(void);


#endif
