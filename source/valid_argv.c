/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:39:42 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/30 21:54:29 by wwallas-         ###   ########.fr       */
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
	if (argc != 6)
		return (FALSE);
	if (argv == NULL || *argv == NULL)
		return (FALSE);
	if (ft_is_array_int(argv) == FALSE)
		return (FALSE);
	if (is_negative(argv))
		return (FALSE);
	return (TRUE);
}
