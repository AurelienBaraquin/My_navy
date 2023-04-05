/*
** EPITECH PROJECT, 2023
** name
** File description:
** desc
*/

#include "navy.h"

void create_button(global_t *global)
{
    global->button_play = sfSprite_create();
    global->texture_button_play = sfTexture_createFromFile("assets/Bouton Play.jpg", NULL);
    sfSprite_setTexture(global->button_play, global->texture_button_play, sfTrue);
    global->pos_button_play = (sfVector2f){0, 0};
    sfSprite_setPosition(global->button_play, global->pos_button_play);

    global->button_back = sfSprite_create();
    global->texture_button_back = sfTexture_createFromFile("assets/Bouton back.png", NULL);
    sfSprite_setTexture(global->button_back, global->texture_button_back, sfTrue);
    global->pos_button_back = (sfVector2f){0, 0};
    sfSprite_setPosition(global->button_back, global->pos_button_back);

    global->button_login = sfSprite_create();
    global->texture_button_login = sfTexture_createFromFile("assets/Bouton host.jpg", NULL);
    sfSprite_setTexture(global->button_login, global->texture_button_login, sfTrue);
    global->pos_button_login = (sfVector2f){0, 0};
    sfSprite_setPosition(global->button_login, global->pos_button_login);

    global->button_register = sfSprite_create();
    global->texture_button_register = sfTexture_createFromFile("assets/Bouton join.jpg", NULL);
    sfSprite_setTexture(global->button_register, global->texture_button_register, sfTrue);
    global->pos_button_register = (sfVector2f){0, 0};
    sfSprite_setPosition(global->button_register, global->pos_button_register);

    global->button_settings = sfSprite_create();
    global->texture_button_settings = sfTexture_createFromFile("assets/Bouton settings.jpg", NULL);
    sfSprite_setTexture(global->button_settings, global->texture_button_settings, sfTrue);
    global->pos_button_settings = (sfVector2f){0, 0};
    sfSprite_setPosition(global->button_settings, global->pos_button_settings);

    global->button_skills = sfSprite_create();
    global->texture_button_skills = sfTexture_createFromFile("assets/Bouton skills tree.jpg", NULL);
    sfSprite_setTexture(global->button_skills, global->texture_button_skills, sfTrue);
    global->pos_button_skills = (sfVector2f){0, 0};
    sfSprite_setPosition(global->button_skills, global->pos_button_skills);

    global->titlebar = sfSprite_create();
    global->texture_titlebar = sfTexture_createFromFile("assets/titlebar.png", NULL);
    sfSprite_setTexture(global->titlebar, global->texture_titlebar, sfTrue);
    global->pos_titlebar = (sfVector2f){0, 0};
    sfSprite_setPosition(global->titlebar, global->pos_titlebar);

    global->my_map_font = sfSprite_create();
    global->texture_water = sfTexture_createFromFile("assets/water_texture.png", NULL);
    sfSprite_setTexture(global->my_map_font, global->texture_water, sfTrue);
    global->pos_water = (sfVector2f){0, 0};
    sfSprite_setPosition(global->my_map_font, global->pos_water);

    global->enemy_map_font = sfSprite_create();
    global->texture_water_enemy = sfTexture_createFromFile("assets/water_texture.png", NULL);
    sfSprite_setTexture(global->enemy_map_font, global->texture_water_enemy, sfTrue);
    global->pos_water_enemy = (sfVector2f){0, 0};
    sfSprite_setPosition(global->enemy_map_font, global->pos_water_enemy);

    global->cross = sfSprite_create();
    global->texture_cross = sfTexture_createFromFile("assets/cross.png", NULL);
    sfSprite_setTexture(global->cross, global->texture_cross, sfTrue);
    global->pos_cross = (sfVector2f){0, 0};
    sfSprite_setPosition(global->cross, global->pos_cross);

    global->circle = sfSprite_create();
    global->texture_circle = sfTexture_createFromFile("assets/circle.png", NULL);
    sfSprite_setTexture(global->circle, global->texture_circle, sfTrue);
    global->pos_circle = (sfVector2f){0, 0};
    sfSprite_setPosition(global->circle, global->pos_circle);

    global->square = sfSprite_create();
    global->texture_square = sfTexture_createFromFile("assets/square_opacite50.png", NULL);
    sfSprite_setTexture(global->square, global->texture_square, sfTrue);
    global->pos_square = (sfVector2f){0, 0};
    sfSprite_setPosition(global->square, global->pos_square);

    // int framelimit;
    // int volume;
    // int enable_music;
    // sfRectangleShape *music_rect;
    // sfRectangleShape *framelimit_rect;
    // sfRectangleShape *music_rect_move;
    // sfRectangleShape *framelimit_rect_move;

    global->framelimit = 60;
    global->volume = 100;
    global->enable_music = 1;
    global->music_rect = sfRectangleShape_create();
    global->framelimit_rect = sfRectangleShape_create();
    global->music_rect_move = sfRectangleShape_create();
    global->framelimit_rect_move = sfRectangleShape_create();
    sfRectangleShape_setSize(global->music_rect, (sfVector2f){800, 40});
    sfRectangleShape_setSize(global->framelimit_rect, (sfVector2f){800, 40});
    sfRectangleShape_setSize(global->music_rect_move, (sfVector2f){global->volume * 8, 40});
    sfRectangleShape_setSize(global->framelimit_rect_move, (sfVector2f){global->framelimit * 8, 40});
    sfRectangleShape_setFillColor(global->music_rect, sfBlack);
    sfRectangleShape_setFillColor(global->framelimit_rect, sfBlack);
    sfRectangleShape_setFillColor(global->music_rect_move, sfWhite);
    sfRectangleShape_setFillColor(global->framelimit_rect_move, sfWhite);
    sfRectangleShape_setPosition(global->music_rect, (sfVector2f){200, 300});
    sfRectangleShape_setPosition(global->music_rect_move, (sfVector2f){200, 300});
    sfRectangleShape_setPosition(global->framelimit_rect, (sfVector2f){200, 500});
    sfRectangleShape_setPosition(global->framelimit_rect_move, (sfVector2f){200, 500});
}

