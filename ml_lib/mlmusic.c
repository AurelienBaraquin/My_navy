/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** mlmusic
*/

#include "mlsf.h"

void mlmusic_set_volume(mlmusic *music, int volume)
{
    music->volume = volume;
    sfMusic_setVolume(music->music, music->volume);
}

mlmusic *mlmusic_create(char *path)
{
    mlmusic *music = malloc(sizeof(mlmusic));
    music->path = path;
    music->music = sfMusic_createFromFile(path);
    music->volume = 100;
    sfMusic_setVolume(music->music, music->volume);
    sfMusic_play(music->music);
    sfMusic_setLoop(music->music, sfTrue);
    return music;
}
