/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** mlcircle
*/

#include "mlsf.h"

void mlcircle_display(mlwindow *window, mlcircle *circle)
{
    if (circle->is_click == 0 && circle->is_hover == 0) {
        sfCircleShape_setFillColor(circle->circle, circle->color);
        sfCircleShape_setPosition(circle->circle, circle->pos);
        sfCircleShape_setRadius(circle->circle, circle->radius);
    }
    sfRenderWindow_drawCircleShape(window->window, circle->circle, NULL);
}

void mlcircle_update_next(mlcircle *circle)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        circle->is_click = 1;
        sfCircleShape_setPosition(circle->circle, circle->pos_click);
        sfCircleShape_setRadius(circle->circle, circle->radius_click);
        sfCircleShape_setFillColor(circle->circle, circle->color_click);
    } else {
        circle->is_click = 0;
        sfCircleShape_setPosition(circle->circle, circle->pos_hover);
        sfCircleShape_setRadius(circle->circle, circle->radius_hover);
        sfCircleShape_setFillColor(circle->circle, circle->color_hover);
    }
}

void mlcircle_update(mlwindow *window, mlcircle *circle)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window->window);
    sfVector2f pos = sfCircleShape_getPosition(circle->circle);
    float radius = sfCircleShape_getRadius(circle->circle);
    if (mouse.x >= pos.x && mouse.x <= pos.x + radius * 2 &&
    mouse.y >= pos.y && mouse.y <= pos.y + radius * 2) {
        circle->is_hover = 1;
        mlcircle_update_next(circle);
    } else {
        circle->is_hover = 0;
        sfCircleShape_setPosition(circle->circle, circle->pos);
        sfCircleShape_setRadius(circle->circle, circle->radius);
        sfCircleShape_setFillColor(circle->circle, circle->color);
    }
}

mlcircle *mlcircle_create(sfVector2f pos, float radius, sfColor color)
{
    mlcircle *circle = malloc(sizeof(mlcircle));
    circle->pos = pos;
    circle->pos_hover = pos;
    circle->pos_click = pos;
    circle->radius = radius;
    circle->radius_hover = radius;
    circle->radius_click = radius;
    circle->color = color;
    circle->color_hover = color;
    circle->color_click = color;
    circle->is_hover = 0;
    circle->is_click = 0;
    circle->circle = sfCircleShape_create();
    sfCircleShape_setPosition(circle->circle, circle->pos);
    sfCircleShape_setRadius(circle->circle, circle->radius);
    sfCircleShape_setFillColor(circle->circle, circle->color);
    return circle;
}
