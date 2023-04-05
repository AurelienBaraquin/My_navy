/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** mlkeyboard
*/

#include "mlsf.h"

int mlkeyboard_is_key_pressed(int key)
{
    if (sfKeyboard_isKeyPressed(key) == sfTrue)
        return 1;
    return 0;
}

int mlkeyboard_is_key_released(int key)
{
    if (sfKeyboard_isKeyPressed(key) == sfFalse)
        return 1;
    return 0;
}
