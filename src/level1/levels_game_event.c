/*
** EPITECH PROJECT, 2022
** snake_no_map.c
** File description:
** snake level 0
*/

#include "my.h"
#include "rpg_header.h"

void change_scale(sfEvent event)
{
    if (event.key.code == all_keys()->zoom_out &&
    all_infos()->nb_of_zoom + 1 != 4) {
        sfView_zoom(all_infos()->view, 0.8);
        all_infos()->nb_of_zoom += 1;
    }
    if (event.key.code == all_keys()->zoom_in &&
    all_infos()->nb_of_zoom - 1 > 0) {
        sfView_zoom(all_infos()->view, 1.2);
        all_infos()->nb_of_zoom -= 1;
    }
    sfRenderWindow_setView(all_infos()->window, all_infos()->view);
}

void event_level_game_pressed_next(sfEvent event)
{
    if (event.key.code == all_keys()->k_sprint)
        all_infos()->sprint = true;
    if (event.key.code == all_keys()->k_up)
        all_infos()->move_u = true;
    if (event.key.code == all_keys()->k_left)
        all_infos()->move_l = true;
    if (event.key.code == all_keys()->k_down)
        all_infos()->move_d = true;
    if (event.key.code == all_keys()->k_right)
        all_infos()->move_r = true;
    if (event.key.code == all_keys()->k_open_bag)
        all_infos()->level = INVENTORY;
    if (event.key.code == sfKeyP)
        all_infos()->life--;
    if (event.key.code == sfKeyM) {
        increase_life();
    }
    check_stamina();
}

void event_npc(sfEvent event)
{
    npcs *npcs = all_maps()[all_infos()->map_actual].all_npcs;
    while (npcs) {
        if (event.key.code == sfKeyF && npcs->interaction == 1)
            all_infos()->level = DIALOGUE;
        npcs = npcs->next;
    }
}

void event_level_mission_pressed(sfEvent event)
{
    if (event.key.code == all_keys()->k_open_missions)
        all_infos()->level = MISSIONS;
}

void event_level_game_pressed(sfEvent event)
{
    if (event.key.code == all_keys()->shoot) {
        all_infos()->loading_bow = true;
        all_infos()->charging_ticks++;
        all_infos()->move = 'c';
        if (all_sprites()[HUNTER].rect.top == 16 ||
        all_sprites()[HUNTER].rect.top == 2 * 16) {
            all_sprites()[HUNTER].rect.top = 64;
        } else {
            all_sprites()[HUNTER].rect.top = 80;
        }
        all_sprites()[HUNTER].rect.left = 16 * 3;
    }
    if (event.key.code == sfKeyEscape)
        all_infos()->level = PAUSE_GAME;
    event_level_game_pressed_next(event);
    change_scale(event);
    event_npc(event);
    check_interact_chest(event);
    event_level_mission_pressed(event);
}
