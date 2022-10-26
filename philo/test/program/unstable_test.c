/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unstable_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 08:25:51 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/26 11:16:58 by wwallas-         ###   ########.fr       */
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
/*							TST 5 MS LEFT									   *
/******************************************************************************/

MU_TEST(unstable_1_5ms_tst)
{
	t_table table;
	int		status;

	create_table(&table, (char *[]){"./philo", "2", "100", "45", "50", "10", NULL});
	status = run_test_suppressed(&table, table.nbr_philo);
	mu_assert_int_eq(0, status);
}

MU_TEST(unstable_2_5ms_tst)
{
	t_table table;
	int		status;

	create_table(&table, (char *[]){"./philo", "2", "200", "95", "100", "10", NULL});
	status = run_test_suppressed(&table, table.nbr_philo);
	mu_assert_int_eq(0, status);
}

MU_TEST(unstable_3_5ms_tst)
{
	t_table table;
	int		status;

	create_table(&table, (char *[]){"./philo", "4", "200", "95", "100", "10", NULL});
	status = run_test_suppressed(&table, table.nbr_philo);
	mu_assert_int_eq(0, status);
}

MU_TEST(unstable_4_5ms_tst)
{
	t_table table;
	int		status;

	create_table(&table, (char *[]){"./philo", "6", "200", "95", "100", "10", NULL});
	status = run_test_suppressed(&table, table.nbr_philo);
	mu_assert_int_eq(0, status);
}

MU_TEST(unstable_5_5ms_tst)
{
	t_table table;
	int		status;

	create_table(&table, (char *[]){"./philo", "2", "180", "75", "100", "10", NULL});
	status = run_test_suppressed(&table, table.nbr_philo);
	mu_assert_int_eq(0, status);
}

MU_TEST(unstable_6_5ms_tst)
{
	t_table table;
	int		status;

	create_table(&table, (char *[]){"./philo", "4", "180", "75", "100", "10", NULL});
	status = run_test_suppressed(&table, table.nbr_philo);
	mu_assert_int_eq(0, status);
}

MU_TEST(unstable_7_5ms_tst)
{
	t_table table;
	int		status;

	create_table(&table, (char *[]){"./philo", "4", "1000", "495", "500", "5", NULL});
	status = run_test_suppressed(&table, table.nbr_philo);
	mu_assert_int_eq(0, status);
}

/******************************************************************************/
/*							TST 3 MS LEFT									   *
/******************************************************************************/

MU_TEST(unstable_1_3ms_tst)
{
	t_table table;
	int		status;

	create_table(&table, (char *[]){"./philo", "2", "100", "47", "50", "10", NULL});
	status = run_test_suppressed(&table, table.nbr_philo);
	mu_assert_int_eq(0, status);
}

MU_TEST(unstable_2_3ms_tst)
{
	t_table table;
	int		status;

	create_table(&table, (char *[]){"./philo", "2", "200", "97", "100", "10", NULL});
	status = run_test_suppressed(&table, table.nbr_philo);
	mu_assert_int_eq(0, status);
}

MU_TEST(unstable_3_3ms_tst)
{
	t_table table;
	int		status;

	create_table(&table, (char *[]){"./philo", "4", "200", "97", "100", "10", NULL});
	status = run_test_suppressed(&table, table.nbr_philo);
	mu_assert_int_eq(0, status);
}

MU_TEST(unstable_4_3ms_tst)
{
	t_table table;
	int		status;

	create_table(&table, (char *[]){"./philo", "6", "200", "97", "100", "10", NULL});
	status = run_test_suppressed(&table, table.nbr_philo);
	mu_assert_int_eq(0, status);
}

MU_TEST(unstable_5_3ms_tst)
{
	t_table table;
	int		status;

	create_table(&table, (char *[]){"./philo", "2", "180", "77", "100", "10", NULL});
	status = run_test_suppressed(&table, table.nbr_philo);
	mu_assert_int_eq(0, status);
}

MU_TEST(unstable_6_3ms_tst)
{
	t_table table;
	int		status;

	create_table(&table, (char *[]){"./philo", "4", "180", "77", "100", "10", NULL});
	status = run_test_suppressed(&table, table.nbr_philo);
	mu_assert_int_eq(0, status);
}

MU_TEST(unstable_7_3ms_tst)
{
	t_table table;
	int		status;

	create_table(&table, (char *[]){"./philo", "4", "1000", "497", "500", "5", NULL});
	status = run_test_suppressed(&table, table.nbr_philo);
	mu_assert_int_eq(0, status);
}

/******************************************************************************/
/*							TST 2 MS LEFT									   *
/******************************************************************************/

MU_TEST(unstable_1_2ms_tst)
{
	t_table table;
	int		status;

	create_table(&table, (char *[]){"./philo", "2", "100", "48", "50", "10", NULL});
	status = run_test_suppressed(&table, table.nbr_philo);
	mu_assert_int_eq(0, status);
}

MU_TEST(unstable_2_2ms_tst)
{
	t_table table;
	int		status;

	create_table(&table, (char *[]){"./philo", "2", "200", "98", "100", "10", NULL});
	status = run_test_suppressed(&table, table.nbr_philo);
	mu_assert_int_eq(0, status);
}

MU_TEST(unstable_3_2ms_tst)
{
	t_table table;
	int		status;

	create_table(&table, (char *[]){"./philo", "4", "200", "98", "100", "10", NULL});
	status = run_test_suppressed(&table, table.nbr_philo);
	mu_assert_int_eq(0, status);
}

MU_TEST(unstable_4_2ms_tst)
{
	t_table table;
	int		status;

	create_table(&table, (char *[]){"./philo", "6", "200", "98", "100", "10", NULL});
	status = run_test_suppressed(&table, table.nbr_philo);
	mu_assert_int_eq(0, status);
}

