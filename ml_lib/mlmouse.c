/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** mlmouse
*/

#include "mlsf.h"

void mlmouse_update(mlwindow *window, mlmouse *mouse)
{
    mouse->pos_i = sfMouse_getPositionRenderWindow(window->window);
    mouse->pos_f.x = mouse->pos_i.x;
    mouse->pos_f.y = mouse->pos_i.y;
    mouse->is_pressed = window->mouse_pressed;
}

mlmouse *mlmouse_create(mlwindow *window)
{
    mlmouse *mouse = malloc(sizeof(mlmouse));
    mouse->pos_i = sfMouse_getPositionRenderWindow(window->window);
    mouse->pos_f.x = mouse->pos_i.x;
    mouse->pos_f.y = mouse->pos_i.y;
    return mouse;
}
