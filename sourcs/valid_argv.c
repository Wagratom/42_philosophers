/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 11:30:42 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/19 10:50:36 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

t_bool	valid_argv(int argc, char **argv)
{
	if (argc != 5)
		return (FALSE);
		//printf("Invalid number of arguments\n");
	else if (ft_is_array_int(argv) == FALSE)
		return (FALSE);
		//printf("Invalid arguments\n");
	else
		return (TRUE);
	return (FALSE);
}
