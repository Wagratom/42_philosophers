/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ults.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:17:43 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/25 22:41:18 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTE_H
# define TESTE_H

# include "../../include/philosophers.h"
# include <fcntl.h>

void restore_static(void)
{
	*create_philo(NULL, NULL, -1) = 0;
}

void	suppress_output(void)
{
	int	dev_null;

	dev_null = open("/dev/null", O_RDWR);
	if (dev_null  == -1)
		ft_putstr_err("erro file\n");
	dup2(dev_null , STDOUT_FILENO);
	close (dev_null );
}

void	restore_stdout(int outfile)
{
	dup2(outfile, STDOUT_FILENO);
}

int	run_test_suppressed(t_table *table, int n_thread)
{
	int		status;
	int 	outifile = dup(STDOUT_FILENO);

	suppress_output();
	start_routine(table, n_thread);
	status = wait_routine(table, n_thread);
	restore_stdout(outifile);
	restore_static();
	destroy_table(table, n_thread);
	return (status);
}

#endif
