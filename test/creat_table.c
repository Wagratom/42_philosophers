/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:43:57 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/25 18:04:23 by wwallas-         ###   ########.fr       */
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
	mu_check(NULL == table);
}

MU_TEST(trivial_tst)
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
	printf("%d\n", philo[0].time_die);
	printf("%d\n", philo[0].time_eat);
	printf("%d\n", philo[0].time_sleep);
	printf("%d\n", philo[0].times);
	printf("%d\n", philo[0].posi_table);
	exit(0);
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
}

MU_TEST_SUITE(table_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	//MU_RUN_TEST(trivial_tst);
	//MU_RUN_TEST(philos_tst);
	MU_RUN_TEST(null_tst);
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
