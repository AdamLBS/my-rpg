/*
** EPITECH PROJECT, 2022
** B-MUL-200-MAR-2-1-myrpg-niels.ouvrard
** File description:
** enemies_list
*/

#include "my.h"
#include "rpg_header.h"

// int size_list(enemies *expl)
// {
//     int a = 0;
//     while (expl) {
//         a++;
//         expl = expl->next;
//     }
//     return a;
// }

void add_enemies_to_list(int map, int value, int x, int y)
{
    enemies *new_enemy = malloc(sizeof(enemies));
    new_enemy->pos.x = x;
    new_enemy->pos.y = y;
    new_enemy->value = value;
    new_enemy->next = NULL;
    if (all_maps()[map].all_ennemis == NULL) {
        all_maps()[map].all_ennemis = new_enemy;
        return;
    }
    enemies *last = all_maps()[map].all_ennemis;
    while (last->next != NULL)
        last = last->next;
    last->next = new_enemy;
}

void explor_map_find_all_ennemis_next(int map, int i, int j)
{
    char *c = &all_maps()[map].fg[i][j];
    if ((*c) >= '0')
        return;
    if (c[0] == 47)
        add_enemies_to_list(map, DEMON, j * SIZE_TILE, (i * SIZE_TILE) + 16);
    else if (c[0] == 46)
        add_enemies_to_list(map, NINJA, j * SIZE_TILE, (i * SIZE_TILE) + 16);
    c[0] = 'R';
}

void explor_map_find_all_ennemis(int map)
{
    all_maps()[map].all_ennemis = NULL;
    for (int i = 0; all_maps()[map].fg[i]; i++)
        for (int j = 0; all_maps()[map].fg[i][j]; j++)
            explor_map_find_all_ennemis_next(map, i, j);
}
// my_printf("%d ennemis in map %d\n", size_list(all_maps()[map].all_ennemis), map);

void disp_all_ennemsi (void)
{
    enemies *expl = all_maps()[all_infos()->map_actual].all_ennemis;
    while (expl) {
        sfSprite_setPosition(all_sprites()[expl->value].sprite, expl->pos);
        sfRenderWindow_drawSprite(all_infos()->window, all_sprites()[expl->value].sprite, NULL);
        expl = expl->next;
    }
}

// 47 = DEMON
// 46 = NUNJA
