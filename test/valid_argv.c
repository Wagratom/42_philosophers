/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:17:18 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/19 11:04:00 by wwallas-         ###   ########.fr       */
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
	mu_assert_int_eq(FALSE, valid_argv(-5, (char *[]){NULL}));
	mu_assert_int_eq(FALSE, valid_argv(6, (char *[]){NULL}));
	mu_assert_int_eq(FALSE, valid_argv(8, (char *[]){NULL}));
	mu_assert_int_eq(FALSE, valid_argv(14, (char *[]){NULL}));
}

MU_TEST(false_argv_tst)
{
	mu_assert_int_eq(FALSE, valid_argv(5, (char *[]){NULL}));
	mu_assert_int_eq(FALSE, valid_argv(5, (char *[]){"a", NULL}));
	mu_assert_int_eq(FALSE, valid_argv(5, (char *[]){"10", "20", "30", "a", NULL}));
	mu_assert_int_eq(FALSE, valid_argv(5, (char *[]){"10", "20", "", "30", NULL}));
	mu_assert_int_eq(FALSE, valid_argv(5, (char *[]){"0", "1", "1", ";", NULL}));
	mu_assert_int_eq(FALSE, valid_argv(5, (char *[]){"0", "1", "1", "@", NULL}));
	mu_assert_int_eq(FALSE, valid_argv(5, (char *[]){"0", "1", "1", "#", NULL}));
	mu_assert_int_eq(FALSE, valid_argv(5, (char *[]){"0", "1", "1", "&", NULL}));
	mu_assert_int_eq(FALSE, valid_argv(5, (char *[]){"10", "20", "", NULL}));
	mu_assert_int_eq(FALSE, valid_argv(5, (char *[]){"2147483648"}));
	mu_assert_int_eq(FALSE, valid_argv(5, (char *[]){"-2147483649"}));
}

MU_TEST_SUITE(valid_tst)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(false_argc_tst);
	MU_RUN_TEST(false_argv_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(valid_tst);
	MU_REPORT();
	argc = argc;
	envp = envp;
	return (MU_EXIT_CODE);
}
