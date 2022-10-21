/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:39:42 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/20 18:15:50 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	ft_puterr(char	*messege)
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
	if (argc < 5 || argc > 6)
		ft_puterr("Invalid number of arguments\n");
	if (argv == NULL || *argv == NULL)
		ft_puterr("NULL argument list\n");
	if (ft_is_array_int(argv + 1) == FALSE)
		ft_puterr("Non-integer argument list\n");
	if (is_negative(argv))
		ft_puterr("Argument list possui numeros negativos\n");
	return (TRUE);
}
