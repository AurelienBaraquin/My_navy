/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** mlsf.h
*/

#ifndef MY_LIB_MLSF_H
    #define MY_LIB_MLSF_H

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Network.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/stat.h>

typedef struct mlsprite {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f pos_click;
    sfVector2f pos_hover;
    sfIntRect rect;
    sfVector2f origin;
    float rotation;
    sfColor color;
    sfVector2f size;
    int is_click;
    int is_hover;
} mlsprite;

typedef struct mltext {
    sfText *text;
    sfFont *font;
    sfVector2f pos;
    sfColor color;
    int size;
    char *str;
} mltext;

typedef struct mlwindow {
    sfRenderWindow *window;
    sfVideoMode mode;
    sfColor color;
    char *name;
    int fps;
    int isopen;
    int width;
    int height;
    sfEvent event;
    int mouse_pressed;
} mlwindow;

typedef struct mlclock {
    sfClock *clock;
    sfTime time;
    float seconds;
} mlclock;

typedef struct mlanimation {
    mlsprite *sprite;
    sfIntRect rect;
    int nb_frame;
    int current_frame;
    int is_loop;
    int is_play;
    int is_end;
    int is_reverse;
    int is_pause;
    int is_stop;
    int is_click;
    int is_hover;
} mlanimation;

typedef struct mlmusic {
    sfMusic *music;
    char *path;
    int volume;
} mlmusic;

typedef struct mlbutton {
    sfRectangleShape *rect;
    sfVector2f pos;
    sfVector2f pos_click;
    sfVector2f pos_hover;
    sfVector2f size;
    sfVector2f size_click;
    sfVector2f size_hover;
    sfColor color;
    sfColor color_hover;
    sfColor color_click;
    int is_hover;
    int is_click;
    mltext *text;
} mlbutton;

typedef struct mlcircle {
    sfCircleShape *circle;
    sfVector2f pos;
    sfColor color;
    sfColor color_hover;
    sfColor color_click;
    sfVector2f pos_click;
    sfVector2f pos_hover;
    float radius;
    float radius_click;
    float radius_hover;
    int is_hover;
    int is_click;
} mlcircle;

typedef struct mlscrolling_sprite {
    mlsprite *sprite;
    sfVector2f pos;
    sfVector2f init_pos;
    sfVector2f size;
    sfIntRect rect;
    sfVector2f origin;
    float rotation;
    sfColor color;
    sfVector2f speed;
} mlscrolling_sprite;

typedef struct mlview {
    sfView *view;
    sfVector2f pos;
    sfVector2f size;
    sfVector2f center;
    sfVector2f rotation;
    sfVector2f zoom;
} mlview;

typedef struct mlmouse {
    sfVector2i pos_i;
    sfVector2f pos_f;
    int is_pressed;
} mlmouse;

typedef struct mlelement {
    mlsprite *sprite;
    mltext *text;
    mlbutton *button;
    mlcircle *circle;
    mlanimation *animation;
    int type;
} mlelement;

typedef struct mlscene {
    mlelement **element;
    int nb_element;
} mlscene;

typedef struct mlgame {
    mlwindow *window;
    mlscene **scene;
    int nb_scene;
    int current_scene;
} mlgame;

