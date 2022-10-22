/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:34:22 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/22 14:25:46 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

# include "../libft/libft.h"
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdatomic.h>

typedef void *(*t_start)(void *);
typedef struct s_table t_table;

typedef struct s_guardian
{
	pthread_mutex_t		*print_protection;

	pthread_mutex_t		*die_protection;
	t_bool				*die_table;
	int					**die_philos;
	int 				size;
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

	pthread_mutex_t		*print_protection;
	pthread_mutex_t		*die_protection;
	t_bool				*die_table;
}	t_philo;

typedef struct s_table
{
	int					nbr_philo;
	t_bool				die;

	pthread_mutex_t		*forks;
	pthread_t			*threads;
	t_philo				*philos;

	t_guardian 			guardian;
	pthread_mutex_t		print_protection;
	pthread_mutex_t		die_protection;
}	t_table;


t_bool		valid_argv(int argc, char	*argv[]);

/******************************************************************************/
/*								BUILTDERS									  */
/******************************************************************************/
void		create_table(t_table *table, char *argv[]);
void		create_philos(t_table *table, int size, char *argv[]);
int			*create_philo(char *argv[], t_table *table, int index);
void		handle_one_philo(t_table *table, int size);

/******************************************************************************/
/*							ROUTINE THREADS									  */
/******************************************************************************/

void		init_threads(t_table *table, int size);

void		*routine(void *argument);
t_bool		philo_eating_or_die(t_philo *philo);

void		*guardian(void *argument);

void		print_protect(t_philo *philo, char *msg);

/******************************************************************************/
/*								CONTROL										  */
/******************************************************************************/
int			*control_time(void);

int			time_start(void);
int			get_time(void);

void		set_time_init(int time);
int			time_init(void);

void		destroy_table(t_table *table, int size);
void		restore_static(void);
#endif
