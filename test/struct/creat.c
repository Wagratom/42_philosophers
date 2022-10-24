/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 08:25:51 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/23 18:17:04 by wwallas-         ###   ########.fr       */
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

MU_TEST(table_tst)
{
	t_table table;

	create_table(&table, (char *[]){"a.out", "5", "3", "1", "2", "5", NULL});
	mu_assert_int_eq(5, table.nbr_philo);
	mu_check(NULL != table.forks);
	mu_check(NULL != table.philos);
	mu_check(NULL != table.threads);
	restore_static();
	destroy_table(&table, table.nbr_philo);
}

MU_TEST_SUITE(create_table_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(table_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(create_table_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
