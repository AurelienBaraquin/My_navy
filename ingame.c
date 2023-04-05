/*
** EPITECH PROJECT, 2023
** B-PSU-100-MPL-1-1-navy-aurelien.baraquin
** File description:
** connection_mulit
*/

#include "navy.h"

#define mp global->simply_pos

void ingame_event(global_t *global, list *list)
{
    while (sfRenderWindow_pollEvent(global->window, &global->event)) {
        if (global->event.type == sfEvtClosed)
            global->stop = 1;
        if (global->event.type == sfEvtKeyPressed) {
            if (global->event.key.code == sfKeyEscape) {
                global->stop = 1;
            }
        }
        if (global->event.type == sfEvtMouseButtonPressed) {
            if (global->time.microseconds >= 100000 && global->event.mouseButton.x >= 1005 && global->event.mouseButton.x <= 1395 &&
            global->event.mouseButton.y >= 305 && global->event.mouseButton.y <= 695 && global->priority == 1) {
                // display_text_ingame(global);
                if (global->map_enemy[mp.y][mp.x] != 0)
                    return;
                // usleep(2000);
                sfClock_restart(global->clock);
                global->time = sfClock_getElapsedTime(global->clock);
                char *int_str = malloc(sizeof(char) * 3);
                int_str[2] = '\0';
                sprintf(int_str, "%d%d", mp.y, mp.x);
                write(global->sockfd, int_str, 2);
                printf("send: %s\n", int_str);
                free(global->message);
                global->message = malloc(sizeof(char) * 3);
                free(int_str);
                global->message[2] = '\0';
                read(global->sockfd, global->message, 100);
                if (strncmp(global->message, "hit", 3) == 0) {
                    global->map_enemy[mp.y][mp.x] = -2;
                }
                if (strncmp(global->message, "miss", 4) == 0) {
                    global->map_enemy[mp.y][mp.x] = -1;
                }
                global->priority = 2;
                display_text_ingame(global);
                global->start = 0;
            }
        }
    }
}

void get_simply_mouse(global_t *global)
{
    global->pos_mouse = sfMouse_getPositionRenderWindow(global->window);
    int i = 1000;
    for (i = 1000; i < global->pos_mouse.x; i += 50);
    mp.x = (i / 50) - 20 - 1;
    for (i = 300; i < global->pos_mouse.y; i += 50);
    mp.y = (i / 50) - 6 - 1;
}

void display_text_ingame(global_t *global)
{
    sfText_setColor(global->text, sfRed);
    if (global->priority == 1) {
        sfText_setString(global->text, "Your turn");
        sfText_setColor(global->text, sfGreen);
    } else
        sfText_setString(global->text, "Enemy's turn");
    sfText_setPosition(global->text, (sfVector2f){720, 800});
    sfRenderWindow_drawText(global->window, global->text, NULL);
}

void read_enemy(void *arg)
{
    global_t *global = (global_t *)arg;
    // display_text_ingame(global);
    int test = read(global->sockfd, global->message, 100);
    if (test != -1 && global->message[0] != '\0') {
        int x = global->message[0] - 48;
        int y = global->message[1] - 48;
        if (global->map[x][y] == 0) {
            global->map[x][y] = -1;
            write(global->sockfd, "miss", 4);
        }
        else if (global->map[x][y] >= 1) {
            global->map[x][y] = -2;
            write(global->sockfd, "hit", 3);
        }
        global->priority = 1;
        // display_text_ingame(global);
        sfClock_restart(global->clock);
        global->time = sfClock_getElapsedTime(global->clock);
    }
}

void game(global_t *global, list *list)
{
    display_text_ingame(global);
    if (global->turn == 0) {
        get_map_from_intint(global, global->map, list);
        global->turn = 1;
        display_game(global, list);
    }
    get_simply_mouse(global);
    if (win_condition(global) >= 1) {
        global->stop = 1;
        if (win_condition(global) == 1)
            printf("I won\n");
        else
            printf("Enemy won\n");
        return;
    }
    if (strncmp(global->message, "win", 3) == 0) {
        global->stop = 1;
        return;
    }
    if (strncmp(global->message, "continue", 8) == 0) {
        global->priority = 1;
    }
    if (global->priority == 2) {
        free(global->message);
        global->message = malloc(sizeof(char) * 100);
        // global->flags = fcntl(global->sockfd, F_GETFL, 0);
        // fcntl(global->sockfd, F_SETFL, global->flags | O_NONBLOCK);
        // usleep(2000);
        if (global->start == 0) {
            global->thread = sfThread_create(read_enemy, global);
            sfThread_launch(global->thread);
            global->start = 1;
        }
    }
    ingame_event(global, list);
    display_game(global, list);
    display_text_ingame(global);
}
