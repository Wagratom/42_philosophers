/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:17:43 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/24 12:36:30 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTE_H
# define TESTE_H
#include "../../include/philosophers.h"

void restore_static(void)
{
	*create_philo(NULL, NULL, -1) = 0;
}

#endif
