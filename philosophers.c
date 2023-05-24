/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:44:42 by crepou            #+#    #+#             */
/*   Updated: 2023/05/23 16:44:42 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	philosophers(char *argv[], int argc)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info || fill_info(argc, argv, info))
		return (-1);
	check_if_dead(info);
	if (join_threads(info))
		return (-1);
	if (destroy_mutexes(info))
		return (-1);
	return (0);
}
