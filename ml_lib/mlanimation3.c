/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** mlanimation
*/

#include "mlsf.h"

void mlanimation_display(mlwindow *window, mlanimation *animation)
{
    mlsprite_display(window, animation->sprite);
}

void mlanimation_play(mlanimation *animation)
{
    animation->is_play = 1;
    animation->is_end = 0;
    animation->is_pause = 0;
    animation->is_stop = 0;
}

void mlanimation_pause(mlanimation *animation)
{
    animation->is_play = 0;
    animation->is_pause = 1;
}

void mlanimation_stop(mlanimation *animation)
{
    animation->is_play = 0;
    animation->is_stop = 1;
    animation->current_frame = 0;
    animation->rect.left = 0;
    sfSprite_setTextureRect(animation->sprite->sprite, animation->rect);
}
