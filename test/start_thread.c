/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 17:35:54 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/22 17:39:13 by wwallas-         ###   ########.fr       */
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

MU_TEST(wait_philo_eat_tst)
{
	t_table				*table;
	pthread_t			p1, p2;
	pthread_mutex_t		mutex;


	pthread_mutex_init(&mutex, NULL);
	table = creat_table((char *[]){"10","10", "10", "1000", "10", "10", NULL});
	table->mutex = &mutex;
	new_thread(&p1, &start_thread, table);
	new_thread(&p2, &start_thread, table);
	pthread_join(p1, NULL);
	pthread_join(p2, NULL);
}

MU_TEST_SUITE(test_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(wait_philo_eat_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
