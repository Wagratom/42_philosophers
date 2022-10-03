/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:07:50 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/03 13:37:09 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	destroy_table(t_table **table, int status)
{
	free((*table)->forks);
	free((*table)->philos);
	free((*table)->threads);
	free(*table);
	(*table) = NULL;
}
