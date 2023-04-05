/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** mlscene
*/

#include "mlsf.h"

void mlscene_add_circle(mlscene *scene, mlcircle *circle)
{
    mlelement *element = malloc(sizeof(mlelement));
    element->circle = circle;
    element->type = 4;
    mlscene_add_element(scene, element);
}

void mlscene_add_animation(mlscene *scene, mlanimation *animation)
{
    mlelement *element = malloc(sizeof(mlelement));
    element->animation = animation;
    element->type = 5;
    mlscene_add_element(scene, element);
}

void mlscene_remove_element(mlscene *scene, int index)
{
    if (index >= scene->nb_element)
        return;
    if (scene->element[index]->type == 1)
        mlsprite_destroy(scene->element[index]->sprite);
    if (scene->element[index]->type == 2)
        mltext_destroy(scene->element[index]->text);
    if (scene->element[index]->type == 3)
        mlbutton_destroy(scene->element[index]->button);
    if (scene->element[index]->type == 4)
        mlcircle_destroy(scene->element[index]->circle);
    if (scene->element[index]->type == 5)
        mlanimation_destroy(scene->element[index]->animation);
    for (int i = index; i < scene->nb_element - 1; i++)
        scene->element[i] = scene->element[i + 1];
    scene->nb_element--;
    scene->element = realloc(scene->element,
    sizeof(mlelement) * scene->nb_element);
}

void mlscene_display(mlwindow *window, mlscene *scene)
{
    for (int i = 0; i < scene->nb_element; i++) {
        if (scene->element[i]->type == 1)
            mlsprite_display(window, scene->element[i]->sprite);
        if (scene->element[i]->type == 2)
            mltext_display(window, scene->element[i]->text);
        if (scene->element[i]->type == 3)
            mlbutton_display(window, scene->element[i]->button);
        if (scene->element[i]->type == 4)
            mlcircle_display(window, scene->element[i]->circle);
        if (scene->element[i]->type == 5)
            mlanimation_display(window, scene->element[i]->animation);
    }
}

void mlscene_update(mlwindow *window, mlscene *scene)
{
    for (int i = 0; i < scene->nb_element; i++) {
        if (scene->element[i]->type == 1)
            mlsprite_update(window, scene->element[i]->sprite);
        if (scene->element[i]->type == 3)
            mlbutton_update(window, scene->element[i]->button);
        if (scene->element[i]->type == 4)
            mlcircle_update(window, scene->element[i]->circle);
        if (scene->element[i]->type == 5)
            mlanimation_update(window, scene->element[i]->animation);
    }
}
