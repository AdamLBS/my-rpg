/*
** EPITECH PROJECT, 2021
** game file 1
** File description:
** lib csfml
*/

#include "my.h"
#include "rpg_header.h"

static main_screen infos;

main_screen all_infos (void)
{
    return infos;
}

void creat_main (void)
{
    sfVideoMode mode = {SCREEN_MAX_X, SCREEN_MAX_Y, 60};
    infos.window = sfRenderWindow_create(mode, "RPG", sfResize | sfClose, NULL);
    infos.level = 0;
    infos.quit_main = 0;
    return;
}
