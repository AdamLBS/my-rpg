/*
** EPITECH PROJECT, 2022
** B-MUL-200-MAR-2-1-myrpg-niels.ouvrard
** File description:
** is_walking
*/

#include "my.h"
#include "rpg_header.h"

int is_moving(void)
{
    if (all_infos()->bo->move_d || all_infos()->bo->move_l
    || all_infos()->bo->move_r || all_infos()->bo->move_u) {
        return 1;
    }
    return 0;
}
