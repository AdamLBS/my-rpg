/*
** EPITECH PROJECT, 2021
** game file 1
** File description:
** lib csfml
*/

#include "my.h"
#include "rpg_header.h"

void full_perso(int type, int x, int y)
{
    all_sprites()[type].origin.x = 8;
    all_sprites()[type].origin.y = 16;
    sfSprite_setOrigin(all_sprites()[type].sprite, all_sprites()[type].origin);
    all_sprites()[type].anim = 'a';
    all_sprites()[type].scale.x = 3;
    all_sprites()[type].scale.y = 3;
    sfSprite_setScale(all_sprites()[type].sprite, all_sprites()[type].scale);
    all_sprites()[type].pos.y = y;
    all_sprites()[type].pos.x = x;
    sfSprite_setPosition(all_sprites()[type].sprite, all_sprites()[type].pos);
    all_sprites()[type].rect.height = 16;
    all_sprites()[type].rect.width = 16;
    all_sprites()[type].rect.top = 16;
    all_sprites()[type].rect.left = 16;
    sfSprite_setTextureRect(all_sprites()[type].sprite,
    all_sprites()[type].rect);
}

void origin_in_8_8_scale(int sprite)
{
    all_sprites()[sprite].origin.x = 8;
    all_sprites()[sprite].origin.y = 8;
    sfSprite_setOrigin(all_sprites()[sprite].sprite,
    all_sprites()[sprite].origin);
    all_sprites()[sprite].scale.x = 1.4;
    all_sprites()[sprite].scale.y = 1.4;
    sfSprite_setScale(all_sprites()[sprite].sprite,
    all_sprites()[sprite].scale);
}

void full_list_sprites_more_infos_3(void)
{
    sfSprite_setTextureRect(all_sprites()[BALLON].sprite,
    all_sprites()[BALLON].rect);
    sfSprite_setPosition(all_sprites()[BALLON].sprite,
    (sfVector2f) {550, 437});
    sfSprite_setTextureRect(all_sprites()[PARCHMENT].sprite,
    all_sprites()[PARCHMENT].rect);
    sfSprite_setPosition(all_sprites()[PARCHMENT].sprite,
    (sfVector2f) {620, 270});
    all_sprites()[WRITE_BOX].scale.x = 2;
    all_sprites()[WRITE_BOX].scale.y = 2;
    sfSprite_setScale(all_sprites()[WRITE_BOX].sprite,
    all_sprites()[WRITE_BOX].scale);
    all_sprites()[WRITE_BOX].rect.height = 300;
    all_sprites()[WRITE_BOX].rect.width = 500;
    all_sprites()[WRITE_BOX].rect.left = 0;
    all_sprites()[WRITE_BOX].rect.top = 0;
    sfSprite_setTextureRect(all_sprites()[WRITE_BOX].sprite,
    all_sprites()[WRITE_BOX].rect);
    sfSprite_setPosition(all_sprites()[WRITE_BOX].sprite,
    (sfVector2f) {500, 250});
}

void full_list_sprites_more_infos_2(void)
{
    all_sprites()[BALLON].scale.x = 1.8;
    all_sprites()[BALLON].scale.y = 1.8;
    sfSprite_setScale(all_sprites()[BALLON].sprite,
    all_sprites()[BALLON].scale);
    all_sprites()[BALLON].rect.height = 350;
    all_sprites()[BALLON].rect.width = 820;
    all_sprites()[BALLON].rect.left = 0;
    all_sprites()[BALLON].rect.top = 0;
    all_sprites()[PARCHMENT].scale.x = 1.5;
    all_sprites()[PARCHMENT].scale.y = 1.5;
    sfSprite_setScale(all_sprites()[PARCHMENT].sprite,
    all_sprites()[PARCHMENT].scale);
    all_sprites()[PARCHMENT].rect.height = 357;
    all_sprites()[PARCHMENT].rect.width = 500;
    all_sprites()[PARCHMENT].rect.left = 0;
    all_sprites()[PARCHMENT].rect.top = 0;
    full_list_sprites_more_infos_3();
}

void full_list_sprites_more_infos(void)
{
    full_perso(HUNTER, 10 * 50, 10 * 35);
    full_perso(DEMON, 500, 240);
    full_perso(NINJA, 700, 1000);
    full_perso(NPC, 900, 1000);
    full_perso(NPC2, 1100, 1200);
    full_perso(NPC3, 1300, 1400);
    full_perso(NPC4, 1300, 1400);
    origin_in_8_8_scale(EMPTY_BOX);
    origin_in_8_8_scale(CHECK_BOX);
    origin_in_8_8_scale(CROSS_BOX);
    origin_in_8_8_scale(SELEC_BOX);
    origin_in_8_8_scale(APPLE);
    origin_in_8_8_scale(BANANA);
    all_sprites()[LIFE].origin.x = 8;
    all_sprites()[LIFE].origin.y = 8;
    sfSprite_setOrigin(all_sprites()[LIFE].sprite, all_sprites()[LIFE].origin);
    all_sprites()[LIFE].scale.x = 3.125;
    all_sprites()[LIFE].scale.y = 3.125;
    sfSprite_setScale(all_sprites()[LIFE].sprite, all_sprites()[LIFE].scale);
    full_list_sprites_more_infos_2();
}
