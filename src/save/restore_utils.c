/*
** EPITECH PROJECT, 2022
** B-MUL-200-MAR-2-1-myrpg-niels.ouvrard
** File description:
** restore_utils
*/

#include "my.h"
#include "rpg_header.h"

void restore_health_points(int type, char *buffer)
{
    if (type != 8)
        return;
    all_infos()->life = my_getnbr(buffer);
}

void restore_life_size(int type, char *buffer)
{
    if (type != 9)
        return;
    all_infos()->life_size = my_getnbr(buffer);
}

void restore_player_type(int type, char *buffer)
{
    if (type != 10)
        return;
    int player_type = my_getnbr(buffer);
    if (player_type == 1) {
        all_sprites()[HUNTER].texture = create_texture("pictures/Characters/Hunter/Hunter.png");
        sfSprite_setTexture(all_sprites()[HUNTER].sprite, all_sprites()[HUNTER].texture, sfTrue);
    }
    if (player_type == 2) {
        all_sprites()[HUNTER].texture = create_texture("pictures/Characters/Hunter/Hunter_blue.png");
        sfSprite_setTexture(all_sprites()[HUNTER].sprite, all_sprites()[HUNTER].texture, sfTrue);
    }
    all_infos()->player_type = player_type;
    return;
}

void restore_nb_of_enemies(int type, char *buffer)
{
    if (type != 11)
        return;
    all_infos()->nb_of_enemies_outside = my_getnbr(buffer);
    return;
}
