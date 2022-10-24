/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guardian.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 08:25:51 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/23 18:17:39 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minunit.h"
# include "../../include/philosophers.h"

void	test_setup(void)
{
}
void	test_teardown(void)
{
}

MU_TEST(die_philos)
{
	pthread_mutex_t		*next;
	int					index = -1;
	t_table 			 table;

	create_table(&table, (char *[]){"a.out", "3", "3", "1", "2", "5", NULL});

	while(++index < table.nbr_philo)
	{
		mu_assert_int_eq(table.philos[index].die, 3);
		*table.guardian.die_philos[index] = 0;
	}
	index = -1;
	while(++index < table.nbr_philo)
		mu_assert_int_eq(table.philos[index].die, 0);
	restore_static();
	destroy_table(&table, table.nbr_philo);
}

MU_TEST(link_die_table)
{
	t_table table;

	create_table(&table, (char *[]){"a.out", "3", "3", "1", "2", "5", NULL});
	mu_assert_int_eq(table.die, FALSE);
	*table.guardian.die_table = TRUE;
	mu_assert_int_eq(table.die, TRUE);
	restore_static();
	destroy_table(&table, table.nbr_philo);
}

MU_TEST(die_protection)
{
	t_table table;

	create_table(&table, (char *[]){"a.out", "3", "3", "1", "2", "5", NULL});
	mu_check(&table.die_protection == table.guardian.die_protection);
	mu_check(&table.die_protection == table.philos[0].die_protection);
	restore_static();
	destroy_table(&table, table.nbr_philo);
}

MU_TEST(size)
{
	t_table table;

	create_table(&table, (char *[]){"a.out", "3", "3", "1", "2", "5", NULL});
	mu_assert_int_eq(table.guardian.size, 3);
	restore_static();
	destroy_table(&table, table.nbr_philo);
}


MU_TEST_SUITE(create_table_suite)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(die_philos);
	MU_RUN_TEST(link_die_table);
	MU_RUN_TEST(die_protection);
	MU_RUN_TEST(size);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(create_table_suite);
	MU_REPORT();
	return (MU_EXIT_CODE);
}
