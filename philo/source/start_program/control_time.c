/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 12:37:42 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/24 11:53:00 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	time_start(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000 + time.tv_usec / 1000) - time_init());
}

int	*control_time(void)
{
	static int	_time;

	return (&_time);
}

void	set_time_init(int time)
{
	*control_time() = time;
}

int	time_init(void)
{
	return (*(control_time()));
}
