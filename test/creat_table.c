/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 08:25:51 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/29 16:59:16 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minunit.h"
# include "../include/philosophers.h"


void	test_setup(void)
{
}
void	test_teardown(void)
{
}

MU_TEST(table_tst)
{
	t_table	*table;

	table = creat_table((char *[]){"a.out", "5", "3", "1", "2", "5", NULL});
	mu_assert_int_eq(5, table->nbr_philo);
	mu_check(NULL != table->forks);
	mu_check(NULL != table->philos);
}

MU_TEST_SUITE(creat_table_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(table_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(creat_table_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
