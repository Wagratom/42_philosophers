/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:43:57 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/26 11:16:47 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
# include "../includes/philosophers.h"


/******************************************************************************\
* 								CREAT_TABLE									   *
\******************************************************************************/

t_table		*table;

void	test_setup(void)
{
}
void	test_teardown(void)
{
	mu_check(NULL == table);
}

MU_TEST(table_tst)
{
	mu_check(NULL == table);
	table = creat_table((char	*[]){"a.out", "3", "5", "3", "10", "10", NULL});
	mu_check(NULL != table);
	mu_check(NULL != table->forks);
	mu_check(NULL != table->philo);
	mu_assert_int_eq(3, table->number_philo);
	destroy_table(&table);
}

MU_TEST(philos_tst)
{
	t_philo			*philo;
	int				i;

	mu_check(NULL == table);
	table = creat_table((char	*[]){"a.out", "3", "5", "3", "10", "10", NULL});
	philo = table->philo;
	i = -1;
	while (++i < table->number_philo)
	{
		mu_assert_int_eq(5, philo[i].time_die);
		mu_assert_int_eq(3, philo[i].time_eat);
		mu_assert_int_eq(10, philo[i].time_sleep);
		mu_assert_int_eq(10, philo[i].times);
		mu_assert_int_eq(i, philo[i].posi_table);
	}
	destroy_table(&table);
}

MU_TEST(null_tst)
{
	t_philo			*philo;
	int				i;

	table = creat_table(NULL);
	mu_check(NULL == table);
	table = creat_table((char	*[]){"a.out", "3", "5", "3", "10", "10", NULL});
	destroy_table(&table);
	mu_check(NULL == table);
}

MU_TEST_SUITE(table_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(table_tst);
	//MU_RUN_TEST(philos_tst);
	MU_RUN_TEST(null_tst);
}

/******************************************************************************\
* 								CREAT_THREAD								   *
\******************************************************************************/

MU_TEST(thread_5_tst)
{
	t_table				*table;
	int 				i;

	table = creat_table((char *[]){"0", "5", "10", "1000", "10", "10", NULL});
	creat_threads(&table, table->number_philo);
	i = -1;
	while(++i < table->number_philo)
		mu_assert_int_eq(0, pthread_join(table->threads[i], NULL));
}

MU_TEST(thread_10_tst)
{
	t_table				*table;
	int 				i;

	table = creat_table((char *[]){"0", "10", "10", "1000", "10", "10", NULL});
	creat_threads(&table, table->number_philo);
	i = -1;
	while(++i < table->number_philo)
		mu_assert_int_eq(0, pthread_join(table->threads[i], NULL));
}

MU_TEST_SUITE(thread_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	//MU_RUN_TEST(thread_5_tst);
	MU_RUN_TEST(thread_10_tst);
}

/******************************************************************************\
* 								INIT										   *
\******************************************************************************/
MU_MAIN
{
	MU_DIVIDER;
	//MU_RUN_SUITE(table_suite);
	MU_RUN_SUITE(thread_suite);
	MU_REPORT();
	argc = argc;
	envp = envp;
	return (MU_EXIT_CODE);
}