MU_TEST(unstable_5_2ms_tst)
{
	t_table table;
	int		status;

	create_table(&table, (char *[]){"./philo", "2", "180", "78", "100", "10", NULL});
	status = run_test_suppressed(&table, table.nbr_philo);
	mu_assert_int_eq(0, status);
}

MU_TEST(unstable_6_2ms_tst)
{
	t_table table;
	int		status;

	create_table(&table, (char *[]){"./philo", "4", "180", "78", "100", "10", NULL});
	status = run_test_suppressed(&table, table.nbr_philo);
	mu_assert_int_eq(0, status);
}

MU_TEST(unstable_7_2ms_tst)
{
	t_table table;
	int		status;

	create_table(&table, (char *[]){"./philo", "4", "1000", "498", "500", "5", NULL});
	status = run_test_suppressed(&table, table.nbr_philo);
	mu_assert_int_eq(0, status);
}


/******************************************************************************/
/*							TST 1 MS LEFT									   *
/******************************************************************************/

MU_TEST(unstable_1_1ms_tst)
{
	t_table table;
	int		status;

	create_table(&table, (char *[]){"./philo", "2", "100", "49", "50", "10", NULL});
	status = run_test_suppressed(&table, table.nbr_philo);
	mu_assert_int_eq(0, status);
}

MU_TEST(unstable_2_1ms_tst)
{
	t_table table;
	int		status;

	create_table(&table, (char *[]){"./philo", "2", "200", "99", "100", "10", NULL});
	status = run_test_suppressed(&table, table.nbr_philo);
	mu_assert_int_eq(0, status);
}

MU_TEST(unstable_3_1ms_tst)
{
	t_table table;
	int		status;

	create_table(&table, (char *[]){"./philo", "4", "200", "99", "100", "10", NULL});
	status = run_test_suppressed(&table, table.nbr_philo);
	mu_assert_int_eq(0, status);
}

MU_TEST(unstable_4_1ms_tst)
{
	t_table table;
	int		status;

	create_table(&table, (char *[]){"./philo", "6", "200", "99", "100", "10", NULL});
	status = run_test_suppressed(&table, table.nbr_philo);
	mu_assert_int_eq(0, status);
}

MU_TEST(unstable_5_1ms_tst)
{
	t_table table;
	int		status;

	create_table(&table, (char *[]){"./philo", "2", "180", "79", "100", "10", NULL});
	status = run_test_suppressed(&table, table.nbr_philo);
	mu_assert_int_eq(0, status);
}

MU_TEST(unstable_6_1ms_tst)
{
	t_table table;
	int		status;

	create_table(&table, (char *[]){"./philo", "4", "180", "79", "100", "10", NULL});
	status = run_test_suppressed(&table, table.nbr_philo);
	mu_assert_int_eq(0, status);
}

MU_TEST(unstable_7_1ms_tst)
{
	t_table table;
	int		status;

	create_table(&table, (char *[]){"./philo", "4", "1000", "499", "500", "5", NULL});
	status = run_test_suppressed(&table, table.nbr_philo);
	mu_assert_int_eq(0, status);
}

MU_TEST_SUITE(test_5ms_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	printf("\033[0;36m		running seven unstable tests\n\n");
	printf("\033[0;36m5 ms left\n");
	MU_RUN_TEST(unstable_1_5ms_tst);
	MU_RUN_TEST(unstable_2_5ms_tst);
	MU_RUN_TEST(unstable_3_5ms_tst);
	MU_RUN_TEST(unstable_4_5ms_tst);
	MU_RUN_TEST(unstable_5_5ms_tst);
	MU_RUN_TEST(unstable_6_5ms_tst);
	MU_RUN_TEST(unstable_7_5ms_tst);
}

MU_TEST_SUITE(test_3ms_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	printf("\n");
	printf("\033[0;36m3 ms left\n");
	MU_RUN_TEST(unstable_1_5ms_tst);
	MU_RUN_TEST(unstable_2_5ms_tst);
	MU_RUN_TEST(unstable_3_5ms_tst);
	MU_RUN_TEST(unstable_4_5ms_tst);
	MU_RUN_TEST(unstable_5_5ms_tst);
	MU_RUN_TEST(unstable_6_5ms_tst);
	MU_RUN_TEST(unstable_7_5ms_tst);
}

MU_TEST_SUITE(test_2ms_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	printf("\n");
	printf("\033[0;36m2 ms left\n");
	MU_RUN_TEST(unstable_1_2ms_tst);
	MU_RUN_TEST(unstable_2_2ms_tst);
	MU_RUN_TEST(unstable_3_2ms_tst);
	MU_RUN_TEST(unstable_4_2ms_tst);
	MU_RUN_TEST(unstable_5_2ms_tst);
	MU_RUN_TEST(unstable_6_2ms_tst);
	MU_RUN_TEST(unstable_7_2ms_tst);
}

MU_TEST_SUITE(test_1ms_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	printf("\n");
	printf("\033[0;36m1 ms left\n");
	MU_RUN_TEST(unstable_1_1ms_tst);
	MU_RUN_TEST(unstable_2_1ms_tst);
	MU_RUN_TEST(unstable_3_1ms_tst);
	MU_RUN_TEST(unstable_4_1ms_tst);
	MU_RUN_TEST(unstable_5_1ms_tst);
	MU_RUN_TEST(unstable_6_1ms_tst);
	MU_RUN_TEST(unstable_7_1ms_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	//MU_RUN_SUITE(test_5ms_suite);
	// MU_RUN_SUITE(test_3ms_suite);
	// MU_RUN_SUITE(test_2ms_suite);
	MU_RUN_SUITE(test_1ms_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
