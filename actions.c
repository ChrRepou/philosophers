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
	pthread_mutex_lock(&info->forks[philosopher->left_fork]);
	if (info->philo_is_dead)
		return ;
	action_print(info, philosopher, "has taken a fork", time_diff(info->init_time));
	if (info->number_of_philos < 2)
	{
		info->philo_is_dead = 1;
		usleep(info->time_to_die * 1000);
		action_print(info, philosopher, "is dead", time_diff(info->init_time));
		return ;
	}
	pthread_mutex_lock(&info->forks[philosopher->right_fork]);
	if (info->philo_is_dead)
		return ;
	action_print(info, philosopher, "has taken a fork", time_diff(info->init_time));
	pthread_mutex_lock(&info->eating);
	action_print(info, philosopher, "is eating", time_diff(info->init_time));
	pthread_mutex_unlock(&info->eating);
	usleep(1000 * info->time_to_eat);
	philosopher->last_time_ate = time_diff(info->init_time);
	philosopher->times_ate++;
	pthread_mutex_unlock(&info->forks[philosopher->left_fork]);
	pthread_mutex_unlock(&info->forks[philosopher->right_fork]);
}

void	check_if_dead(t_info *info)
{
	int	i;

	i = -1;
	while (!info->all_satisfied)
	{
		while (++i < info->number_of_philos && !info->philo_is_dead)
		{
			pthread_mutex_lock(&info->eating);
			if (time_diff(info->init_time) - info->philos[i].last_time_ate > (long long int)info->time_to_die)
			{
				action_print(info, &info->philos[i], "is dead", time_diff(info->init_time));
				info->philo_is_dead = 1;
				break ;
			}
			pthread_mutex_unlock(&info->eating);
			usleep(250);
		}
		if (info->philo_is_dead)
			break ;
		i = 0;
		while (info->number_of_meals != 0 && i < info->number_of_philos && info->philos[i].times_ate >= info->number_of_meals)
			i++;
		if (i == info->number_of_philos)
			info->all_satisfied = 1;
	}
}

void	*actions(void *args)
{
	t_info	*info;
	int		id;

	info = (*(t_args *)args).info;
	id = (*(t_args *)args).id;
	if (id % 2)
		usleep(15000);
	while (!info->philo_is_dead)
	{
		eat(info, &info->philos[id]);
		if (info->philo_is_dead)
			break ;
		if (info->all_satisfied)
			break ;
		action_print(info, &info->philos[id], "is sleeping", time_diff(info->init_time));
		usleep(1000 * info->time_to_sleep);
		if (info->philo_is_dead)
			return (NULL);
		action_print(info, &info->philos[id], "is thinking", time_diff(info->init_time));
	}
	return (NULL);
}

void	action_print(t_info *info, t_philosopher *philosopher, char *str, long long timestamp)
{
	pthread_mutex_lock(&info->printing);
	printf("%lld philosopher %d %s\n", timestamp, philosopher->id, str);
	pthread_mutex_unlock(&info->printing);
}
