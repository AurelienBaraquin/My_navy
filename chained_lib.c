/*
** EPITECH PROJECT, 2023
** name
** File description:
** desc
*/

#include "navy.h"

list *init(void)
{
    list *list = malloc(sizeof(list));
    list->first = NULL;
}

void insertion(list *liste, int nb, char *filepath, int size)
{
    element_t *nouvelElement = malloc(sizeof(element_t));
    nouvelElement->number = nb;
    nouvelElement->is_click = 0;
    nouvelElement->sizey = size;
    nouvelElement->sizex = 50;
    nouvelElement->sizey_keep = size;
    nouvelElement->sizex_keep = 50;
    nouvelElement->rotate = 0;
    nouvelElement->sprite = sfSprite_create();
    nouvelElement->texture = sfTexture_createFromFile(filepath, NULL);
    sfSprite_setTexture(nouvelElement->sprite, nouvelElement->texture, sfTrue);
    nouvelElement->pos = (sfVector2f){0, 0};
    sfSprite_setPosition(nouvelElement->sprite, nouvelElement->pos);
    nouvelElement->placed = 0;
    nouvelElement->next = liste->first;
    liste->first = nouvelElement;
}

void suppression(list *list)
{
    element_t *temp = list->first;
    list->first = list->first->next;
    free(temp);
}

void remove_last(list *liste)
{
    element_t *temp = liste->first;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    temp->next = NULL;
}

void print_list(list * liste)
{
    if ( liste == NULL )
        return ;
    element_t * actuel = liste->first ;
    while ( actuel != NULL ) {
        printf ("number = %d - ", actuel->number);
        printf ("is_click = %d", actuel->is_click);
        actuel = actuel->next ;
    }
}