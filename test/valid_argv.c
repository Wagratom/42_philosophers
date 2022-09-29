/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 11:18:47 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/29 11:36:21 by wwallas-         ###   ########.fr       */
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

MU_TEST(invalid_argc)
{
	mu_assert_int_eq(FALSE, valid_argv(0, (char *[]){"10", NULL}));
	mu_assert_int_eq(FALSE, valid_argv(1, (char *[]){"10", NULL}));
	mu_assert_int_eq(FALSE, valid_argv(2, (char *[]){"10", NULL}));
	mu_assert_int_eq(FALSE, valid_argv(3, (char *[]){"10", NULL}));
	mu_assert_int_eq(FALSE, valid_argv(4, (char *[]){"10", NULL}));
	mu_assert_int_eq(FALSE, valid_argv(5, (char *[]){"10", NULL}));
	mu_assert_int_eq(FALSE, valid_argv(7, (char *[]){"10", NULL}));
	mu_assert_int_eq(FALSE, valid_argv(8, (char *[]){"10", NULL}));
	mu_assert_int_eq(FALSE, valid_argv(9, (char *[]){"10", NULL}));
	mu_assert_int_eq(FALSE, valid_argv(10, (char *[]){"10", NULL}));
}

MU_TEST_SUITE(valid_argv_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(invalid_argc);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(valid_argv_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
