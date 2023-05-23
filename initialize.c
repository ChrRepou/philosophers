//
// Created by chrre on 23-May-23.
//
#include "philosophers.h"

int create_mutex(t_info *info)
{
    int philos;
    int i;

    philos = info->philos;
    i = -1;
    while (++i < philos)
    {
        if(pthread_mutex_init(info->forks[i], NULL))
            return (1);
    }
    return (0);
}

void    fill_info(int argc, char *argv[], t_info *info)
{
    info->philos = atoi(argv[1]);
    info->time_to_die = atoi(argv[2]);
    info->time_to_eat = atoi(argv[3]);
    info->time_to_sleep = atoi(argv[4]);
    if (argc == 6)
        info->number_of_meals = atoi(argv[5]);
}