/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** mlbutton2
*/

#include "mlsf.h"

int mlbutton_is_hover(mlbutton *button, sfVector2i mouse)
{
    if (mouse.x >= button->pos.x && mouse.x <= button->pos.x + button->size.x &&
    mouse.y >= button->pos.y && mouse.y <= button->pos.y + button->size.y) {
        button->is_hover = 1;
        return 1;
    }
    button->is_hover = 0;
    return 0;
}

void mlbutton_set_text(mlbutton *button, char *text,
sfVector2f pos, sfColor color)
{
    mltext *text_button = mltext_create(text, "assets/font.ttf", 30, color, pos);
}

void mlbutton_destroy(mlbutton *button)
{
    sfRectangleShape_destroy(button->rect);
    free(button);
}

void mlbutton_set_hover(mlbutton *button, sfVector2f pos,
sfVector2f size, sfColor color)
{
    button->pos_hover = pos;
    button->size_hover = size;
    button->color_hover = color;
}

void mlbutton_set_click(mlbutton *button, sfVector2f pos,
sfVector2f size, sfColor color)
{
    button->pos_click = pos;
    button->size_click = size;
    button->color_click = color;
}
