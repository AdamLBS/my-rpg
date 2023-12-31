/*
** EPITECH PROJECT, 2022
** snake_no_map.c
** File description:
** snake level 0
*/

#include "my.h"
#include "rpg_header.h"

void disp_tile_sprite_seet_e(int i, int j, int top, int left)
{
    int type = SPRITE_SHEET;
    all_sprites()[type].rect.top = top;
    all_sprites()[type].rect.left = left;
    sfSprite_setTextureRect(all_sprites()[type].sprite,
    all_sprites()[type].rect);
    all_sprites()[type].pos.x = all_infos()->pos_player.x +
    (all_sprites()[type].scale.x * 16) * all_infos()->zoom * j;
    all_sprites()[type].pos.y = all_infos()->pos_player.y +
    (all_sprites()[type].scale.x * 16) * all_infos()->zoom * i;
    sfSprite_setPosition(all_sprites()[type].sprite, all_sprites()[type].pos);
    sfRenderWindow_drawSprite(all_infos()->window,
    all_sprites()[type].sprite, NULL);
}

void disp_map_editor_next(char **map, int i, int j)
{
    if (!(map[i][j] >= '0' && map[i][j] <= '0' + NMB_TILES))
        return;
    int x = map[i][j] - '0';
    x *= 16;
    int y = 0;
    while (x >= SIZE_TILE_SHEET_X) {
        y += 16;
        x -= SIZE_TILE_SHEET_X;
    }
    disp_tile_sprite_seet_e(i, j, y, x);
}

void disp_map_editor(char **map)
{
    for (int i = 0; map[i]; i++)
        for (int j = 0; map[i][j]; j++)
            disp_map_editor_next(map, i, j);
}

void disp_value_to_print(void)
{
    sfSprite_setTextureRect(all_sprites()[SPRITE_SHEET].sprite,
    (sfIntRect){0, 0, SIZE_TILE_SHEET_X, SIZE_TILE_SHEET_Y});
    sfSprite_setPosition(all_sprites()[SPRITE_SHEET].sprite,
    (sfVector2f){0, 0});
    sfRenderWindow_drawSprite(all_infos()->window,
    all_sprites()[SPRITE_SHEET].sprite, NULL);
}
