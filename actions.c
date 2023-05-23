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

void	eat(t_info *info, t_philosopher *philosopher)
{
	int	id;

	id = philosopher->id;
	pthread_mutex_lock(&philosopher->left_fork);
	pthread_mutex_lock(&philosopher->right_fork);
	pthread_mutex_lock(&info->eating);
	action_print(info, philosopher, "is eating", time_diff(info->init_time));
	pthread_mutex_unlock(&info->eating);
	usleep(1000 * info->time_to_eat);
	philosopher->last_time_ate = time_diff(info->init_time);
	philosopher->times_ate++;
	pthread_mutex_unlock(&philosopher->left_fork);
	pthread_mutex_unlock(&philosopher->right_fork);
}

void	*actions(void *args)
{
	t_info	*info;

	info = (t_info *)args;
	
	return (NULL);
}

void	action_print(t_info *info, t_philosopher *philosopher, char *str, long long timestamp)
{
	pthread_mutex_lock(&info->printing);
	printf("%lld philosopher %d %s\n", timestamp, philosopher->id, str);
	pthread_mutex_unlock(&info->printing);
}
