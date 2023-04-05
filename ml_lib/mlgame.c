/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** mlgame
*/

#include "mlsf.h"

mlgame *mlgame_create(int width, int height, char *name, int fps)
{
    mlgame *game = malloc(sizeof(mlgame));
    game->window = mlwindow_create(width, height, name, fps);
    game->scene = malloc(sizeof(mlscene));
    game->nb_scene = 0;
    game->current_scene = 0;
    return game;
}

void mlgame_add_scene(mlgame *game, mlscene *scene)
{
    game->scene = realloc(game->scene,
    sizeof(mlscene) * (game->nb_scene + 1));
    game->scene[game->nb_scene] = scene;
    game->nb_scene++;
}

int mlgame_set_scene(mlgame *game, int scene)
{
    if (scene >= game->nb_scene)
        return -1;
    game->current_scene = scene;
    return scene;
}
