/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 18:09:08 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/22 18:27:29 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

#include <philosophers.h>

/******************************************************************************/
/*								GUARDIAN									  */
/******************************************************************************/

typedef struct s_guardian
{
	pthread_mutex_t		*print_protection;
	pthread_mutex_t		*die_protection;

	t_bool				*die_table;
	int					**die_philos;

	int					size;

}	t_guardian;

/******************************************************************************/
/*								PHILO										  */
/******************************************************************************/

typedef struct s_philo
{
	int					die;
	int					eat;
	int					sleep;
	int					times;
	int					position;

	pthread_mutex_t		*fork1;
	pthread_mutex_t		*fork2;

	pthread_mutex_t		*print_protection;
	pthread_mutex_t		*die_protection;

	t_bool				*die_table;

}	t_philo;

/******************************************************************************/
/*								TABLE										  */
/******************************************************************************/

typedef struct s_table
{
	int					nbr_philo;
	t_bool				die;

	pthread_mutex_t		*forks;
	pthread_t			*threads;
	t_philo				*philos;

	t_guardian			guardian;

	pthread_mutex_t		print_protection;
	pthread_mutex_t		die_protection;

}	t_table;

#endif
