/*
** EPITECH PROJECT, 2022
** B-MUL-200-MAR-2-1-myrpg-niels.ouvrard
** File description:
** sound_utils
*/

#include "my.h"
#include "rpg_header.h"

void stop_all_sounds_2(char c, char mg)
{
    if (c == 'F' || mg == 'l' || mg == 'm' || mg == 'n' && is_moving()) {
        check_status(all_infos()->sounds->wood);
        stop_sound(all_infos()->sounds->grass);
        stop_sound(all_infos()->sounds->stone);
    }
}