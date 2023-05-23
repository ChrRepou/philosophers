/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:25:30 by crepou            #+#    #+#             */
/*   Updated: 2023/05/23 16:25:30 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	create_mutex(t_info *info)
{
	int	philos;
	int	i;

	philos = info->number_of_philos;
	info->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * info->number_of_philos);
	i = -1;
	while (++i < philos)
	{
		if (pthread_mutex_init(&(info->forks[i]), NULL))
			return (1);
	}
	if (pthread_mutex_init(&info->printing, NULL))
		return (1);
	return (0);
}

void	initialize_philo(t_philosopher *philo, int i, int number_of_philos)
{
	philo->left_fork = i;
	philo->right_fork = (i + 1) % number_of_philos;
	philo->times_ate = 0;
	philo->id = i;
	philo->last_time_ate = get_curr_time();
}

int	create_philosophers(t_info *info)
{
	int	philos;
	int	i;

	philos = info->number_of_philos;
	i = -1;
	info->philos = (t_philosopher *)malloc(sizeof(t_philosopher) * info->number_of_philos);
	while (++i < philos)
	{
		initialize_philo(&info->philos[i], i, info->number_of_philos);
		if (pthread_create(&info->philos[i].philosopher, NULL, &actions, info))
			return (1);
	}
	return (0);
}

int	fill_info(int argc, char *argv[], t_info *info)
{
	info->time_to_die = atoi(argv[2]);
	info->time_to_eat = atoi(argv[3]);
	info->time_to_sleep = atoi(argv[4]);
	info->number_of_philos = atoi(argv[1]);
	info->philo_is_dead = 0;
	if (argc == 6)
		info->number_of_meals = atoi(argv[5]);
	else
		info->number_of_meals = 1;
	if (info->time_to_die < 0 || info->time_to_eat < 0
		|| info->time_to_sleep < 0 || info->number_of_meals <= 0
		|| info->number_of_philos < 2)
		return (1);
	if (create_mutex(info) || create_philosophers(info))
		return (1);
	return (0);
}