void init_chained_list(list *list)
{
    insertion(list, 1, "assets/Sea Warfare Set/Battleship/bateau1.png", 100);
    insertion(list, 2, "assets/Sea Warfare Set/Carrier/bateau2.png", 200);
    insertion(list, 3, "assets/Sea Warfare Set/Cruiser/bateau3.png", 200);
    insertion(list, 4, "assets/Sea Warfare Set/Destroyer/bateau4.png", 150);
    insertion(list, 5, "assets/Sea Warfare Set/PatrolBoat/bateau5.png", 150);
    element_t *tmp = list->first;
    for (int i = 0; tmp != NULL; i++) {
        tmp->pos = (sfVector2f){(i * 120) + 120, 480};
        sfSprite_setPosition(tmp->sprite, tmp->pos);
        tmp = tmp->next;
    }
}

void init_global(global_t *global, list *list)
{
    global->font = sfFont_createFromFile("assets/font/ASMAN.TTF");
    init_chained_list(list);
    global->map = malloc(sizeof(int *) * 8);
    global->map_enemy = malloc(sizeof(int *) * 8);
    for (int i = 0; i < 8; i++) {
        global->map[i] = malloc(sizeof(int) * 8);
        global->map_enemy[i] = malloc(sizeof(int) * 8);
        for (int j = 0; j < 8; j++) {
            global->map[i][j] = 0;
            global->map_enemy[i][j] = 0;
        }
    }
    global->framelimit = 60;
    global->stop = 0;
    global->state = 0;
    global->turn = 0;
    create_button(global);
    global->text = sfText_create();
    global->text2 = sfText_create();
    global->ip_text = sfText_create();
    global->text3 = sfText_create();
    global->text4 = sfText_create();
    global->your_ip = sfText_create();
    global->confirm = sfText_create();
    global->reset_map = sfText_create();
    sfText_setFont(global->text, global->font);
    sfText_setFont(global->text2, global->font);
    sfText_setFont(global->ip_text, global->font);
    sfText_setFont(global->text3, global->font);
    sfText_setFont(global->text4, global->font);
    sfText_setFont(global->your_ip, global->font);
    sfText_setFont(global->confirm, global->font);
    sfText_setFont(global->reset_map, global->font);
    sfText_setCharacterSize(global->text, 50);
    sfText_setCharacterSize(global->text2, 50);
    sfText_setCharacterSize(global->ip_text, 50);
    sfText_setCharacterSize(global->text3, 50);
    sfText_setCharacterSize(global->text4, 50);
    sfText_setCharacterSize(global->your_ip, 50);
    sfText_setCharacterSize(global->confirm, 50);
    sfText_setCharacterSize(global->reset_map, 50);
    sfText_setColor(global->text, sfWhite);
    sfText_setColor(global->text2, sfWhite);
    sfText_setColor(global->ip_text, sfWhite);
    sfText_setColor(global->text3, sfWhite);
    sfText_setColor(global->text4, sfWhite);
    sfText_setColor(global->your_ip, sfWhite);
    sfText_setColor(global->confirm, sfWhite);
    sfText_setColor(global->reset_map, sfWhite);
    sfText_setString(global->text, "Enter your choosen PORT number :");
    sfText_setString(global->text2, "");
    sfText_setString(global->ip_text, "");
    sfText_setString(global->text3, "Enter IP adress :");
    sfText_setString(global->text4, "Enter PORT number :");
    sfText_setString(global->your_ip, "");
    sfText_setString(global->confirm, "-> Confirm <-");
    sfText_setString(global->reset_map, "-> Reset map <-");

    global->volume_text = sfText_create();
    global->framelimit_text = sfText_create();
    global->framelimit_todisp_text = sfText_create();
    sfText_setString(global->volume_text, "Volume");
    sfText_setString(global->framelimit_text, "FPS");
    global->framelimit_todisp = malloc(sizeof(char) * 4);
    sprintf(global->framelimit_todisp, "%d", global->framelimit);
    sfText_setString(global->framelimit_todisp_text, global->framelimit_todisp);
    sfText_setPosition(global->volume_text, (sfVector2f){200, 240});
    sfText_setPosition(global->framelimit_text, (sfVector2f){200, 440});
    sfText_setPosition(global->framelimit_todisp_text, (sfVector2f){1020, 490});
    sfText_setFont(global->volume_text, global->font);
    sfText_setFont(global->framelimit_text, global->font);
    sfText_setFont(global->framelimit_todisp_text, global->font);
    sfText_setCharacterSize(global->volume_text, 50);
    sfText_setCharacterSize(global->framelimit_text, 50);
    sfText_setCharacterSize(global->framelimit_todisp_text, 50);
    sfText_setColor(global->volume_text, sfWhite);
    sfText_setColor(global->framelimit_text, sfWhite);
    sfText_setColor(global->framelimit_todisp_text, sfWhite);

    global->window = sfRenderWindow_create((sfVideoMode){1920, 1080, 32}, "Navy", sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(global->window, 30);
    global->texture_background = sfTexture_createFromFile("assets/wallpaper.jpg", NULL);
    global->sprite_background2_texture = sfTexture_createFromFile("assets/background.png", NULL);
    global->semi_back_texture = sfTexture_createFromFile("assets/font_opacity50.png", NULL);
    global->semi_back = sfSprite_create();
    sfSprite_setTexture(global->semi_back, global->semi_back_texture, sfTrue);
    global->sprite_background = sfSprite_create();
    sfSprite_setTexture(global->sprite_background, global->texture_background, sfTrue);
    global->shadow_texture = sfTexture_createFromFile("assets/black50percent.png", NULL);
    global->shadow = sfSprite_create();
    sfSprite_setTexture(global->shadow, global->shadow_texture, sfTrue);
    sfSprite_setPosition(global->button_login, (sfVector2f){760, 290});
    sfSprite_setPosition(global->button_register, (sfVector2f){760, 540});
    sfSprite_setPosition(global->button_back, (sfVector2f){760, 790});

    global->music = sfMusic_createFromFile("assets/music/navy_music.ogg");
    sfMusic_setLoop(global->music, sfTrue);
    sfMusic_setVolume(global->music, global->volume);
    sfMusic_play(global->music);
}

void menu_choose(global_t *global)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(global->window, &event)) {
        if (event.type == sfEvtClosed)
            global->stop = 1;
        if (event.type == sfEvtKeyPressed) {
            if (event.key.code == sfKeyEscape)
                exit(0);
        }
        if (event.type == sfEvtMouseButtonPressed) {
            if (event.mouseButton.x >= 760 && event.mouseButton.x <= 1080 && event.mouseButton.y >= 290 && event.mouseButton.y <= 470) {
                global->state = 7;
            }
            if (event.mouseButton.x >= 760 && event.mouseButton.x <= 1080 && event.mouseButton.y >= 540 && event.mouseButton.y <= 720) {
                global->state = 8;
            }
            if (event.mouseButton.x >= 770 && event.mouseButton.x <= 1030 && event.mouseButton.y >= 830 && event.mouseButton.y <= 920) {
                global->state = 0;
            }
        }
        if (sfMouse_getPositionRenderWindow(global->window).x >= 760 && sfMouse_getPositionRenderWindow(global->window).x <= 1090 && sfMouse_getPositionRenderWindow(global->window).y >= 290 && sfMouse_getPositionRenderWindow(global->window).y <= 470)
            sfSprite_setPosition(global->button_login, (sfVector2f){770, 300});
        else
            sfSprite_setPosition(global->button_login, (sfVector2f){760, 290});
        if (sfMouse_getPositionRenderWindow(global->window).x >= 760 && sfMouse_getPositionRenderWindow(global->window).x <= 1090 && sfMouse_getPositionRenderWindow(global->window).y >= 540 && sfMouse_getPositionRenderWindow(global->window).y <= 730)
            sfSprite_setPosition(global->button_register, (sfVector2f){770, 550});
        else
            sfSprite_setPosition(global->button_register, (sfVector2f){760, 540});
    }
    sfRenderWindow_clear(global->window, sfBlack);
    sfRenderWindow_drawSprite(global->window, global->sprite_background, NULL);
    sfSprite_setPosition(global->shadow, (sfVector2f){770, 300});
    sfRenderWindow_drawSprite(global->window, global->shadow, NULL);
    sfRenderWindow_drawSprite(global->window, global->button_login, NULL);
    sfSprite_setPosition(global->shadow, (sfVector2f){770, 550});
    sfRenderWindow_drawSprite(global->window, global->shadow, NULL);
    sfRenderWindow_drawSprite(global->window, global->button_register, NULL);
    sfSprite_setPosition(global->button_back, (sfVector2f){770, 800});
    sfRenderWindow_drawSprite(global->window, global->button_back, NULL);
    sfRenderWindow_display(global->window);
}

