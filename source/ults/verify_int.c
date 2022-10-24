/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 23:06:50 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/24 10:37:06 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static char	*convert_number(char **nbr)
{
	if (nbr == NULL || *nbr == NULL)
		return (NULL);
	if (*nbr[0] == '+')
		(*nbr) = (*nbr + 1);
	return (ft_itoa(ft_atoi(*nbr)));
}

t_bool	ft_is_int_nbr(char *nbr)
{
	char	*nbr_conv;
	int		status;

	nbr_conv = convert_number(&nbr);
	status = ft_str_eq(nbr_conv, nbr);
	free(nbr_conv);
	return (status);
}

t_bool	ft_is_array_int(char	**array)
{
	if (array == NULL || *array == NULL)
		return (FALSE);
	while (*array)
	{
		if (ft_is_int_nbr(*array) == FALSE)
			return (FALSE);
		array++;
	}
	return (TRUE);
}
