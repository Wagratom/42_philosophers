/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:43:41 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/26 09:06:57 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

int main(int argc, char *argv[])
{
	t_table	*table;

	valid_argv(argc, argv);
	table = creat_table(argv);
	creat_threads(table, table->number_philo);
	start_philo(&table);
	return (0);
}
