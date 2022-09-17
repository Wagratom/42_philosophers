/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thereads_tst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:17:18 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/16 22:33:29 by wwallas-         ###   ########.fr       */
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

MU_TEST(new_thereds)
{
	mu_assert_int_eq(1, new_thread(&t1, &routinee));
	// mu_assert_int_eq(1, new_thread(&t2, &routinee));
	// pthread_join(t1, NULL);
	// pthread_join(t2, NULL);


	// mu_assert_int_eq(0, new_thread(&t1, NULL));
	// mu_assert_int_eq(0, new_thread(&t2, NULL));

	// mu_assert_int_eq(0, new_thread(&t2, NULL));
	// mu_assert_int_eq(0, new_thread(&t2, NULL));


}

MU_TEST_SUITE(theread_tst)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(new_thereds);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(theread_tst);
	MU_REPORT();
	argc = argc;
	envp = envp;
	return (MU_EXIT_CODE);
}
