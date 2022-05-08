/*
** EPITECH PROJECT, 2022
** B-MUL-200-MAR-2-1-myrpg-niels.ouvrard
** File description:
** move_player_utils
*/

#include "rpg_header.h"
#include "my.h"

void move_pos_player_utils(char a)
{
    if (all_infos()->bo->move_r && can_move(5, 0)) {
        all_infos()->bo->can_move = true;
        all_infos()->move = 'r';
        move_sprint(5, 0);
        if (!all_infos()->bo->move_u && !all_infos()->bo->move_d)
            change_pos_and_views(3, 0);
    }
}
