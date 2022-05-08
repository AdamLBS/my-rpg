/*
** EPITECH PROJECT, 2022
** B-MUL-200-MAR-2-1-myrpg-niels.ouvrard
** File description:
** level_game_utils
*/

#include "my.h"
#include "rpg_header.h"

void event_level_game_relased_next (sfEvent event)
{
    bow_release();
    if (!sfKeyboard_isKeyPressed(all_keys()->k_sprint))
        all_infos()->bo->sprint = false;
    if (!sfKeyboard_isKeyPressed(all_keys()->k_left))
        all_infos()->bo->move_l = false;
    if (!sfKeyboard_isKeyPressed(all_keys()->k_right))
        all_infos()->bo->move_r = false;
    if (!sfKeyboard_isKeyPressed(all_keys()->k_up))
        all_infos()->bo->move_u = false;
    if (!sfKeyboard_isKeyPressed(all_keys()->k_down))
        all_infos()->bo->move_d = false;
    if (!all_infos()->bo->move_u && !all_infos()->bo->move_d &&
    !all_infos()->bo->move_l && !all_infos()->bo->move_r)
        all_infos()->move = '\0';
    sfSprite_setTextureRect(all_sprites()[HUNTER].sprite,
    all_sprites()[HUNTER].rect);
}

void event_level_game_relased(sfEvent event)
{
    if (all_infos()->move == 'c' &&
    !sfKeyboard_isKeyPressed(all_keys()->shoot)) {
        all_sprites()[HUNTER].rect.left = 0;
        all_infos()->move = all_infos()->last_move;
        if (all_infos()->move == 'l' || all_infos()->move == 'd') {
            all_sprites()[HUNTER].rect.top = 32;
        } else if (all_infos()->move == 'r' || all_infos()->move == 'u') {
            all_sprites()[HUNTER].rect.top = 48;
        } else {
            all_sprites()[HUNTER].rect.top = 16;
        }
    }
    event_level_game_relased_next(event);
}

void event_level_game(sfEvent event)
{
    if (!all_infos()->bo->first_run && !all_infos()->bo->save) {
        full_perso(HUNTER, all_infos()->pos_player.x,
        all_infos()->pos_player.y);
        all_infos()->bo->first_run = true;
    }
    while (sfRenderWindow_pollEvent(all_infos()->window, &event)) {
        if (event.type == sfEvtClosed) {
            all_infos()->in->quit_main = 1;
            return;
        }
        if (event.type == sfEvtKeyPressed)
            event_level_game_pressed(event);
        if (event.type == sfEvtKeyReleased)
            event_level_game_relased(event);
    }
    return;
}
