/*
** EPITECH PROJECT, 2022
** B-MUL-200-MAR-2-1-myrpg-niels.ouvrard
** File description:
** manage_music
*/

#include "my.h"
#include "rpg_header.h"

void manage_music(void)
{
    t_sounds *sounds = all_infos()->sounds;
    if (!all_infos()->bo->music) {
        sfMusic_stop(sounds->music);
        return;
    }
    if (all_infos()->in->level != GAME)
        sfMusic_setVolume(sounds->music, 2);
    else
        sfMusic_setVolume(sounds->music, 5);
}
