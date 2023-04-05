/*
** EPITECH PROJECT, 2023
** B-PSU-100-MPL-1-1-navy-aurelien.baraquin
** File description:
** connection_mulit
*/

#include "navy.h"

int win_condition(global_t *global)
{
    int a = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (global->map_enemy[i][j] == -2)
                a++;
        }
    }
    if (a == 16)
        return 1;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (global->map[i][j] >= 1)
                return 0;
        }
    }
    return 2;
}
