/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:43:41 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/23 18:15:09 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

int main(int argc, char *argv[])
{
	pthread_mutex_t		mutex;
	t_table	*table;

	valid_argv(argc, argv);
	table = creat_table(argv);
	pthread_mutex_init(&mutex, NULL);
	table->mutex = &mutex;
	start_philo(table);
	return (0);
}
