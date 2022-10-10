/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:39:31 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/09 14:03:00 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	main(int argc, char *argv[])
{
	t_table table;

	valid_argv(argc, argv);
	creat_table(&table, argv);
	init_ths(&table);
	return (0);
}
