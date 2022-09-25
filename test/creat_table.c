/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:43:57 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/25 17:00:45 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
# include "../includes/philosophers.h"


t_table		*table;

pthread_t	t1, t2;

void	test_setup(void)
{
}
void	test_teardown(void)
{
}

MU_TEST(trivial_tst)
{
	pthread_mutex_t mutex;
	t_philo			philo;

	table = creat_table((char	*[]){"a.out", "3", "5", "3", "10", "10", NULL});
	mu_check(NULL != table);
	mu_check(NULL != table->forks);
	mu_check(NULL != table->philo);
	philo = table->philo[0];
	mu_assert_int_eq(3, table->number_philo);
	mu_assert_int_eq(5, philo.time_die);
	mu_assert_int_eq(3, philo.time_eat);
	mu_assert_int_eq(10, philo.time_sleep);
	mu_assert_int_eq(10, philo.times);
	destroy_table(table);
}

MU_TEST(creat_table_null_tst)
{
	t_philo			philo;
	table = creat_table((char	*[]){"a.out", "10", NULL, "8", NULL, "9", NULL});
	mu_check(NULL != table);
	mu_assert_int_eq(10, table->number_philo);
	philo = table->philo[0];
	// mu_assert_int_eq(-1, table->time_die);
	// mu_assert_int_eq(8, table->time_eat);
	// mu_assert_int_eq(-1, table->time_sleep);
	// mu_assert_int_eq(9, table->times);

	table = creat_table((char	*[]){"a.out", NULL, NULL, NULL, NULL, NULL, NULL});
	mu_check(NULL != table);
	// mu_assert_int_eq(-1, table->number_philo);
	// mu_assert_int_eq(-1, table->time_die);
	// mu_assert_int_eq(-1, table->time_eat);
	// mu_assert_int_eq(-1, table->time_sleep);
	// mu_assert_int_eq(-1, table->times);
}

MU_TEST_SUITE(table_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(trivial_tst);
	//MU_RUN_TEST(creat_table_null_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(table_suite);
	MU_REPORT();
	argc = argc;
	envp = envp;
	return (MU_EXIT_CODE);
}
