//
// Created by chrre on 23-May-23.
//

#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_philosopher
{
    int         left_fork;
    int         right_fork;
    long long   last_time_ate;
    int         times_ate;
    int         id;
}               t_philosopher;

typedef struct  s_info
{
    t_philosopher *philos;
    pthread_mutex_t *forks;
    int             time_to_eat;
    int             time_to_sleep;
    int             time_to_die;
    int             number_of_meals;
    int             number_of_philos;
    int             philo_is_dead;
}               t_info;

int philosophers(char *argv[], int argc);
void    fill_info(int argc, char *argv[], t_info *info);
int create_mutex(t_info *info);

#endif