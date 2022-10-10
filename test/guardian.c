/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guardian.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:46:45 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/10 13:46:50 by wwallas-         ###   ########.fr       */
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

MU_TEST(template_tst)
{
	t_table	*table;
	int		index;

	table =  creat_table((char *[]){"a.out", "5", "3", "1", "2", "5", NULL});
	index = -1;
	while(++index < 5)
		mu_assert_int_eq(0, pthread_mutex_lock(&table->forks[index]));
	//destroy_table(0);
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