mlsprite *mlsprite_create(char *path, sfVector2f pos, sfVector2f size);
void mlsprite_set_position(mlsprite *sprite, sfVector2f position);
int mlsprite_is_click(mlsprite *sprite, sfVector2i mouse);
void mlsprite_update(mlwindow *window, mlsprite *sprite);
mltext *mltext_create(char *str, char *font, int size, sfColor color, sfVector2f pos);
mlwindow *mlwindow_create(int width, int height, char *name, int fps);
void mlwindow_destroy(mlwindow *window);
mlclock *mlclock_create(void);
mlmusic *mlmusic_create(char *path);
mlbutton *mlbutton_create(sfVector2f pos, sfVector2f size, sfColor color);
mlcircle *mlcircle_create(sfVector2f pos, float radius, sfColor color);
mlmouse *mlmouse_create(mlwindow *window);
void mlbutton_set_click(mlbutton *button, sfVector2f pos, sfVector2f size,
sfColor color);
void mlbutton_set_hover(mlbutton *button, sfVector2f pos, sfVector2f size,
sfColor color);
void mlbutton_update(sfWindow *window, mlbutton *button);
void mlbutton_display(mlwindow *window, mlbutton *button);
void mlclock_restart(mlclock *clock);
float mlclock_update(mlclock *clock);
void mlmusic_set_volume(mlmusic *music, int volume);
void mlsprite_display(mlwindow *window, mlsprite *sprite);
void mltext_display(mlwindow *window, mltext *text);
void mlwindow_clear(mlwindow *window);
void mlwindow_display(mlwindow *window);
void mlwindow_close(mlwindow *window);
int mlevent_quit(mlwindow *window);
int mlevent_key_pressed(mlwindow *window, sfKeyCode key);
int mlevent_mouse_pressed(mlwindow *window, sfMouseButton button);
int mlbutton_is_hover(mlbutton *button, sfVector2i mouse);
int mlsprite_is_hover(mlsprite *sprite, sfVector2i mouse);
void mlcircle_set_click(mlcircle *circle, sfVector2f pos, float radius,
sfColor color);
void mlcircle_set_hover(mlcircle *circle, sfVector2f pos, float radius,
sfColor color);
void mlcircle_update(mlwindow *window, mlcircle *circle);
void mlcircle_display(mlwindow *window, mlcircle *circle);
void mlmouse_update(mlwindow *window, mlmouse *mouse);
void mlbutton_destroy(mlbutton *button);
void mlcircle_destroy(mlcircle *circle);
void mlsprite_destroy(mlsprite *sprite);
void mltext_destroy(mltext *text);
int mlkeyboard_is_key_released(int key);
int mlkeyboard_is_key_pressed(int key);

mlscene *mlscene_create(void);
void mlscene_update(mlwindow *window, mlscene *scene);
void mlscene_add_element(mlscene *scene, mlelement *element);
void mlscene_add_sprite(mlscene *scene, mlsprite *sprite);
void mlscene_add_text(mlscene *scene, mltext *text);
void mlscene_add_button(mlscene *scene, mlbutton *button);
void mlscene_add_animation(mlscene *scene, mlanimation *animation);
void mlscene_add_circle(mlscene *scene, mlcircle *circle);
void mlscene_display(mlwindow *window, mlscene *scene);
void mlscene_destroy(mlscene *scene);

mlgame *mlgame_create(int width, int height, char *name, int fps);
void mlgame_add_scene(mlgame *game, mlscene *scene);
int mlgame_set_scene(mlgame *game, int scene);
int mlgame_remove_scene(mlgame *game, int scene);
void mlgame_set_fps(mlgame *game, int fps);
void mlgame_display(mlgame *game);
void mlgame_destroy(mlgame *game);

mlanimation *mlanimation_create(mlsprite *sprite, int nb_frame, int is_loop);
void mlanimation_destroy(mlanimation *animation);
int mlanimation_update(mlwindow *window, mlanimation *animation);
void mlanimation_display(mlwindow *window, mlanimation *animation);
void mlanimation_play(mlanimation *animation);
void mlanimation_pause(mlanimation *animation);
void mlanimation_stop(mlanimation *animation);
void mlanimation_reverse(mlanimation *animation);
void mlanimation_normal(mlanimation *animation);
void mlanimation_set_frame(mlanimation *animation, int frame);
void mlanimation_set_loop(mlanimation *animation, int is_loop);
void mlanimation_set_position(mlanimation *animation, sfVector2f position);

mlscrolling_sprite *mlscrolling_sprite_create(char *path, sfVector2f pos,
sfVector2f size, sfVector2f speed);
void mlscrolling_sprite_display(mlwindow *window, mlscrolling_sprite *sprite);
void mlscrolling_sprite_update(mlwindow *window, mlscrolling_sprite *sprite);
void mlscrolling_sprite_destroy(mlscrolling_sprite *sprite);

mlview *mlview_create(sfVector2f pos, sfVector2f size);
void mlview_display(mlwindow *window, mlview *view);
void mlview_destroy(mlview *view);

#endif /* !MY_LIB_MLSF_H */
