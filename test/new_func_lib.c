/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_func_lib.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 17:42:40 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/17 18:38:14 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thereads_tst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:17:18 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/17 17:42:21 by wwallas-         ###   ########.fr       */
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

MU_TEST(array_int_tst)
{
	mu_assert_int_eq(TRUE, ft_is_array_int((char *[]){"10", "0", "-10", NULL}));
	mu_assert_int_eq(TRUE , ft_is_array_int((char *[]){"-2147483648","2147483647", NULL}));
	mu_assert_int_eq(TRUE , ft_is_array_int((char *[]){"-1","-1","-1","-1","-1", NULL}));
	mu_assert_int_eq(TRUE , ft_is_array_int((char *[]){"+1","+1","+1","+1","+1", NULL}));

	mu_assert_int_eq(FALSE , ft_is_array_int((char *[]){"2147483648","2147483647", NULL}));
	mu_assert_int_eq(FALSE , ft_is_array_int((char *[]){"-2147483648","21474836480", NULL}));
	mu_assert_int_eq(FALSE , ft_is_array_int((char *[]){"-2147483648","a", NULL}));
	mu_assert_int_eq(FALSE , ft_is_array_int((char *[]){"0","-60", "a", NULL}));
	mu_assert_int_eq(FALSE , ft_is_array_int((char *[]){"","-60", "50", NULL}));
}

MU_TEST(str_ep_tst)
{
	mu_assert_int_eq(TRUE, ft_is);

}

MU_TEST_SUITE(lib_tst)
{
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	//MU_RUN_TEST(array_int_tst);
	MU_RUN_TEST(str_ep_tst);
}

MU_MAIN
{
	MU_DIVIDER;
	MU_RUN_SUITE(lib_tst);
	MU_REPORT();
	argc = argc;
	envp = envp;
	return (MU_EXIT_CODE);
}
