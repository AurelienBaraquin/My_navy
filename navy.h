/*
** EPITECH PROJECT, 2023
** B-PSU-100-MPL-1-1-navy-aurelien.baraquin
** File description:
** my
*/

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <ucontext.h>
#include <SFML/Graphics.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Window/Export.h>
#include <time.h>
#include <SFML/System/Vector2.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <SFML/System/Export.h>
#include <SFML/System/InputStream.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>
#include <netdb.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/System/Vector3.h>
#include <stddef.h>
#include <SFML/Audio.h>


#ifndef MY_H_
    #define MY_H_

extern int *signals;

//state 0 = menu principal; 1 = create map; 2 = jeu; 3 = menu de victoire; 4 = menu de défaite; 5 parametre; 6 = arbre techno ; 7 = login; 8 = register; 9 = login_and_register; 10 = verif connect
typedef struct global {
    int stop;
    int state;

//  in game variable

    int turn;
    int priority;
    sfVector2i simply_pos;


//  ################
// settings variable

    int framelimit;
    char *framelimit_todisp;
    int volume;
    int enable_music;
    sfRectangleShape *music_rect;
    sfRectangleShape *framelimit_rect;
    sfRectangleShape *music_rect_move;
    sfRectangleShape *framelimit_rect_move;
    sfText *volume_text;
    sfText *framelimit_text;
    sfText *framelimit_todisp_text;

//  ################
    int **map;
    int **map_enemy;

    sfVector2i pos_mouse;

    sfMusic *music;

    sfVideoMode mode;
    sfRenderWindow* window;
    sfEvent event;
    sfTexture* texture_background;
    sfSprite* sprite_background;

    sfSprite* button_play;
    sfTexture* texture_button_play;
    sfVector2f pos_button_play;

    sfSprite* button_back;
    sfTexture* texture_button_back;
    sfVector2f pos_button_back;

    sfSprite* button_login;
    sfTexture* texture_button_login;
    sfVector2f pos_button_login;

    sfSprite* button_register;
    sfTexture* texture_button_register;
    sfVector2f pos_button_register;

    sfSprite* button_settings;
    sfTexture* texture_button_settings;
    sfVector2f pos_button_settings;

    sfSprite* button_skills;
    sfTexture* texture_button_skills;
    sfVector2f pos_button_skills;

    sfSprite* titlebar;
    sfTexture* texture_titlebar;
    sfVector2f pos_titlebar;

    sfSprite* cross;
    sfTexture* texture_cross;
    sfVector2f pos_cross;

    sfSprite* circle;
    sfTexture* texture_circle;
    sfVector2f pos_circle;

    sfSprite* square;
    sfTexture* texture_square;
    sfVector2f pos_square;

    sfText *text;
    sfFont *font;

    sfText *text2;
    sfText *ip_text;
    char *port;
    char *ip;
    int is_ip_or_port;
    int i;
    struct hostent *server;

    int sockfd, newsockfd, portno, clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;
    int a;

    sfThread *thread;
    pthread_t thread2;

    int connected;
    sfSprite* my_map_font;
    sfTexture* texture_water;
    sfVector2f pos_water;

    sfSprite* enemy_map_font;
    sfTexture* texture_water_enemy;
    sfVector2f pos_water_enemy;

    sfText *text3;
    sfText *text4;

    sfTexture* sprite_background2_texture;

    sfSprite* semi_back;
    sfTexture* semi_back_texture;

    char *message;

    int flags;

    sfText *your_ip;

    sfText *confirm;
    sfText *reset_map;

    sfSprite *shadow;
    sfTexture *shadow_texture;
    sfVector2f pos_shadow;

    sfClock *clock;
    sfTime time;

    int start;
} global_t;

typedef struct element element_t;
struct element {
    int number;
    int is_click;
    int sizex;
    int sizey;
    int sizex_keep;
    int sizey_keep;
    int placed;
    //rotate 0 = 0°; 1 = 90°; 2 = 180°; 3 = 270°
    int rotate;
    sfSprite* sprite;
    sfTexture* texture;
    sfVector2f pos;
    element_t *next;
};

typedef struct list {
    element_t *first;
} list;

int menu_principal(global_t *global);
void create_map(global_t *global, list *list);
list *init(void);
void insertion(list *liste, int nb, char *filepath, int size);
void suppression(list *list);
void remove_last(list *liste);
void verif_ip_and_port(global_t *global);
void join_game(global_t *global);
void host_game(global_t *global);
void join_other(global_t *global);
int verif_str(global_t *global);
void error(const char *msg);
void write_ip(global_t *global, sfEvent event);
void write_port(global_t *global, sfEvent event);
void mouse_button_exit(global_t *global, sfEvent event);
void uptdate_and_draw(global_t *global);
void join_game(global_t *global);
int verif_str(global_t *global);
void error(const char *msg);
void verif_if_connect_succes(global_t *global);
void before_verif_connect(global_t *global);
void verif_ip_and_port(global_t *global);
void verif_button_exit(global_t *global, sfEvent event);
char *get_ip();
void show_ip_and_port(global_t *global);
void join_other(global_t *global);
void a_is_true_socket_create(global_t *global);
void close_event(global_t *global, sfEvent event);
void enter_port(global_t *global, sfEvent event);
void wrong_port(global_t *global, sfEvent event);
void host_game(global_t *global);
void game(global_t *global, list *list);
void get_map_from_intint(global_t *global, int **map, list *list);
void display_game(global_t *global, list *list);
void set_button_menu_principal(global_t *global);
int win_condition(global_t *global);
void display_text_ingame(global_t *global);
void settings(global_t *global);

#endif /* !MY_H_ */
