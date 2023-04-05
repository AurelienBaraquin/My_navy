/*
** EPITECH PROJECT, 2023
** B-PSU-100-MPL-1-1-navy-aurelien.baraquin
** File description:
** join_party
*/
#include "navy.h"

void write_ip(global_t *global, sfEvent event)
{
    if (global->is_ip_or_port == 0){
        if ((event.text.unicode >= 48 && event.text.unicode <= 57) || event.text.unicode == 46) {
            global->ip[global->i] = event.text.unicode;
            global->i++;
            global->ip[global->i] = '\0';
            sfText_setString(global->ip_text, global->ip);
        }
        if (event.text.unicode == 8 && global->i > 0) {
            global->i--;
            global->ip[global->i] = '\0';
            sfText_setString(global->ip_text, global->ip);
        }
        if (event.text.unicode == 13 && global->i != 0) {
            global->is_ip_or_port = 1;
            global->i = 0;
        }
    }
}

void write_port(global_t *global, sfEvent event)
{
    if (global->is_ip_or_port == 1){
        if (event.text.unicode >= 48 && event.text.unicode <= 57) {
            global->port[global->i] = event.text.unicode;
            global->i++;
            global->port[global->i] = '\0';
            sfText_setString(global->text2, global->port);
        }
        if (event.text.unicode == 8 && global->i > 0) {
            global->i--;
            global->port[global->i] = '\0';
            sfText_setString(global->text2, global->port);
        }
        if (event.text.unicode == 13 && global->i != 0) {
            verif_ip_and_port(global);
            event.text.unicode = 0;
            global->state = 1;
            global->priority = 2;
        }
    }
}

void mouse_button_exit(global_t *global, sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed) {
        if (event.mouseButton.x >= 760 && event.mouseButton.x <= 1260 && event.mouseButton.y >= 790 && event.mouseButton.y <= 890) {
            global->state = 9;
            global->ip = malloc(sizeof(char) * 16);
            global->port = malloc(sizeof(char) * 6);
            global->i = 0;
            global->is_ip_or_port = 0;
            global->ip[0] = '\0';
            global->port[0] = '\0';
            sfText_setString(global->ip_text, global->ip);
            sfText_setString(global->text2, global->port);
        }
    }
}

void uptdate_and_draw(global_t *global)
{
    sfSprite_setPosition(global->button_back, (sfVector2f){760, 790});
    sfText_setPosition(global->ip_text, (sfVector2f){980, 410});
    sfText_setPosition(global->text2, (sfVector2f){1090, 500});
    sfText_setPosition(global->text3, (sfVector2f){650, 400});
    sfText_setPosition(global->text4, (sfVector2f){650, 500});
    sfRenderWindow_drawSprite(global->window, global->sprite_background, NULL);
    sfRenderWindow_drawText(global->window, global->ip_text, NULL);
    sfRenderWindow_drawText(global->window, global->text2, NULL);
    sfRenderWindow_drawText(global->window, global->text3, NULL);
    sfRenderWindow_drawText(global->window, global->text4, NULL);
    sfRenderWindow_drawSprite(global->window, global->button_back, NULL);
}

void join_game(global_t *global)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(global->window, &event)) {
        if (event.type == sfEvtClosed)
            global->stop = 1;
        mouse_button_exit(global, event);
        if (event.type == sfEvtTextEntered) {
            write_ip(global, event);
            write_port(global, event);
        }
    }
    sfRenderWindow_clear(global->window, sfBlack);
    uptdate_and_draw(global);
    sfRenderWindow_display(global->window);
}