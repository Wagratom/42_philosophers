/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 08:25:51 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/03 10:47:50 by wwallas-         ###   ########.fr       */
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

MU_TEST(basic_tst)
{
	t_table *table;
	int		index;


	table = creat_table((char *[]){"a.out", "2", "3", "1", "2", "5", NULL});
	init_ths(&table);
	destroy_table(&table);
}

MU_TEST(medio_tst)
{
	t_table *table;
	int		index;


	table = creat_table((char *[]){"a.out", "4", "500", "200", "200", "5", NULL});
	init_ths(&table);
	destroy_table(&table);
}

MU_TEST_SUITE(test_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	//MU_RUN_TEST(basic_tst);
	MU_RUN_TEST(medio_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
