//
// Created by chrre on 23-May-23.
//
#include "philosophers.h"

int philosophers(char *argv[], int argc)
{
    t_info  *info;

    info = (t_info *)malloc(sizeof(t_info));
    if (!info)
        return (-1);
    fill_info(argc, argv, info);
}