/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** mlanimation
*/

#include "mlsf.h"

void mlanimation_reverse(mlanimation *animation)
{
    animation->is_reverse = 1;
}

void mlanimation_normal(mlanimation *animation)
{
    animation->is_reverse = 0;
}

void mlanimation_set_frame(mlanimation *animation, int frame)
{
    animation->current_frame = frame;
    animation->rect.left = animation->current_frame * animation->rect.width;
    sfSprite_setTextureRect(animation->sprite->sprite, animation->rect);
}

void mlanimation_set_loop(mlanimation *animation, int is_loop)
{
    animation->is_loop = is_loop;
}

void mlanimation_set_position(mlanimation *animation, sfVector2f position)
{
    mlsprite_set_position(animation->sprite, position);
}
