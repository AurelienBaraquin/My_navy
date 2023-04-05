/*
** EPITECH PROJECT, 2023
** name
** File description:
** desc
*/

#include "navy.h"

void display_menu(global_t *global)
{
    sfRenderWindow_clear(global->window, sfBlack);
    sfRenderWindow_drawSprite(global->window, global->sprite_background, NULL);
    sfSprite_setPosition(global->shadow, (sfVector2f){770, 300});
    sfRenderWindow_drawSprite(global->window, global->shadow, NULL);
    sfRenderWindow_drawSprite(global->window, global->button_play, NULL);
    sfSprite_setPosition(global->shadow, (sfVector2f){770, 550});
    sfRenderWindow_drawSprite(global->window, global->shadow, NULL);
    sfRenderWindow_drawSprite(global->window, global->button_settings, NULL);
    sfSprite_setPosition(global->shadow, (sfVector2f){770, 800});
    sfRenderWindow_drawSprite(global->window, global->shadow, NULL);
    sfRenderWindow_drawSprite(global->window, global->button_skills, NULL);
    sfRenderWindow_drawSprite(global->window, global->titlebar, NULL);
    sfRenderWindow_display(global->window);
}

void set_button_menu_principal(global_t *global)
{
    global->pos_button_play = (sfVector2f){760, 290};
    sfSprite_setPosition(global->button_play, global->pos_button_play);
    global->pos_button_settings = (sfVector2f){760, 540};
    sfSprite_setPosition(global->button_settings, global->pos_button_settings);
    global->pos_button_skills = (sfVector2f){760, 790};
    sfSprite_setPosition(global->button_skills, global->pos_button_skills);
    global->pos_titlebar = (sfVector2f){460, -20};
    sfSprite_setPosition(global->titlebar, global->pos_titlebar);
}

void event_verif(global_t *global)
{
    while (sfRenderWindow_pollEvent(global->window, &global->event)) {
        if (global->event.type == sfEvtClosed)
            global->stop = 1;
        if (global->event.type == sfEvtKeyPressed) {
            if (global->event.key.code == sfKeyEscape)
                global->stop = 1;
        }
        if (global->event.type == sfEvtMouseButtonPressed) {
            if (global->event.mouseButton.x >= 760 && global->event.mouseButton.x <= 1090 && global->event.mouseButton.y >= 290 && global->event.mouseButton.y <= 480)
                global->state = 9;
            if (global->event.mouseButton.x >= 760 && global->event.mouseButton.x <= 1090 && global->event.mouseButton.y >= 540 && global->event.mouseButton.y <= 730)
                global->state = 6;
            if (global->event.mouseButton.x >= 760 && global->event.mouseButton.x <= 1090 && global->event.mouseButton.y >= 790 && global->event.mouseButton.y <= 980)
                global->state = 5;
        }
        if (sfMouse_getPositionRenderWindow(global->window).x >= 760 && sfMouse_getPositionRenderWindow(global->window).x <= 1090 && sfMouse_getPositionRenderWindow(global->window).y >= 290 && sfMouse_getPositionRenderWindow(global->window).y <= 480)
            sfSprite_setPosition(global->button_play, (sfVector2f){770, 300});
        else
            sfSprite_setPosition(global->button_play, (sfVector2f){760, 290});
        if (sfMouse_getPositionRenderWindow(global->window).x >= 760 && sfMouse_getPositionRenderWindow(global->window).x <= 1090 && sfMouse_getPositionRenderWindow(global->window).y >= 540 && sfMouse_getPositionRenderWindow(global->window).y <= 730)
            sfSprite_setPosition(global->button_settings, (sfVector2f){770, 550});
        else
            sfSprite_setPosition(global->button_settings, (sfVector2f){760, 540});
        if (sfMouse_getPositionRenderWindow(global->window).x >= 760 && sfMouse_getPositionRenderWindow(global->window).x <= 1090 && sfMouse_getPositionRenderWindow(global->window).y >= 790 && sfMouse_getPositionRenderWindow(global->window).y <= 980)
            sfSprite_setPosition(global->button_skills, (sfVector2f){770, 800});
        else
            sfSprite_setPosition(global->button_skills, (sfVector2f){760, 790});
    }
}

int menu_principal(global_t *global)
{
    event_verif(global);
    display_menu(global);
}
