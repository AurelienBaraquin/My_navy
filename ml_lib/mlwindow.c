/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** mlwindow
*/

#include "mlsf.h"

void mlwindow_close(mlwindow *window)
{
    sfRenderWindow_close(window->window);
    window->isopen = 0;
}

void mlwindow_display(mlwindow *window)
{
    sfRenderWindow_setFramerateLimit(window->window, window->fps);
    sfRenderWindow_display(window->window);
}

void mlwindow_clear(mlwindow *window)
{
    sfRenderWindow_clear(window->window, window->color);
}

mlwindow *mlwindow_create(int width, int height, char *name, int fps)
{
    mlwindow *window = malloc(sizeof(mlwindow));
    window->width = width;
    window->height = height;
    window->name = name;
    window->isopen = 1;
    window->fps = fps;
    window->color = sfBlack;
    window->mode = (sfVideoMode){width, height, 32};
    window->window = sfRenderWindow_create(window->mode,
    name, sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(window->window, fps);
    return window;
}

void mlwindow_destroy(mlwindow *window)
{
    sfRenderWindow_destroy(window->window);
    free(window);
}
