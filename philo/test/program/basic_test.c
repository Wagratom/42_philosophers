/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 08:25:51 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/25 23:26:57 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minunit.h"
# include "../include/philosophers.h"
# include <fcntl.h>

void	test_setup(void)
{
}
void	test_teardown(void)
{
}

/******************************************************************************/
/*							TST 20 MS LEFT									   *
/******************************************************************************/

MU_TEST(basic_1_20ms_tst)
{
	t_table table;
	int		status;

	create_table(&table, (char *[]){"./philo", "2", "120", "50", "50", "10", NULL});
	status = run_test_suppressed(&table, table.nbr_philo);
	mu_assert_int_eq(0, status);
}

MU_TEST(basic_2_20ms_tst)
{
	t_table table;
	int		status;

	create_table(&table, (char *[]){"./philo", "2", "210", "90", "100", "10", NULL});
	status = run_test_suppressed(&table, table.nbr_philo);
	mu_assert_int_eq(0, status);
}

MU_TEST(basic_3_20ms_tst)
{
	t_table table;
	int		status;

	create_table(&table, (char *[]){"./philo", "4", "210", "90", "100", "10", NULL});
	status = run_test_suppressed(&table, table.nbr_philo);
	mu_assert_int_eq(0, status);
}

MU_TEST(basic_4_20ms_tst)
{
	t_table table;
	int		status;

	create_table(&table, (char *[]){"./philo", "6", "210", "90", "100", "10", NULL});
	status = run_test_suppressed(&table, table.nbr_philo);
	mu_assert_int_eq(0, status);
}

MU_TEST(basic_5_20ms_tst)
{
	t_table table;
	int		status;

	create_table(&table, (char *[]){"./philo", "2", "180", "60", "100", "10", NULL});
	status = run_test_suppressed(&table, table.nbr_philo);
	mu_assert_int_eq(0, status);
}

MU_TEST(basic_6_20ms_tst)
{
	t_table table;
	int		status;

	create_table(&table, (char *[]){"./philo", "4", "180", "60", "100", "10", NULL});
	status = run_test_suppressed(&table, table.nbr_philo);
	mu_assert_int_eq(0, status);
}

MU_TEST(basic_7_20ms_tst)
{
	t_table table;
	int		status;

	create_table(&table, (char *[]){"./philo", "4", "1000", "480", "500", "5", NULL});
	status = run_test_suppressed(&table, table.nbr_philo);
	mu_assert_int_eq(0, status);
}

/******************************************************************************/
/*							TST 10 MS LEFT									   *
/******************************************************************************/

MU_TEST(basic_1_10ms_tst)
{
	t_table table;
	int		status;

	create_table(&table, (char *[]){"./philo", "2", "110", "50", "50", "10", NULL});
	status = run_test_suppressed(&table, table.nbr_philo);
	mu_assert_int_eq(0, status);
}

MU_TEST(basic_2_10ms_tst)
{
	t_table table;
	int		status;

	create_table(&table, (char *[]){"./philo", "2", "210", "100", "100", "10", NULL});
	status = run_test_suppressed(&table, table.nbr_philo);
	mu_assert_int_eq(0, status);
}

MU_TEST(basic_3_10ms_tst)
{
	t_table table;
	int		status;

	create_table(&table, (char *[]){"./philo", "4", "210", "100", "100", "10", NULL});
	status = run_test_suppressed(&table, table.nbr_philo);
	mu_assert_int_eq(0, status);
}

MU_TEST(basic_4_10ms_tst)
{
	t_table table;
	int		status;

	create_table(&table, (char *[]){"./philo", "6", "210", "100", "100", "10", NULL});
	status = run_test_suppressed(&table, table.nbr_philo);
	mu_assert_int_eq(0, status);
}

MU_TEST(basic_5_10ms_tst)
{
	t_table table;
	int		status;

	create_table(&table, (char *[]){"./philo", "2", "180", "70", "100", "10", NULL});
	status = run_test_suppressed(&table, table.nbr_philo);
	mu_assert_int_eq(0, status);
}

MU_TEST(basic_6_10ms_tst)
{
	t_table table;
	int		status;

	create_table(&table, (char *[]){"./philo", "4", "180", "70", "100", "10", NULL});
	status = run_test_suppressed(&table, table.nbr_philo);
	mu_assert_int_eq(0, status);
}

MU_TEST(basic_7_10ms_tst)
{
	t_table table;
	int		status;

	create_table(&table, (char *[]){"./philo", "4", "1000", "490", "500", "5", NULL});
	status = run_test_suppressed(&table, table.nbr_philo);
	mu_assert_int_eq(0, status);
}

MU_TEST_SUITE(test_20ms_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	printf("\033[0;36m		running seven basic tests\n\n");
	printf("\033[0;36m20 ms left\n");
	MU_RUN_TEST(basic_1_20ms_tst);
	MU_RUN_TEST(basic_2_20ms_tst);
	MU_RUN_TEST(basic_3_20ms_tst);
	MU_RUN_TEST(basic_4_20ms_tst);
	MU_RUN_TEST(basic_5_20ms_tst);
	MU_RUN_TEST(basic_6_20ms_tst);
	MU_RUN_TEST(basic_7_20ms_tst);
}

MU_TEST_SUITE(test_10ms_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	printf("\n");
	printf("\033[0;36m10 ms left\n");
	MU_RUN_TEST(basic_1_10ms_tst);
	MU_RUN_TEST(basic_2_10ms_tst);
	MU_RUN_TEST(basic_3_10ms_tst);
	MU_RUN_TEST(basic_4_10ms_tst);
	MU_RUN_TEST(basic_5_10ms_tst);
	MU_RUN_TEST(basic_6_10ms_tst);
	MU_RUN_TEST(basic_7_10ms_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(test_20ms_suite);
	MU_RUN_SUITE(test_10ms_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
