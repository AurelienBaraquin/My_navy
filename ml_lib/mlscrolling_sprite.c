/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** mlscrolling_sprite
*/

#include "mlsf.h"

mlscrolling_sprite *mlscrolling_sprite_create(char *path, sfVector2f pos,
sfVector2f size, sfVector2f speed)
{
    mlscrolling_sprite *sprite = malloc(sizeof(mlscrolling_sprite));
    sprite->sprite = mlsprite_create(path, pos, size);
    sprite->pos = pos;
    sprite->init_pos = pos;
    sprite->size = size;
    sprite->rect = (sfIntRect){0, 0, size.x, size.y};
    sprite->origin = (sfVector2f){0, 0};
    sprite->rotation = 0;
    sprite->color = sfWhite;
    sprite->speed = speed;
    return (sprite);
}

void mlscrolling_sprite_display(mlwindow *window, mlscrolling_sprite *sprite)
{
    sprite->sprite->pos = sprite->pos;
    mlsprite_display(window, sprite->sprite);
    if (sprite->init_pos.x < sprite->pos.x) {
        sprite->sprite->pos = (sfVector2f){sprite->pos.x -
            sprite->size.x, sprite->pos.y};
    } else {
        sprite->sprite->pos = (sfVector2f){sprite->pos.x +
            sprite->size.x, sprite->pos.y};
    }
    mlsprite_display(window, sprite->sprite);
}

void mlscrolling_sprite_update(mlwindow *window, mlscrolling_sprite *sprite)
{
    sprite->pos.x += sprite->speed.x;
    sprite->pos.y += sprite->speed.y;
    if (sprite->pos.x > sprite->init_pos.x + sprite->size.x)
        sprite->pos.x = sprite->init_pos.x - sprite->size.x;
    if (sprite->pos.x < sprite->init_pos.x - sprite->size.x)
        sprite->pos.x = sprite->init_pos.x + sprite->size.x;
}

void mlscrolling_sprite_destroy(mlscrolling_sprite *sprite)
{
    mlsprite_destroy(sprite->sprite);
    free(sprite);
}
