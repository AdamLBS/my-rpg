/*
** EPITECH PROJECT, 2022
** snake_no_map.c
** File description:
** snake level 0
*/

#include "my.h"
#include "rpg_header.h"

void anim_perso (void)
{
    if (all_sprites()[GHOST].anim) {
        all_sprites()[GHOST].rect.left += 15;
        all_sprites()[GHOST].anim = false;
    } else {
        all_sprites()[GHOST].rect.left -= 15;
        all_sprites()[GHOST].anim = true;
    }
}

void event_level_1 (sfEvent event)
{
    while (sfRenderWindow_pollEvent(all_infos()->window, &event)) {
        if (event.type == sfEvtClosed) {
            all_infos()->quit_main = 1;
            return;
        }
        if (event.type == sfEvtKeyPressed) {
            if (event.key.code == sfKeySpace)
                all_infos()->level = 0;
            if (event.key.code == sfKeyA) {
                all_infos()->zoom += 0.01;
                all_sprites()[GROUND].scale.x += 0.01;
                all_sprites()[GROUND].scale.y += 0.01;
                sfSprite_setScale(all_sprites()[GROUND].sprite, all_sprites()[GROUND].scale);
            }
            if (event.key.code == sfKeyE) {
                all_infos()->zoom -= 0.01;
                all_sprites()[GROUND].scale.x -= 0.01;
                all_sprites()[GROUND].scale.y -= 0.01;
                sfSprite_setScale(all_sprites()[GROUND].sprite, all_sprites()[GROUND].scale);
            }
            if (event.key.code == sfKeyZ)
                all_infos()->pos_player.y -= 10;
            if (event.key.code == sfKeyS)
                all_infos()->pos_player.y += 10;
            if (event.key.code == sfKeyQ)
                all_infos()->pos_player.x -= 10;
            if (event.key.code == sfKeyD)
                all_infos()->pos_player.x += 10;
        }
    }
    return;
}

void disp_map (void)
{
    for (int i = 0; all_infos()->map[i]; i++) {
        for (int j = 0; all_infos()->map[i][j]; j++) {
            if (all_infos()->map[i][j] == 'c') {
                all_sprites()[GROUND].pos.x = all_infos()->pos_player.x + 50 * all_infos()->zoom * j;
                all_sprites()[GROUND].pos.y = all_infos()->pos_player.y + 50 * all_infos()->zoom * i;
                sfSprite_setPosition(all_sprites()[GROUND].sprite, all_sprites()[GROUND].pos);
                sfRenderWindow_drawSprite(all_infos()->window, all_sprites()[GROUND].sprite, NULL);
            } else if (all_infos()->map[i][j] == 'e') {
                all_sprites()[4].pos.x = all_infos()->pos_player.x + 50 * all_infos()->zoom * j;
                all_sprites()[4].pos.y = all_infos()->pos_player.y + 50 * all_infos()->zoom * i;
                sfSprite_setPosition(all_sprites()[4].sprite, all_sprites()[4].pos);
                sfRenderWindow_drawSprite(all_infos()->window, all_sprites()[4].sprite, NULL);
            }
        }
    }
}

void level_1 (sfEvent event)
{
    event_level_1(event);
    if (all_infos()->quit_main == 1) {
        return;
    }
    disp_map();
    sfRenderWindow_drawSprite(all_infos()->window, all_sprites()[GHOST].sprite, NULL);
    // sfRenderWindow_drawSprite(all_infos()->window, all_infos()->sprite_difficulty, NULL);
    return;
}
