/*
** EPITECH PROJECT, 2022
** B-MUL-200-MAR-2-1-myrpg-niels.ouvrard
** File description:
** level_utils
*/

#include "my.h"
#include "rpg_header.h"

void malloc_all(tags *game)
{
    game->f_rects = malloc(sizeof(f_rect));
    game->sprites = malloc(sizeof(t_sprites));
    game->text = malloc(sizeof(t_text));
    initialize_sprite_menu(game);
    initialize_bounds_menu(game);
    inicialize_variables_option(game);
    inicialize_sprite_option(game);
    initialize_options_game(game);
}

void game_loop2(tags *game, sfEvent event)
{
    if (all_infos()->in->level == INVENTORY)
        level_inventory(event);
    if (all_infos()->in->level == DIALOGUE)
        level_quest();
    if (all_infos()->in->level == MISSIONS)
        level_missions();
    if (all_infos()->in->level == BONUS)
        level_bonus();
    if (all_infos()->in->level == CHEST)
        chest_level();
    if (all_infos()->in->level == OPTIONS)
        level_option(game);
    if (all_infos()->in->level == CHOSE_NPC)
        level_selection(game);
    if (all_infos()->in->level == STORY)
        story();
    if (all_infos()->in->level == PAUSE_GAME)
        level_pause(game);
    game_loop3(game, event);
}

void game_loop3(tags *game, sfEvent event)
{
    if (all_infos()->in->level == MAP_EDITOR)
        level_map_editor(event);
    if (all_infos()->in->level == END)
        level_end(game);
}
