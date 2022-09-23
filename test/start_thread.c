/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 11:46:02 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/23 13:10:15 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minunit.h"
# include "../includes/philosophers.h"

void	test_setup(void)
{
}
void	test_teardown(void)
{
}

MU_TEST(wait_philo_eat_tst)
{
	pthread_t		p1, p2;

	t_table				*table;

	table = creat_table((char *[]){"0","3", "10", "1000", "10", "10", NULL});
	start_thread(table);
	//pthread_join(p2, NULL);
}

MU_TEST_SUITE(test_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(wait_philo_eat_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
