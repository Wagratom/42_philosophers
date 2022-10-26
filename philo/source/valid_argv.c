/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:39:42 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/26 11:06:06 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

t_bool	is_negative(char *argv[])
{
	while (*argv)
	{
		if (*argv[0] == '-')
			return (TRUE);
		argv++;
	}
	return (FALSE);
}

t_bool	valid_argv(int argc, char	*argv[])
{
	if (argc < 5 || argc > 6)
		ft_putstr_err("Invalid number of arguments\n");
	if (ft_str_eq(argv[1], "0") || ft_str_eq(argv[5], "0"))
		exit(0);
	if (argv == NULL || *argv == NULL)
		ft_putstr_err("NULL argument list\n");
	if (ft_is_array_int(argv + 1) == FALSE)
		ft_putstr_err("Non-integer argument list\n");
	if (is_negative(argv))
		ft_putstr_err("Argument list possui numeros negativos\n");
	return (TRUE);
}
