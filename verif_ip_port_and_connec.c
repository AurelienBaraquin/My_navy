/*
** EPITECH PROJECT, 2023
** B-PSU-100-MPL-1-1-navy-aurelien.baraquin
** File description:
** verif_ip_port_and_connec
*/

#include "navy.h"

int verif_str(global_t *global)
{
    if (global->port[0] == '\0') {
        sfText_setString(global->text2, "Please enter a port number");
        return (1);
    }
    else {
        return (0);
    }
}

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

void verif_if_connect_succes(global_t *global)
{
    bzero((char *) &global->serv_addr, sizeof(global->serv_addr));
    global->serv_addr.sin_family = AF_INET;
    bcopy((char *)global->server->h_addr,(char *)&global->serv_addr.sin_addr.s_addr,global->server->h_length);
    global->serv_addr.sin_port = htons(global->portno);
    if (connect(global->sockfd,(struct sockaddr *) &global->serv_addr,sizeof(global->serv_addr)) < 0) {
        printf("ERROR connecting\n");
        exit(84);
    } else {
        printf("Connected to server\n");
        global->connected = 1;
        global->state = 1;
    }
}

void before_verif_connect(global_t *global)
{
    global->portno = atoi(global->port);
    global->serv_addr.sin_port = htons(global->portno);
    global->server = gethostbyname(global->ip);
    if (global->server == NULL) {
        printf("ERROR, no such host\n");
        exit(84);
    } else {
        global->sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (global->sockfd < 0){
            printf("ERROR opening socket\n");
            exit(84);
        } else {
            verif_if_connect_succes(global);
        }
    }
}

void verif_ip_and_port(global_t *global)
{
    sfRenderWindow_clear(global->window, sfBlack);
    sfText_setPosition(global->text3, (sfVector2f){760, 440});
    sfText_setString(global->text3, "Waiting for connection...");
    sfRenderWindow_drawSprite(global->window, global->sprite_background, NULL);
    sfRenderWindow_drawText(global->window, global->text3, NULL);
    sfRenderWindow_display(global->window);
    printf("Waiting for connection...\n");
    if (global->ip[0] == '\0' || global->port[0] == '\0'){
        sfText_setString(global->text2, "ERROR, not a valid ip or port");
    } else {
        before_verif_connect(global);
    }
}