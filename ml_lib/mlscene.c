/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** mlscene
*/

#include "mlsf.h"

mlscene *mlscene_create(void)
{
    mlscene *scene = malloc(sizeof(mlscene));
    scene->element = malloc(sizeof(mlelement));
    scene->nb_element = 0;
    return scene;
}

void mlscene_add_element(mlscene *scene, mlelement *element)
{
    scene->element = realloc(scene->element,
    sizeof(mlelement) * (scene->nb_element + 1));
    scene->element[scene->nb_element] = element;
    scene->nb_element++;
}

void mlscene_add_sprite(mlscene *scene, mlsprite *sprite)
{
    mlelement *element = malloc(sizeof(mlelement));
    element->sprite = sprite;
    element->type = 1;
    mlscene_add_element(scene, element);
}

void mlscene_add_text(mlscene *scene, mltext *text)
{
    mlelement *element = malloc(sizeof(mlelement));
    element->text = text;
    element->type = 2;
    mlscene_add_element(scene, element);
}

void mlscene_add_button(mlscene *scene, mlbutton *button)
{
    mlelement *element = malloc(sizeof(mlelement));
    element->button = button;
    element->type = 3;
    mlscene_add_element(scene, element);
}
