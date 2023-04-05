/*
** EPITECH PROJECT, 2023
** name
** File description:
** desc
*/

#include "mlsf.h"

int mlsprite_is_hover(mlsprite *sprite, sfVector2i mouse)
{
    if (mouse.x >= sprite->pos.x && mouse.x <= sprite->pos.x + sprite->size.x &&
    mouse.y >= sprite->pos.y && mouse.y <= sprite->pos.y + sprite->size.y) {
        sprite->is_hover = 1;
        return 1;
    }
    sprite->is_hover = 0;
    return 0;
}

int mlsprite_is_click(mlsprite *sprite, sfVector2i mouse)
{
    if (mouse.x >= sprite->pos.x && mouse.x <= sprite->pos.x + sprite->size.x &&
    mouse.y >= sprite->pos.y && mouse.y <= sprite->pos.y + sprite->size.y) {
        sprite->is_click = 1;
        return 1;
    }
    sprite->is_click = 0;
    return 0;
}

void mlsprite_display(mlwindow *window, mlsprite *sprite)
{
    sfSprite_setPosition(sprite->sprite, sprite->pos);
    sfSprite_setRotation(sprite->sprite, sprite->rotation);
    sfRenderWindow_drawSprite(window->window, sprite->sprite, NULL);
}

void mlsprite_update(mlwindow *window, mlsprite *sprite)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window->window);
    mlsprite_is_hover(sprite, mouse);
    mlsprite_is_click(sprite, mouse);
}

mlsprite *mlsprite_create(char *path, sfVector2f pos, sfVector2f size)
{
    mlsprite *sprite = malloc(sizeof(mlsprite));
    sprite->texture = sfTexture_createFromFile(path, NULL);
    sprite->sprite = sfSprite_create();
    sprite->pos = pos;
    sprite->is_click = 0;
    sprite->is_hover = 0;
    sprite->origin = (sfVector2f){0, 0};
    sprite->rotation = 0;
    sprite->rect = (sfIntRect){0, 0, size.x, size.y};
    sprite->size = size;
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfTrue);
    sfSprite_setTextureRect(sprite->sprite, sprite->rect);
    sfSprite_setPosition(sprite->sprite, sprite->pos);
    return sprite;
}
