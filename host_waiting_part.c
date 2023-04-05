/*
** EPITECH PROJECT, 2023
** B-PSU-100-MPL-1-1-navy-aurelien.baraquin
** File description:
** host_waiting_part
*/
#include "navy.h"

void verif_button_exit(global_t *global, sfEvent event)
{
    while (sfRenderWindow_pollEvent(global->window, &event)) {
        if (event.type == sfEvtClosed)
            global->stop = 1;
        if (event.type == sfEvtMouseButtonPressed && 
        event.mouseButton.x >= 760 && event.mouseButton.x <= 1260 &&
        event.mouseButton.y >= 790 && event.mouseButton.y <= 890) {
            global->state = 9;
            global->port = malloc(sizeof(char) * 6);
            global->i = 0;
            global->port[0] = '\0';
            sfText_setString(global->text2, global->port);
        }
    }
}

void show_ip_and_port(global_t *global)
{
    char *ip = malloc(sizeof(char) * 100);
    ip = get_ip();
    sfRenderWindow_clear(global->window, sfBlack);
    sfSprite_setPosition(global->button_back, (sfVector2f){760, 790});
    sfRenderWindow_drawSprite(global->window, global->sprite_background, NULL);
    sfRenderWindow_drawSprite(global->window, global->button_back, NULL);
    sfText_setString
    (global->text, "Waiting for a player to join,...\n Your IP :\n Port :");
    sfText_setPosition(global->text, (sfVector2f){650, 290});
    sfText_setString(global->text2, global->port);
    sfText_setString(global->your_ip, ip);
    sfText_setPosition(global->your_ip, (sfVector2f){840, 350});
    sfText_setPosition(global->text2, (sfVector2f){780, 395});
    sfRenderWindow_drawText(global->window, global->text, NULL);
    sfRenderWindow_drawText(global->window, global->text2, NULL);
    sfRenderWindow_drawText(global->window, global->your_ip, NULL);
    sfRenderWindow_display(global->window);
    listen(global->sockfd,5);
}

void join_other(global_t *global)
{
    sfEvent event;
    verif_button_exit(global, event);
    show_ip_and_port(global);
    global->clilen = sizeof(global->cli_addr);
    global->flags = fcntl(global->sockfd, F_GETFL, 0);
    fcntl(global->sockfd, F_SETFL, global->flags | O_NONBLOCK);
    global->newsockfd = accept(global->sockfd, (struct sockaddr *)
    &global->cli_addr, &global->clilen);
    if (global->newsockfd > 0){
        printf("Connection accepte\n");
        global->state = 1;
        global->sockfd = global->newsockfd;
        global->priority = 1;
    }
}