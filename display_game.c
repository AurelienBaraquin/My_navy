/*
** EPITECH PROJECT, 2023
** B-PSU-100-MPL-1-1-navy-aurelien.baraquin
** File description:
** connection_mulit
*/

#include "navy.h"

void square_cursor(global_t *global, list *list)
{
    int i = 0;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(global->window);
    if (mouse.x < 1000 || mouse.x > 1400 || mouse.y < 300 || mouse.y > 700)
        return;
    for (i = 50; i < mouse.x; i += 50);
    mouse.x = i - 50;
    for (i = 50; i < mouse.y; i += 50);
    mouse.y = i - 50;
    sfSprite_setPosition(global->square, (sfVector2f){mouse.x, mouse.y});
    sfRenderWindow_drawSprite(global->window, global->square, NULL);
}

void display_game(global_t *global, list *list)
{
    sfRenderWindow_clear(global->window, sfBlack);
    sfSprite_setTexture(global->sprite_background, global->sprite_background2_texture, sfTrue);
    sfRenderWindow_drawSprite(global->window, global->sprite_background, NULL);
    sfRenderWindow_drawSprite(global->window, global->titlebar, NULL);
    sfSprite_setPosition(global->semi_back, (sfVector2f){500, 300});
    sfSprite_setPosition(global->my_map_font, (sfVector2f){500, 300});
    sfRenderWindow_drawSprite(global->window, global->semi_back, NULL);
    sfRenderWindow_drawSprite(global->window, global->my_map_font, NULL);
    sfSprite_setPosition(global->semi_back, (sfVector2f){1000, 300});
    sfSprite_setPosition(global->enemy_map_font, (sfVector2f){1000, 300});
    sfRenderWindow_drawSprite(global->window, global->semi_back, NULL);
    sfRenderWindow_drawSprite(global->window, global->enemy_map_font, NULL);
    element_t *actuel = list->first;
    while (actuel != NULL) {
        sfRenderWindow_drawSprite(global->window, actuel->sprite, NULL);
        actuel = actuel->next;
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (global->map[i][j] == -1) {
                sfSprite_setPosition(global->circle, (sfVector2f){500 + (j * 50), 300 + (i * 50)});
                sfRenderWindow_drawSprite(global->window, global->circle, NULL);
            }
            if (global->map[i][j] == -2) {
                sfSprite_setPosition(global->cross, (sfVector2f){500 + (j * 50), 300 + (i * 50)});
                sfRenderWindow_drawSprite(global->window, global->cross, NULL);
            }
        }
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (global->map_enemy[i][j] == -1) {
                sfSprite_setPosition(global->circle, (sfVector2f){1000 + (j * 50), 300 + (i * 50)});
                sfRenderWindow_drawSprite(global->window, global->circle, NULL);
            }
            if (global->map_enemy[i][j] == -2) {
                sfSprite_setPosition(global->cross, (sfVector2f){1000 + (j * 50), 300 + (i * 50)});
                sfRenderWindow_drawSprite(global->window, global->cross, NULL);
            }
        }
    }
    square_cursor(global, list);
    sfRenderWindow_drawText(global->window, global->text, NULL);
    sfRenderWindow_display(global->window);
}
