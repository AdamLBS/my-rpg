/*
** EPITECH PROJECT, 2022
** B-MUL-200-MAR-2-1-myrpg-niels.ouvrard
** File description:
** utils_save
*/

#include "my.h"
#include "rpg_header.h"

sfVector2f handle_view_pos(char *buffer, int *type, int run, sfVector2f pos)
{
    if (*type != 2)
        return pos;
    if (run == 1) {
        int x = my_getnbr(buffer);
        pos.x = x;
    } else {
        int y = my_getnbr(buffer);
        pos.y = y;
        sfView_setCenter(all_infos()->view, pos);
        *type = 0;
    }
    return pos;
}

void handle_map_actual(int *type, char *buffer)
{
    if (*type != 3)
        return;
    all_infos()->map_actual = my_getnbr(buffer);
    *type = 0;
    return;
}

void handle_inventory(char *buffer, int *type)
{
    int nb = 0;
    if (*type != 4)
        return;
    add_to_inventory(&all_infos()->inventory, my_getnbr(buffer));
    return;
}

void handle_player_pos(char *buffer, int *type, int run)
{
    if (*type != 1)
        return;
    if (run == 1) {
        int x = my_getnbr(buffer);
        all_sprites()[HUNTER].pos.x = x;
    } else {
        int y = my_getnbr(buffer);
        all_sprites()[HUNTER].pos.y = y;
        sfSprite_setPosition(all_sprites()[HUNTER].sprite,
        all_sprites()[HUNTER].pos);
        *type = 0;
    }
    return;
}
