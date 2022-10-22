/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 08:25:51 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/22 14:29:07 by wwallas-         ###   ########.fr       */
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

MU_TEST(philo_tst)
{
	t_table table;

	create_table(&table, (char *[]){"a.out", "5", "3", "1", "2", "5", NULL});
	mu_assert_int_eq(3, table.philos[0].die);
	mu_assert_int_eq(1, table.philos[0].eat);
	mu_assert_int_eq(2, table.philos[0].sleep);
	mu_assert_int_eq(5, table.philos[0].times);
	mu_assert_int_eq(1, table.philos[0].position);
	restore_static();
	destroy_table(&table, table.nbr_philo);
}

MU_TEST(philo_all_tst)
{
	t_table table;
	int		index = -1;

	create_table(&table, (char *[]){"a.out", "5", "3", "1", "2", "5", NULL});
	while(++index < table.nbr_philo)
	{
		mu_assert_int_eq(3, table.philos[index].die);
		mu_assert_int_eq(1, table.philos[index].eat);
		mu_assert_int_eq(2, table.philos[index].sleep);
		mu_assert_int_eq(5, table.philos[index].times);
		mu_assert_int_eq(index + 1, table.philos[index].position);
	}
	restore_static();
	destroy_table(&table, table.nbr_philo);
}

MU_TEST(philo_not_time_tst)
{
	t_table table;
	int		index = -1;

	create_table(&table, (char *[]){"a.out", "5", "3", "1", "2", NULL});
	while(++index < table.nbr_philo)
	{
		mu_assert_int_eq(3, table.philos[index].die);
		mu_assert_int_eq(1, table.philos[index].eat);
		mu_assert_int_eq(2, table.philos[index].sleep);
		mu_assert_int_eq(-1, table.philos[index].times);
		mu_assert_int_eq(index + 1, table.philos[index].position);
	}
	restore_static();
	destroy_table(&table, table.nbr_philo);
}

MU_TEST(print_protect_tst)
{
	t_table table;
	int		index = -1;

	create_table(&table, (char *[]){"a.out", "5", "3", "1", "2", NULL});
	mu_check(&table.print_protection == table.philos[0].print_protection);
	restore_static();
	destroy_table(&table, table.nbr_philo);
}

MU_TEST_SUITE(creat_table_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(philo_tst);
	MU_RUN_TEST(philo_all_tst);
	MU_RUN_TEST(philo_not_time_tst);
	MU_RUN_TEST(print_protect_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(creat_table_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
