/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:28:02 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/24 10:51:27 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	s_dest;
	size_t	s_src;
	size_t	i;

	s_dest = ft_strlen(dst);
	if (size <= s_dest)
		return (ft_strlen(src) + size);
	size -= s_dest + 1;
	i = -1;
	while (++i < size && src[i])
		dst[s_dest + i] = src[i];
	dst[s_dest + i] = '\0';
	s_src = ft_strlen(src);
	return (s_src + s_dest);
}

char	*ft_strdup(const char *s)
{
	char	*cpy;
	int		len;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s) + 1;
	cpy = (char *) ft_calloc(len, 1);
	ft_strlcat(cpy, s, len);
	return (cpy);
}
