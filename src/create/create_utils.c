/*
** EPITECH PROJECT, 2022
** B-MUL-200-MAR-2-1-myrpg-niels.ouvrard
** File description:
** create_utils
*/

#include "my.h"
#include "rpg_header.h"

void full_list_sprites_next(void)
{
    all_sprites()[SPRITE_SHEET].rect.height = 16;
    all_sprites()[SPRITE_SHEET].rect.width = 16;
    all_sprites()[SPRITE_SHEET].rect.top = 16;
    all_sprites()[SPRITE_SHEET].rect.left = 16;
    sfSprite_setTextureRect(all_sprites()[SPRITE_SHEET].sprite,
    all_sprites()[SPRITE_SHEET].rect);
    all_sprites()[SPRITE_SHEET].anim = '\0';
    all_sprites()[SPRITE_SHEET].scale.x = SCALE_TILE_SHEET;
    all_sprites()[SPRITE_SHEET].scale.y = SCALE_TILE_SHEET;
    sfSprite_setScale(all_sprites()[SPRITE_SHEET].sprite,
    all_sprites()[SPRITE_SHEET].scale);
    all_sprites()[BANANA].anim = '\0';
    all_sprites()[BANANA].scale.x = 10;
    all_sprites()[BANANA].scale.y = 10;
    sfSprite_setScale(all_sprites()[BANANA].sprite,
    all_sprites()[BANANA].scale);
    full_list_sprites_more_infos();
}
