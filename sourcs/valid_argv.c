/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 11:30:42 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/17 23:16:24 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

t_bool	valid_argv(char argc, char argv)
{
	if (argc != 4)
		printf("Invalid number of arguments");
	else if (ft_is_array_int(argv) == FALSE)
		printf("Invalid arguments");
	else
		return (TRUE);
	return (FALSE);
}
