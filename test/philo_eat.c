/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:14:25 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/22 17:45:14 by wwallas-         ###   ########.fr       */
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

MU_TEST(philo_eat_tst)
{
	pthread_mutex_t		mutex;
	t_table				*table;

	table = creat_table((char *[]){"10","10", "10", "1000", "10", "10", NULL});
	pthread_mutex_init(&mutex, NULL);
	table->mutex = &mutex;

	mu_assert_int_eq(TRUE, philo_eat(table));

	table = creat_table((char *[]){"10","10", "10", "-1000", "10", "10", NULL});
	mu_assert_int_eq(FALSE, philo_eat(table));
}

MU_TEST_SUITE(test_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(philo_eat_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
