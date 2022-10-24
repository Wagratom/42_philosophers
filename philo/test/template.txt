/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 08:25:51 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/29 11:07:55 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minunit.h"

int	foo;

void	test_setup(void)
{
}
void	test_teardown(void)
{
}

MU_TEST(template_tst)
{
	foo = 42;
	mu_assert_int_eq(foo, 42);
}

MU_TEST_SUITE(test_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(template_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
