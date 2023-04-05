/*
** EPITECH PROJECT, 2023
** name
** File description:
** desc
*/

#include "navy.h"

int set_boat_position_quad(global_t *global, element_t *actuel)
{
    int i = 50;
    if (actuel->rotate == 1)
        if (actuel->pos.x < 720 + actuel->sizex - 25 || actuel->pos.x > 1120 + 25 || actuel->pos.y < 320 - 18 || actuel->pos.y > 720 - 32)
            return 1;
    if (actuel->rotate == 3)
        if (actuel->pos.x < 720 - 25 || actuel->pos.x > 1120 - actuel->sizex + 25 || actuel->pos.y < 320 - 18 + 50 || actuel->pos.y > 720 - 32 + 50)
            return 1;
    if (actuel->rotate == 0)
        if (actuel->pos.x < 720 - 25 || actuel->pos.x > 1120 - 25 || actuel->pos.y < 320 - 18 || actuel->pos.y > 720 - 32 - actuel->sizey + 50)
            return 1;
    if (actuel->rotate == 2)
        if (actuel->pos.x < 720 - 25 + 50 || actuel->pos.x > 1120 - 25 + 50 || actuel->pos.y < 320 - 18 + actuel->sizey || actuel->pos.y > 720 - 32 + 50)
            return 1;
    for (i = 50; i < actuel->pos.x; i += 50);
    actuel->pos.x = i - 25;
    for (i = 50; i < actuel->pos.y; i += 50);
    actuel->pos.y = i - 25;
    return 0;
}

void set_attribute_boat(global_t *global, list *list)
{
    element_t *actuel = list->first;
    while (actuel != NULL) {
        if (actuel->is_click == 1) {
            actuel->pos.x = global->pos_mouse.x - 25;
            actuel->pos.y = global->pos_mouse.y - 25;
            set_boat_position_quad(global, actuel);
        }
        sfSprite_setTexture(actuel->sprite, actuel->texture, sfTrue);
        sfSprite_setPosition(actuel->sprite, actuel->pos);
        actuel = actuel->next;
    }
}

void display_create_map(global_t *global, list *list)
{
    set_attribute_boat(global, list);
    sfRenderWindow_clear(global->window, sfBlack);
    sfRenderWindow_drawSprite(global->window, global->sprite_background, NULL);
    sfSprite_setPosition(global->my_map_font, global->pos_water);
    sfRenderWindow_drawSprite(global->window, global->my_map_font, NULL);
    sfText_setPosition(global->confirm, (sfVector2f){700, 150});
    sfRenderWindow_drawText(global->window, global->confirm, NULL);
    sfText_setPosition(global->reset_map, (sfVector2f){700, 800});
    sfRenderWindow_drawText(global->window, global->reset_map, NULL);
    element_t *actuel = list->first;
    while (actuel != NULL) {
        sfRenderWindow_drawSprite(global->window, actuel->sprite, NULL);
        actuel = actuel->next;
    }
    sfRenderWindow_display(global->window);
}

int boat_pressed(global_t *global, sfMouseButtonEvent event, list *list)
{
    element_t *actuel = list->first;
    while (actuel != NULL) {
        if (actuel->is_click == 1) {
            return 0;
        }
        actuel = actuel->next;
    }
    actuel = list->first;
    while (actuel != NULL) {
        if (event.x >= actuel->pos.x && event.x <= actuel->pos.x + 50 &&
            event.y >= actuel->pos.y && event.y <= actuel->pos.y + 200 && actuel->placed == 0) {
            actuel->is_click = 1;
            return (actuel->number);
        }
        actuel = actuel->next;
    }
    return (-1);
}

int is_selected(global_t *global, list *list)
{
    element_t *actuel = list->first;
    while (actuel != NULL) {
        if (actuel->is_click == 1) {
            return 1;
        }
        actuel = actuel->next;
    }
    return 0;
}

void place_boat(global_t *global, list *list)
{
    element_t *actuel = list->first;
    while (actuel != NULL) {
        if (actuel->is_click == 1 && set_boat_position_quad(global, actuel) == 0) {
            actuel->is_click = 0;
            actuel->placed = 1;
            return;
        }
        actuel = actuel->next;
    }
}

void rotate_boat(global_t *global, list *list)
{
    element_t *actuel = list->first;
    while (actuel != NULL) {
        if (actuel->is_click == 1) {
            actuel->rotate++;
            sfSprite_setOrigin(actuel->sprite, (sfVector2f){50, 50});
            sfSprite_setRotation(actuel->sprite, actuel->rotate * 90);
            sfSprite_setOrigin(actuel->sprite, (sfVector2f){0, 0});
            if (actuel->rotate == 4)
                actuel->rotate = 0;
            if (actuel->rotate == 0 || actuel->rotate == 2) {
                actuel->sizex = 50;
                actuel->sizey = actuel->sizey_keep;
            } else {
                actuel->sizex = actuel->sizey_keep;
                actuel->sizey = 50;
            }
            return;
        }
        actuel = actuel->next;
    }
}

