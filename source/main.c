/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:39:31 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/16 11:43:45 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	main(int argc, char *argv[])
{
	t_table table;

	if (!valid_argv(argc, argv))
		return (1);
	creat_table(&table, argv);
	init_threads(&table, table.nbr_philo);
	return (0);
}
