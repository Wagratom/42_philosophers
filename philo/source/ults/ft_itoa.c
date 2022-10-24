/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:18:53 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/24 10:42:06 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static unsigned int	convert_positive(int nbr)
{
	unsigned int	aux;

	aux = nbr;
	if (nbr < 0)
		aux = -aux;
	return (aux);
}

static char	*alloc_ptr(int size)
{
	char	*ptr;

	ptr = (char *)ft_calloc((size + 1), 1);
	ptr[size] = '\0';
	return (ptr);
}

static char	*fill_ptr(char *ptr, unsigned int nbr, int size)
{
	while (nbr)
	{
		ptr[--size] = (nbr % 10) + 48;
		nbr /= 10;
	}
	return (ptr);
}

static char	*convert_numb(int nbr, int is_negative)
{
	unsigned int	aux;
	int				numb_house;
	char			*ptr;

	aux = convert_positive(nbr);
	numb_house = ft_numb_house(aux, 10) + is_negative;
	ptr = alloc_ptr(numb_house);
	ptr = fill_ptr(ptr, aux, numb_house);
	if (is_negative)
		ptr[0] = '-';
	return (ptr);
}

char	*ft_itoa(int n)
{
	if (n == 0)
		return (ft_strdup("0"));
	return (convert_numb(n, (n < 0)));
}
