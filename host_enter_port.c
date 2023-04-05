/*
** EPITECH PROJECT, 2023
** B-PSU-100-MPL-1-1-navy-aurelien.baraquin
** File description:
** host_enter_port
*/

#include "navy.h"

void a_is_true_socket_create(global_t *global)
{
    if (global->a == 0){
        global->sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (global->sockfd < 0)
            error("ERROR opening socket");
        bzero((char *) &global->serv_addr, sizeof(global->serv_addr));
        global->serv_addr.sin_family = AF_INET;
        global->serv_addr.sin_addr.s_addr = INADDR_ANY;
        global->a = 1;
    }
}

void close_event(global_t *global, sfEvent event)
{
    if (event.type == sfEvtClosed)
            global->stop = 1;
    if (event.type == sfEvtMouseButtonPressed) {
        if (event.mouseButton.x >= 760 && event.mouseButton.x <= 1260 && event.mouseButton.y >= 790 && event.mouseButton.y <= 890) {
            global->state = 9;
            global->port = malloc(sizeof(char) * 6);
            global->i = 0;
            global->port[0] = '\0';
            sfText_setString(global->text2, global->port);
        }
    }
}

void enter_port(global_t *global, sfEvent event)
{
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
}

void wrong_port(global_t *global, sfEvent event)
{
    if (event.text.unicode == 13) {
        global->portno = atoi(global->port);
        global->serv_addr.sin_port = htons(global->portno);
        if (global->port[0] == '\0' || bind(global->sockfd, (struct sockaddr *) &global->serv_addr, sizeof(global->serv_addr)) < 0){
            sfText_setString(global->text2, "ERROR, not a valid port");
            global->a = 0;
        } else {
            global->state = 10;
            global->i = 0;
        }
    }
}

void host_game(global_t *global)
{
    sfEvent event;
    a_is_true_socket_create(global);
    while (sfRenderWindow_pollEvent(global->window, &event)) {
        close_event(global, event);
        if (event.type == sfEvtTextEntered) {
            enter_port(global, event);
            wrong_port(global, event);
        }
    }
    sfRenderWindow_clear(global->window, sfBlack);
    sfSprite_setPosition(global->button_back, (sfVector2f){760, 790});
    sfRenderWindow_drawSprite(global->window, global->sprite_background, NULL);
    sfRenderWindow_drawSprite(global->window, global->button_back, NULL);
    sfText_setPosition(global->text, (sfVector2f){650, 290});
    sfText_setPosition(global->text2, (sfVector2f){760, 400});
    sfText_setString(global->text, "Enter the PORT you want to host on");
    sfRenderWindow_drawText(global->window, global->text, NULL);
    sfRenderWindow_drawText(global->window, global->text2, NULL);
    sfRenderWindow_display(global->window);
}