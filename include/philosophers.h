/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:34:22 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/10 14:30:16 by wwallas-         ###   ########.fr       */
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

typedef struct s_guardian
{
	int		**die_philos;
	int		*die;
	int 	size;
}	t_guardian;

typedef struct s_philo
{
	int					die;
	int					eat;
	int					sleep;
	int					times;
	int 				position;
	pthread_mutex_t		*fork1;
	pthread_mutex_t		*fork2;
}	t_philo;

typedef struct s_table
{
	int					nbr_philo;
	pthread_mutex_t		*forks;
	t_philo				*philos;
	pthread_t			*threads;
	t_guardian 			guardion;
	int					die;
}	t_table;


t_bool	valid_argv(int argc, char	*argv[]);
void	*creat_table(t_table *table, char *argv[]);
void	creat_philos(t_table *table, char *argv[]);

void	set_time_init(int time);

int		time_init(void);

int		time_start(void);

void	init_ths(t_table *table);

void	*init_philo(void *_philo);

void	destroy_table(t_table *table, int status);

int		time_start(void);

t_table	*table(void);

int		settime(void);


void	*guardian(void *argument);


#endif
