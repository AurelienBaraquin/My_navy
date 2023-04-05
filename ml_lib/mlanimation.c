/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** mlanimation
*/

#include "mlsf.h"

mlanimation *mlanimation_create(mlsprite *sprite, int nb_frame, int is_loop)
{
    mlanimation *animation = malloc(sizeof(mlanimation));
    animation->sprite = sprite;
    animation->rect = sprite->rect;
    animation->nb_frame = nb_frame;
    animation->current_frame = 0;
    animation->is_loop = is_loop;
    animation->is_play = 0;
    animation->is_end = 0;
    animation->is_reverse = 0;
    animation->is_pause = 0;
    animation->is_stop = 0;
    animation->is_click = 0;
    animation->is_hover = 0;
    return animation;
}

void mlanimation_destroy(mlanimation *animation)
{
    mlsprite_destroy(animation->sprite);
    free(animation);
}

void ml_animation_notreverse(mlanimation *animation)
{
    animation->current_frame++;
    if (animation->current_frame >= animation->nb_frame) {
        if (animation->is_loop == 1)
            animation->current_frame = 0;
        else
            animation->is_end = 1;
    }
}

void ml_animation_isreverse(mlanimation *animation)
{
    animation->current_frame--;
    if (animation->current_frame <= 0) {
        if (animation->is_loop == 1)
            animation->current_frame = animation->nb_frame - 1;
        else
            animation->is_end = 1;
    }
}

int mlanimation_update(mlwindow *window, mlanimation *animation)
{
    if (animation->is_end == 1 && animation->is_loop == 0) {
        animation->is_play = 0;
        return -1;
    }
    if (animation->is_play == 1) {
        if (animation->is_reverse == 0)
            ml_animation_notreverse(animation);
        else
            ml_animation_isreverse(animation);
        animation->rect.left = animation->current_frame * animation->rect.width;
        sfSprite_setTextureRect(animation->sprite->sprite, animation->rect);
    }
    mlsprite_update(window, animation->sprite);
    return animation->current_frame;
}
