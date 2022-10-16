/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:39:42 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/16 08:28:05 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static void msg_and_die(char	*messege)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(messege, 2);
	exit(EXIT_FAILURE);
}

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
	if (argc != 6)
		msg_and_die("Invalid number of arguments\n");
	if (argv == NULL || *argv == NULL)
		msg_and_die("NULL argument list\n");
	if (ft_is_array_int(argv + 1) == FALSE)
		msg_and_die("Non-integer argument list\n");
	if (is_negative(argv))
		msg_and_die("Argument list possui numeros negativos\n");
	return (TRUE);
}
