/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:16:55 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/24 10:41:58 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	avance_isspace(const char **nptr)
{
	while ((**nptr >= 9 && **nptr <= 13) || **nptr == 32)
		(*nptr)++;
}

int	solve_signs(const char **nptr)
{
	int		sig;

	sig = 1;
	if (**nptr == '-')
		sig = -1;
	if (**nptr == '-' || **nptr == '+')
		(*nptr)++;
	return (sig);
}

int	convert_nunber(const char *nptr)
{
	int		result;

	result = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = (*nptr - 48) + (result * 10);
		nptr++;
	}
	return (result);
}

int	ft_atoi(const char *nptr)
{
	int	result;
	int	sig;

	avance_isspace(&nptr);
	sig = solve_signs(&nptr);
	result = convert_nunber(nptr);
	result *= sig;
	return (result);
}
