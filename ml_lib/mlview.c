/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** mlview
*/

#include "mlsf.h"

mlview *mlview_create(sfVector2f pos, sfVector2f size)
{
    mlview *view = malloc(sizeof(mlview));
    view->view = sfView_create();
    view->pos = pos;
    view->size = size;
    view->center = (sfVector2f){size.x / 2, size.y / 2};
    view->rotation = (sfVector2f){0, 0};
    view->zoom = (sfVector2f){1, 1};
    sfView_setSize(view->view, size);
    sfView_setCenter(view->view, view->center);
    return (view);
}

void mlview_display(mlwindow *window, mlview *view)
{
    sfView_setCenter(view->view, view->center);
    sfView_setRotation(view->view, view->rotation.x);
    sfView_setSize(view->view, view->size);
    sfRenderWindow_setView(window->window, view->view);
}

void mlview_destroy(mlview *view)
{
    sfView_destroy(view->view);
    free(view);
}
