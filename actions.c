/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:32:48 by crepou            #+#    #+#             */
/*   Updated: 2023/05/23 16:32:48 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*actions(void *args)
{
	(void)args;
	return (NULL);
}

void	action_print(t_info *info, t_philosopher *philosopher, char *str, long long timestamp)
{
	pthread_mutex_lock(&info->printing);
	printf("%lld philosopher %d %s\n", timestamp, philosopher->id, str);
	pthread_mutex_unlock(&info->printing);
}
