/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 08:25:51 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/30 16:48:02 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minunit.h"
# include "../include/philosophers.h"

t_table	*table;

void	test_setup(void)
{
}
void	test_teardown(void)
{
}

MU_TEST(table_tst)
{
	table = creat_table((char *[]){"a.out", "5", "3", "1", "2", "5", NULL});
	mu_assert_int_eq(5, table->nbr_philo);
	mu_check(NULL != table->forks);
	mu_check(NULL != table->philos);
	mu_check(NULL != table->threads);
}

MU_TEST(philo_tst)
{
	table = creat_table((char *[]){"a.out", "5", "3", "1", "2", "5", NULL});
	mu_assert_int_eq(3, table->philos[0].die);
	mu_assert_int_eq(1, table->philos[0].eat);
	mu_assert_int_eq(2, table->philos[0].sleep);
	mu_assert_int_eq(5, table->philos[0].times);
	mu_assert_int_eq(1, table->philos[0].position);

}

MU_TEST(philo_all_tst)
{
	int		index = -1;

	table = creat_table((char *[]){"a.out", "5", "3", "1", "2", "5", NULL});
	while(++index < table->nbr_philo)
	{
		mu_assert_int_eq(3, table->philos[index].die);
		mu_assert_int_eq(1, table->philos[index].eat);
		mu_assert_int_eq(2, table->philos[index].sleep);
		mu_assert_int_eq(5, table->philos[index].times);
		mu_assert_int_eq(index + 1, table->philos[index].position);
	}
}

MU_TEST(forks_address_basic_tst)
{
	pthread_mutex_t		*next;
	int		index = -1;


	table = creat_table((char *[]){"a.out", "3", "3", "1", "2", "5", NULL});
	next = table->philos[1].fork1;
	mu_check(table->philos[0].fork2 == next);
}


MU_TEST(forks_address_full_tst)
{
	pthread_mutex_t		*next;
	int		index = -1;


	table = creat_table((char *[]){"a.out", "5", "3", "1", "2", "5", NULL});
	while(++index < table->nbr_philo - 1)
	{
		next = table->philos[index + 1].fork1;
		mu_check(table->philos[index].fork2 == next);
	}
	next = table->philos[0].fork1;
	mu_check(table->philos[index].fork2 == next);
}

MU_TEST_SUITE(creat_table_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	//MU_RUN_TEST(table_tst);
	//MU_RUN_TEST(philo_tst);
	//MU_RUN_TEST(philo_all_tst);
	//MU_RUN_TEST(forks_address_basic_tst);
	MU_RUN_TEST(forks_address_full_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(creat_table_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
