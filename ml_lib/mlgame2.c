/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** mlgame
*/

#include "mlsf.h"

int mlgame_remove_scene(mlgame *game, int scene)
{
    if (scene >= game->nb_scene)
        return -1;
    for (int i = scene; i < game->nb_scene; i++)
        game->scene[i] = game->scene[i + 1];
    game->scene = realloc(game->scene,
    sizeof(mlscene) * (game->nb_scene - 1));
    game->nb_scene--;
    return scene;
}

void mlgame_set_fps(mlgame *game, int fps)
{
    game->window->fps = fps;
    sfRenderWindow_setFramerateLimit(game->window->window, game->window->fps);
}

void mlgame_display_next(mlgame *game, int i)
{
    if (game->scene[game->current_scene]->element[i]->type == 1)
        mlsprite_display(game->window,
        game->scene[game->current_scene]->element[i]->sprite);
    if (game->scene[game->current_scene]->element[i]->type == 2)
        mltext_display(game->window,
        game->scene[game->current_scene]->element[i]->text);
    if (game->scene[game->current_scene]->element[i]->type == 3)
        mlbutton_display(game->window,
        game->scene[game->current_scene]->element[i]->button);
    if (game->scene[game->current_scene]->element[i]->type == 4)
        mlcircle_display(game->window,
        game->scene[game->current_scene]->element[i]->circle);
    if (game->scene[game->current_scene]->element[i]->type == 5)
        mlanimation_display(game->window,
        game->scene[game->current_scene]->element[i]->animation);
}

void mlgame_display(mlgame *game)
{
    while (game->window->isopen) {
        mlwindow_clear(game->window);
        for (int i = 0; i < game->scene[game->current_scene]->nb_element; i++) {
            mlgame_display_next(game, i);
        }
        mlwindow_display(game->window);
    }
}

void mlgame_destroy(mlgame *game)
{
    mlwindow_destroy(game->window);
    for (int i = 0; i < game->nb_scene; i++)
        mlscene_destroy(game->scene[i]);
    free(game->scene);
    free(game);
}
