/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** mlevent
*/

#include "mlsf.h"

int mlevent_quit(mlwindow *window)
{
    if (window->event.type == sfEvtClosed) {
        sfRenderWindow_close(window->window);
        window->isopen = 0;
        return 1;
    }
    if (window->event.type == sfEvtKeyPressed &&
    window->event.key.code == sfKeyEscape) {
        sfRenderWindow_close(window->window);
        window->isopen = 0;
        return 1;
    }
    return 0;
}

int mlevent_key_pressed(mlwindow *window, sfKeyCode key)
{
    if (window->event.type == sfEvtKeyPressed && window->event.key.code == key)
        return 1;
    return 0;
}

int mlevent_mouse_pressed(mlwindow *window, sfMouseButton button)
{
    if (window->event.type == sfEvtMouseButtonPressed &&
    window->event.mouseButton.button == button) {
        window->mouse_pressed = 1;
        return 1;
    }
    window->mouse_pressed = 0;
    return 0;
}
