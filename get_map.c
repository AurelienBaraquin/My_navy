/*
** EPITECH PROJECT, 2023
** B-PSU-100-MPL-1-1-navy-aurelien.baraquin
** File description:
** connection_mulit
*/

#include "navy.h"

void get_map_from_intint(global_t *global, int **map, list *list)
{
    element_t *actuel = list->first;
    while (actuel != NULL) {
        actuel->pos.x -= 220;
        actuel->pos.y -= 20;
        sfSprite_setPosition(actuel->sprite, actuel->pos);
        actuel = actuel->next;
    }
}