int create_map_intint(global_t *global, list *list)
{
    int i = 0;
    int j = 0;
    element_t *actuel = list->first;
    while (actuel != NULL) {
        if (actuel->placed == 0) {
            actuel = actuel->next;
            return 84;
        }
        for (i = 720; i < actuel->pos.x - 50; i += 50);
        for (j = 320; j < actuel->pos.y - 50; j += 50);
        if (actuel->rotate == 3) {
            for (int l = 0; l < actuel->sizex / 50; l++) {
                if (global->map[(j - 320) / 50 - 1][(i - 720) / 50 + l] != 0)
                    return 84;
                global->map[(j - 320) / 50 - 1][(i - 720) / 50 + l] = actuel->number;
            }
        }
        if (actuel->rotate == 1) {
            for (int l = 0; l < actuel->sizex / 50; l++) {
                if (global->map[(j - 320) / 50][(i - 720) / 50 - l - 1] != 0)
                    return 84;
                global->map[(j - 320) / 50][(i - 720) / 50 - l - 1] = actuel->number;
            }
        }
        if (actuel->rotate == 0) {
            for (int l = 0; l < actuel->sizey / 50; l++) {
                if (global->map[(j - 320) / 50 + l][(i - 720) / 50] != 0)
                    return 84;
                global->map[(j - 320) / 50 + l][(i - 720) / 50] = actuel->number;
            }
        }
        if (actuel->rotate == 2) {
            for (int l = 0; l < actuel->sizey / 50; l++) {
                if (global->map[(j - 320) / 50 - l - 1][(i - 720) / 50 - 1] != 0)
                    return 84;
                global->map[(j - 320) / 50 - l - 1][(i - 720) / 50 - 1] = actuel->number;
            }
        }
        actuel = actuel->next;
    }
    return 0;
}

int text_pressed_map(global_t *global, sfMouseButtonEvent event, list *list)
{
    if (event.x >= 700 && event.x <= 900 && event.y >= 150 && event.y <= 200) {
        return 1;
    }
    if (event.x >= 700 && event.x <= 900 && event.y >= 800 && event.y <= 850) {
        return 2;
    }
    return 0;
}

void reset_map(global_t *global, list *list)
{
    element_t *actuel = list->first;
    for (int i = 0; actuel != NULL; i++) {
        actuel->placed = 0;
        actuel->is_click = 0;
        actuel->rotate = 0;
        actuel->sizex = 50;
        actuel->sizey = actuel->sizey_keep;
        sfSprite_setRotation(actuel->sprite, 0);
        actuel->pos = (sfVector2f){(i * 120) + 120, 480};
        sfSprite_setPosition(actuel->sprite, actuel->pos);
        actuel = actuel->next;
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            global->map[i][j] = 0;
        }
    }
}

void event_create_map(global_t *global, list *list)
{
    while (sfRenderWindow_pollEvent(global->window, &global->event)) {
        if (global->event.type == sfEvtClosed){
                sfRenderWindow_close(global->window);
                global->stop = 1;
            }
            if (global->event.type == sfEvtKeyPressed) {
                if (global->event.key.code == sfKeyEscape){
                    sfRenderWindow_close(global->window);
                    global->stop = 1;
                }
            }
        if (global->event.type == sfEvtMouseButtonPressed) {
            if (is_selected(global, list) == 0)
                boat_pressed(global, global->event.mouseButton, list);
            else
                place_boat(global, list);
            if (text_pressed_map(global, global->event.mouseButton, list) == 1) {
                if (create_map_intint(global, list) != 0) {
                    sfText_setString(global->confirm, "Invalid map !");
                    sfText_setColor(global->confirm, sfRed);
                    display_create_map(global, list);
                    sleep(1);
                    sfText_setString(global->confirm, "-> Confirm <-");
                    sfText_setColor(global->confirm, sfWhite);
                    reset_map(global, list);
                } else {
                    sfText_setString(global->confirm, "Map confirmed ! Please wait for the other player.");
                    sfText_setColor(global->confirm, sfGreen);
                    display_create_map(global, list);
                    write(global->sockfd, "Confirmed", 10);
                    int a = read(global->sockfd, global->message, 100);
                    if (a >= 0 && strcmp(global->message, "Confirmed") == 0) {
                        global->state = 2;
                    }
                }
            }
            if (text_pressed_map(global, global->event.mouseButton, list) == 2) {
                reset_map(global, list);
            }
        }
        if (global->event.type == sfEvtKeyPressed) {
            if (global->event.key.code == sfKeyR) {
                if (is_selected(global, list) == 1)
                    rotate_boat(global, list);
            }
        }
    }
}

void create_map(global_t *global, list *list)
{
    //1 = 50x100, 2 = 50x200, 3 = 50x200, 4 = 50x150, 5 = 50x150
    global->pos_water = (sfVector2f){720, 320};
    event_create_map(global, list);
    display_create_map(global, list);
}
