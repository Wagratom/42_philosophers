/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:17:19 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/24 17:10:49 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	ft_bzero(void *b, size_t len)
{
	while (len--)
		*(char *)b++ = '\0';
}

void	*ft_alloc_or_die(size_t itens, size_t size)
{
	void	*ptr;

	ptr = malloc(itens * size);
	if (ptr != NULL)
		return (ptr);
	write(2, "Erro em alocar memória\n", 23);
	exit(EXIT_FAILURE);
}

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*rtn;
	int		result;

	if (!nitems || !size)
		return (NULL);
	result = nitems * size;
	if ((result / nitems) != size)
		return (NULL);
	rtn = ft_alloc_or_die(nitems, size);
	ft_bzero(rtn, nitems * size);
	return (rtn);
}
