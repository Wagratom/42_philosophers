/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_array_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 12:03:05 by wwallas-          #+#    #+#             */
/*   Updated: 2022/09/17 18:12:38 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <philosophers.h>

t_bool	ft_is_array_int(char	**array)
{
	if (array == NULL || *array == NULL)
		return (FALSE);
	while (*array)
	{
		if(ft_is_int_nbr(*array) == FALSE)
			return (FALSE);
		array++;
	}
	return (TRUE);
}
