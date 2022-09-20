/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:28:36 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/20 17:30:26 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
# include "../includes/philosophers.h"

void	test_setup(void)
{
}
void	test_teardown(void)
{
}

MU_TEST(start_filo_tst)
{
	mu_assert_int_eq(42, 42);
}

MU_TEST_SUITE(philo_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(start_filo_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(philo_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
