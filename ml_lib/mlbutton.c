/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** mlbutton
*/

#include "mlsf.h"

void mlbutton_display(mlwindow *window, mlbutton *button)
{
    if (button->is_hover == 0 && button->is_click == 0) {
        sfRectangleShape_setFillColor(button->rect, button->color);
        sfRectangleShape_setPosition(button->rect, button->pos);
        sfRectangleShape_setSize(button->rect, button->size);
    }
    sfRenderWindow_drawRectangleShape(window->window, button->rect, NULL);
    if (button->text != NULL)
        mltext_display(window, button->text);
}

void mlbutton_update_next(mlbutton *button)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        button->is_click = 1;
        sfRectangleShape_setFillColor(button->rect, button->color_click);
        sfRectangleShape_setPosition(button->rect, button->pos_click);
        sfRectangleShape_setSize(button->rect, button->size_click);
    } else {
        button->is_click = 0;
        sfRectangleShape_setFillColor(button->rect, button->color_hover);
        sfRectangleShape_setPosition(button->rect, button->pos_hover);
        sfRectangleShape_setSize(button->rect, button->size_hover);
    }
}

void mlbutton_update(sfWindow *window, mlbutton *button)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    sfVector2f pos = sfRectangleShape_getPosition(button->rect);
    sfVector2f size = sfRectangleShape_getSize(button->rect);
    if (mouse.x >= pos.x && mouse.x <= pos.x + size.x && mouse.y >= pos.y
    && mouse.y <= pos.y + size.y) {
        button->is_hover = 1;
        sfRectangleShape_setFillColor(button->rect, button->color_hover);
        mlbutton_update_next(button);
    } else {
        button->is_hover = 0;
        sfRectangleShape_setFillColor(button->rect, button->color);
        sfRectangleShape_setPosition(button->rect, button->pos);
        sfRectangleShape_setSize(button->rect, button->size);
    }
}

mlbutton *mlbutton_create(sfVector2f pos, sfVector2f size, sfColor color)
{
    mlbutton *button = malloc(sizeof(mlbutton));
    button->text = NULL;
    button->pos = pos;
    button->pos_click = pos;
    button->pos_hover = pos;
    button->size = size;
    button->size_click = size;
    button->size_hover = size;
    button->color = color;
    button->color_hover = color;
    button->color_click = color;
    button->is_hover = 0;
    button->is_click = 0;
    button->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->rect, button->pos);
    sfRectangleShape_setSize(button->rect, button->size);
    sfRectangleShape_setFillColor(button->rect, button->color);
    return button;
}
