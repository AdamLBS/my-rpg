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
