/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** mltext
*/

#include "mlsf.h"

void mltext_display(mlwindow *window, mltext *text)
{
    sfText_setPosition(text->text, text->pos);
    sfText_setString(text->text, text->str);
    sfText_setFont(text->text, text->font);
    sfText_setCharacterSize(text->text, text->size);
    sfText_setColor(text->text, text->color);
    sfRenderWindow_drawText(window->window, text->text, NULL);
}

mltext *mltext_create(char *str, char *font, int size, sfColor color, sfVector2f pos)
{
    mltext *text = malloc(sizeof(mltext));
    text->pos = pos;
    text->str = str;
    text->font = sfFont_createFromFile(font);
    text->size = size;
    text->color = color;
    text->text = sfText_create();
    sfText_setPosition(text->text, text->pos);
    sfText_setString(text->text, text->str);
    sfText_setFont(text->text, text->font);
    sfText_setCharacterSize(text->text, text->size);
    sfText_setColor(text->text, text->color);
    return text;
}

void mltext_destroy(mltext *text)
{
    sfFont_destroy(text->font);
    sfText_destroy(text->text);
    free(text);
}
