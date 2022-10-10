/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 08:25:51 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/10 14:50:26 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minunit.h"
# include "../../include/philosophers.h"

void	test_setup(void)
{
}
void	test_teardown(void)
{
}

MU_TEST(fork_not_erro_tst)
{
	t_table	table;
	int		index;

	creat_table(&table, (char *[]){"a.out", "5", "3", "1", "2", "5", NULL});
	index = -1;
	while(++index < 5)
		mu_assert_int_eq(0, pthread_mutex_lock(&table.forks[index]));
	//destroy_table(0);
}

MU_TEST(address_basic_tst)
{
	pthread_mutex_t		*next;
	int		index = -1;
	t_table table;

	creat_table(&table, (char *[]){"a.out", "2", "3", "1", "2", "5", NULL});
	next = table.philos[1].fork1;
	mu_check(table.philos[0].fork2 == next);
}

MU_TEST(address_full_tst)
{
	pthread_mutex_t		*next;
	int		index = -1;
	t_table table;

	creat_table(&table, (char *[]){"a.out", "5", "3", "1", "2", "5", NULL});
	while(++index < table.nbr_philo - 1)
	{
		next = table.philos[index + 1].fork1;
		mu_check(table.philos[index].fork2 == next);
	}
	next = table.philos[0].fork1;
	mu_check(table.philos[index].fork2 == next);
}

MU_TEST_SUITE(creat_table_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(fork_not_erro_tst);
	//MU_RUN_TEST(address_basic_tst);
	//MU_RUN_TEST(address_full_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(creat_table_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
