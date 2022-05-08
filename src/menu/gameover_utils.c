/*
** EPITECH PROJECT, 2022
** B-MUL-200-MAR-2-1-mydefender-gabriel.de-souza-morais
** File description:
** gameover_utils
*/

#include "my.h"
#include "rpg_header.h"

void initialize_bounds_end_game(tags *game)
{
    game->f_rects->quit_button_b =
    sfSprite_getGlobalBounds(game->sprites->squit);
    game->f_rects->quit_button_b.width = 420;
    game->f_rects->menu_button_b =
    sfSprite_getGlobalBounds(game->sprites->srestart);
    game->f_rects->menu_button_b.width = 420;
}

void analyse_events_end_game(tags *game)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(all_infos()->window, &event)) {
        if (event.type == sfEvtClosed)
            all_infos()->quit_main = 1;
        if (event.type == sfEvtMouseButtonPressed)
            manage_mouse_click_end_game(game);
    }
}
