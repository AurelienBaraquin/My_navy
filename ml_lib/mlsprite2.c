/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** mlsprite
*/

#include "mlsf.h"

void mlsprite_destroy(mlsprite *sprite)
{
    sfTexture_destroy(sprite->texture);
    sfSprite_destroy(sprite->sprite);
    free(sprite);
}

void mlsprite_set_position(mlsprite *sprite, sfVector2f position)
{
    sfSprite_setPosition(sprite->sprite, position);
}
