/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** mlcircle
*/

#include "mlsf.h"

void mlcircle_set_hover(mlcircle *circle, sfVector2f pos,
float radius, sfColor color)
{
    circle->pos_hover = pos;
    circle->radius_hover = radius;
    circle->color_hover = color;
}

void mlcircle_set_click(mlcircle *circle, sfVector2f pos,
float radius, sfColor color)
{
    circle->pos_click = pos;
    circle->radius_click = radius;
    circle->color_click = color;
}

void mlcircle_destroy(mlcircle *circle)
{
    sfCircleShape_destroy(circle->circle);
    free(circle);
}