void help_function(void)
{
    printf("USAGE : ./navy\n");
    printf("    This is a multiplayer game, you can play with a friend (or with an AI ( coming soon ! ))\n");
    printf("    It open an CSFML window\n");
    printf("    You can actually choose between 4 thinks when start : \n");
    printf("        - Play\n");
    printf("        - Open Parameters\n");
    printf("        - Tree Skills (comming soon)\n");
    printf("        - Quit with [ESCAPE] Key\n");
    printf("    When you choose play, you can host or join a game in local : \n");
    printf("        - Host : you can create a game and wait for a player to join you\n");
    printf("        - Join : you can join a game hosted by a player\n");
    printf("    After, you can create your own map and place all different ship\n");
    printf("    You can take ship and put it by clicking and rotate it with [R] Key\n");
    printf("    When you are ready, you can start the game\n");
    printf("    You can play with your friend and try to sink all his ship before he sink yours\n");
    printf("    Click on his board when is your turn to shoot him\n");
    printf("    When you win, you can go back to the menu or quit with [ESCAPE] Key\n");
    printf("    Good Game !\n");
}

void game_tree(global_t *global)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(global->window, &event)) {
        if (event.type == sfEvtClosed)
            global->stop = 1;
        if (event.type == sfEvtKeyPressed) {
            if (event.key.code == sfKeyEscape)
                exit(0);
        }
        if (event.type == sfEvtMouseButtonPressed) {
            if (event.mouseButton.x >= 770 && event.mouseButton.x <= 1030 && event.mouseButton.y >= 830 && event.mouseButton.y <= 920) {
                global->state = 0;
            }
        }
    }
    sfRenderWindow_clear(global->window, sfBlack);
    sfRenderWindow_drawSprite(global->window, global->sprite_background, NULL);
    sfText_setString(global->text, "Coming Soon !");
    sfText_setPosition(global->text, (sfVector2f){770, 300});
    sfRenderWindow_drawText(global->window, global->text, NULL);
    sfSprite_setPosition(global->button_back, (sfVector2f){770, 800});
    sfRenderWindow_drawSprite(global->window, global->button_back, NULL);
    sfRenderWindow_display(global->window);
}

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        help_function();
        return (0);
    }
    global_t *global = malloc(sizeof(global_t));
    list *list = init();
    init_global(global, list);
    global->i = 0;
    global->port = malloc(sizeof(char) * 6);
    global->port[0] = '\0';
    global->ip = malloc(sizeof(char) * 16);
    global->ip[0] = '\0';
    global->a = 0;
    global->is_ip_or_port = 0;
    global->connected = 0;
    global->message = malloc(sizeof(char) * 100);
    global->clock = sfClock_create();
    set_button_menu_principal(global);
    global->start = 0;
    while (global->stop != 1) {
        global->pos_mouse = sfMouse_getPositionRenderWindow(global->window);
        if (global->state == 9) {
            menu_choose(global);
        }
        if (global->state == 0) {
            menu_principal(global);
        }
        if (global->state == 1) {
            create_map(global, list);
        }
        if (global->state == 10) {
            join_other(global);
        }
        if (global->state == 7) {
            host_game(global);
        }
        if (global->state == 8) {
            join_game(global);
        }
        if (global->state == 6) {
            settings(global);
        }
        if (global->state == 2) {
            game(global, list);
        }
        if (global->state == 5) {
            game_tree(global);
        }
        global->time = sfClock_getElapsedTime(global->clock);
    }
    sfMusic_stop(global->music);
    sfMusic_destroy(global->music);
    sfRenderWindow_close(global->window);
    sfRenderWindow_destroy(global->window);
    return 0;
}
