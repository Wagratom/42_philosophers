/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 11:30:42 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/20 12:49:13 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static t_bool	is_positive(char **array)
{
	while (*array)
	{
		if (*array[0] == '-')
			return (FALSE);
		array++;
	}
	return (TRUE);
}

t_bool	valid_argv(int argc, char **argv)
{
	if (argc != 6)
		return (FALSE);
		//printf("Invalid number of arguments\n");
	if (ft_is_array_int(argv) == FALSE)
		return (FALSE);
		//printf("Invalid arguments\n");
	if(is_positive(argv) == FALSE)
		return (FALSE);
		//printf("All arguments must be positive\n");
	return (TRUE);
}
