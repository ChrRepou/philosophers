/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:24:34 by crepou            #+#    #+#             */
/*   Updated: 2023/05/23 17:36:37 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	join_threads(t_info *info)
{
	int	i;
	int	philos;

	i = -1;
	philos = info->number_of_philos;
	while (++i < philos)
	{
		if (pthread_join(info->philos[i].philosopher, NULL))
			return (1);
	}
	return (0);
}

int	destroy_threads(t_info *info)
{
	int	i;
	int	philos;

	i = -1;
	philos = info->number_of_philos;
	while (++i < philos)
	{
		if (pthread_detach(info->philos[i].philosopher))
			return (1);
	}
	return (0);
}
