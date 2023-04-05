/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** mlscene
*/

#include "mlsf.h"

void mlscene_destroy(mlscene *scene)
{
    for (int i = 0; i < scene->nb_element; i++) {
        if (scene->element[i]->type == 1)
            mlsprite_destroy(scene->element[i]->sprite);
        if (scene->element[i]->type == 2)
            mltext_destroy(scene->element[i]->text);
        if (scene->element[i]->type == 3)
            mlbutton_destroy(scene->element[i]->button);
        if (scene->element[i]->type == 4)
            mlcircle_destroy(scene->element[i]->circle);
        if (scene->element[i]->type == 5)
            mlanimation_destroy(scene->element[i]->animation);
    }
    free(scene->element);
    free(scene);
}
