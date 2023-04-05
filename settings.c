/*
** EPITECH PROJECT, 2023
** name
** File description:
** desc
*/

#include "navy.h"

void display_settings(global_t *global)
{
    if (global->framelimit < 1)
        global->framelimit = 1;
    if (global->framelimit > 100)
        global->framelimit = 100;
    if (global->volume < 0)
        global->volume = 0;
    if (global->volume > 100)
        global->volume = 100;
    sfRenderWindow_setFramerateLimit(global->window, global->framelimit);
    sfMusic_setVolume(global->music, global->volume);
    sfRenderWindow_clear(global->window, sfBlack);
    sfRenderWindow_drawSprite(global->window, global->sprite_background, NULL);
    sfSprite_setPosition(global->button_back, (sfVector2f){0, 0});
    sfRenderWindow_drawSprite(global->window, global->button_back, NULL);

    sfRectangleShape_setSize(global->music_rect_move, (sfVector2f){global->volume * 8, 40});
    sfRectangleShape_setSize(global->framelimit_rect_move, (sfVector2f){global->framelimit * 8, 40});

    sfRenderWindow_drawRectangleShape(global->window, global->music_rect, NULL);
    sfRenderWindow_drawRectangleShape(global->window, global->music_rect_move, NULL);

    sfRenderWindow_drawRectangleShape(global->window, global->framelimit_rect, NULL);
    sfRenderWindow_drawRectangleShape(global->window, global->framelimit_rect_move, NULL);

    sfRenderWindow_drawText(global->window, global->volume_text, NULL);
    sfRenderWindow_drawText(global->window, global->framelimit_text, NULL);

    global->framelimit_todisp = malloc(sizeof(char) * 4);
    sprintf(global->framelimit_todisp, "%d", global->framelimit);
    sfText_setString(global->framelimit_todisp_text, global->framelimit_todisp);
    sfRenderWindow_drawText(global->window, global->framelimit_todisp_text, NULL);

    sfRenderWindow_display(global->window);
}

void event_settings(global_t *global)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(global->window);
    while (sfRenderWindow_pollEvent(global->window, &global->event)) {
        if (global->event.type == sfEvtClosed)
            sfRenderWindow_close(global->window);
        if (global->event.type == sfEvtMouseButtonPressed) {
            if (global->event.mouseButton.button == sfMouseLeft) {
                if (global->event.mouseButton.x >= 0 && global->event.mouseButton.x <= 200 && global->event.mouseButton.y >= 0 && global->event.mouseButton.y <= 100) {
                    global->state = 0;
                    return;
                }
                if (mouse.x >= 200 && mouse.x <= 1000 && mouse.y >= 280 && mouse.y <= 340) {
                    while (mouse.x >= 200 && mouse.x <= 1000 && mouse.y >= 280 && mouse.y <= 340) {
                        mouse = sfMouse_getPositionRenderWindow(global->window);
                        global->volume = (mouse.x - 200) / 8;
                        display_settings(global);
                    }
                    return;
                }
                if (mouse.x >= 200 && mouse.x <= 1000 && mouse.y >= 500 && mouse.y <= 560) {
                    while (mouse.x >= 200 && mouse.x <= 1000 && mouse.y >= 500 && mouse.y <= 560) {
                        mouse = sfMouse_getPositionRenderWindow(global->window);
                        global->framelimit = (mouse.x - 200) / 8;
                        display_settings(global);
                    }
                    return;
                }
            }
        }
    }
}

void settings(global_t *global)
{
    event_settings(global);
    display_settings(global);
}
