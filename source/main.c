/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwallas- <wwallas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:39:31 by wwallas-          #+#    #+#             */
/*   Updated: 2022/10/05 15:57:39 by wwallas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	main(int argc, char *argv[])
{
	valid_argv(argc, argv);
	creat_table(argv);
	init_ths();
	return (0);
}
