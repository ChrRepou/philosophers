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
	if (!info || fill_info(argc, argv, info) || join_threads(info))
		return (-1);
	while(!info->philo_is_dead)
	{
		//
		
		action_print(info, &info->philos[0], "is eating", get_curr_time());
		info->philo_is_dead = 1;
	}
	return (0);
}
