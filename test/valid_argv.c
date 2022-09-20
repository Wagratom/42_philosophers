/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:44:32 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/20 17:29:54 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
# include "../includes/philosophers.h"


pthread_t	t1, t2;

void	test_setup(void)
{
}
void	test_teardown(void)
{
}

MU_TEST(false_argc_tst)
{
	mu_assert_int_eq(FALSE, valid_argv(0, (char *[]){NULL}));
	mu_assert_int_eq(FALSE, valid_argv(1, (char *[]){NULL}));
	mu_assert_int_eq(FALSE, valid_argv(2, (char *[]){NULL}));
	mu_assert_int_eq(FALSE, valid_argv(3, (char *[]){NULL}));
	mu_assert_int_eq(FALSE, valid_argv(4, (char *[]){NULL}));
	mu_assert_int_eq(FALSE, valid_argv(6, (char *[]){NULL}));
	mu_assert_int_eq(FALSE, valid_argv(6, (char *[]){NULL}));
	mu_assert_int_eq(FALSE, valid_argv(8, (char *[]){NULL}));
	mu_assert_int_eq(FALSE, valid_argv(14, (char *[]){NULL}));
}

MU_TEST(false_argv_tst)
{
	mu_assert_int_eq(FALSE, valid_argv(6, (char *[]){NULL}));
	mu_assert_int_eq(FALSE, valid_argv(6, (char *[]){"a", NULL}));
	mu_assert_int_eq(FALSE, valid_argv(6, (char *[]){"10", "20", "30", "a", NULL}));
	mu_assert_int_eq(FALSE, valid_argv(6, (char *[]){"10", "20", "", "30", NULL}));
	mu_assert_int_eq(FALSE, valid_argv(6, (char *[]){"0", "1", "1", ";", NULL}));
	mu_assert_int_eq(FALSE, valid_argv(6, (char *[]){"0", "1", "1", "@", NULL}));
	mu_assert_int_eq(FALSE, valid_argv(6, (char *[]){"0", "1", "1", "#", NULL}));
	mu_assert_int_eq(FALSE, valid_argv(6, (char *[]){"0", "1", "1", "&", NULL}));
	mu_assert_int_eq(FALSE, valid_argv(6, (char *[]){"10", "20", "", "10", NULL}));
	mu_assert_int_eq(FALSE, valid_argv(6, (char *[]){"2147483648", "0", "0", "1", NULL}));
	mu_assert_int_eq(FALSE, valid_argv(6, (char *[]){"-2147483649", "8", "0", "1", NULL}));
	mu_assert_int_eq(FALSE, valid_argv(6, (char *[]){"110", "0", "1", "-20", NULL}));
	mu_assert_int_eq(FALSE, valid_argv(6, (char *[]){"110", "0", "-20", "-1", NULL}));
	mu_assert_int_eq(FALSE, valid_argv(6, (char *[]){"-20", "0", "110", "-1", NULL}));
}

MU_TEST(true_argv_tst)
{
	mu_assert_int_eq(TRUE, valid_argv(6, (char *[]){"0", NULL}));
	mu_assert_int_eq(TRUE, valid_argv(6, (char *[]){"0", "1", "3", "4", NULL}));
	mu_assert_int_eq(TRUE, valid_argv(6, (char *[]){"0", "10", "20", "30", NULL}));
	mu_assert_int_eq(TRUE, valid_argv(6, (char *[]){"+1", "+1", "+1", "+1", NULL}));
	mu_assert_int_eq(TRUE, valid_argv(6, (char *[]){"2147483647", "0", "2147483647", "20", NULL}));
	mu_assert_int_eq(TRUE, valid_argv(6, (char *[]){"100", "100", "100", "100", NULL}));
}

MU_TEST_SUITE(valid_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(false_argc_tst);
	MU_RUN_TEST(false_argv_tst);
	MU_RUN_TEST(true_argv_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(valid_suite);
	MU_REPORT();
	argc = argc;
	envp = envp;
	return (MU_EXIT_CODE);
}
