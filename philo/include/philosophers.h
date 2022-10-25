/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:34:22 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/25 10:17:54 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# include <pthread.h>
# include <sys/time.h>
# include <struct.h>

typedef void	*(*t_start) (void *);

t_bool		valid_argv(int argc, char	*argv[]);

/******************************************************************************/
/*								BUILTDERS									  */
/******************************************************************************/
void		create_table(t_table *table, char *argv[]);
void		create_philos(t_table *table, int size, char *argv[]);
int			*create_philo(char *argv[], t_table *table, int index);
void		handle_one_philo(t_table *table, int size);

/******************************************************************************/
/*							THREADS, ROUTINE								  */
/******************************************************************************/

void		init_threads(t_table *table, int n_thread);
void		start_routine(t_table *table, int n_thread);
int			wait_routine(t_table *table, int n_thread);

void		*routine(void *argument);
t_bool		eating_status(t_philo *philo);

void		*guardian(void *argument);

t_bool		print_protect(t_philo *philo, char *msg);

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

/******************************************************************************/
/*								LIBFT										  */
/******************************************************************************/

int			ft_atoi(const char *nptr);

void		*ft_calloc(size_t nitems, size_t size);

char		*ft_itoa(int n);

int			ft_numb_house(unsigned long int nbr, int base);

void		ft_putstr_err(char	*messege);

t_bool		ft_str_eq(char *str1, char *str2);

char		*ft_strdup(const char *s);

size_t		ft_strlen(const char *s);

t_bool		ft_is_array_int(char	**array);


#endif
