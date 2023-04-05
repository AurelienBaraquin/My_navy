/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** mlclock
*/

#include "mlsf.h"

float mlclock_update(mlclock *clock)
{
    clock->time = sfClock_getElapsedTime(clock->clock);
    clock->seconds = clock->time.microseconds / 1000000.0;
    return clock->seconds;
}

void mlclock_restart(mlclock *clock)
{
    sfClock_restart(clock->clock);
}

mlclock *mlclock_create(void)
{
    mlclock *clock = malloc(sizeof(mlclock));
    clock->clock = sfClock_create();
    clock->time = sfClock_getElapsedTime(clock->clock);
    clock->seconds = clock->time.microseconds / 1000000.0;
    return clock;
}
