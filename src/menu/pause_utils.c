/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** pause_utils
*/

#include "my.h"
#include "rpg_header.h"

void mouse_position_pause_2(tags *game)
{
    if (sfFloatRect_contains(&game->f_rects->menu_button_b,
    all_infos()->mouse_position.x, all_infos()->mouse_position.y)) {
        game->text->trestart = create_texture
        ("pictures/menu_buttons/Menu2.png");
        sfSprite_setTexture(game->sprites->srestart,
        game->text->trestart, sfTrue);
    } else {
        game->text->trestart =
        create_texture("pictures/menu_buttons/Menu.png");
        sfSprite_setTexture(game->sprites->srestart,
        game->text->trestart, sfTrue);
    }
}

void mouse_position_pause(tags *game)
{
    all_infos()->mouse_position =
    sfMouse_getPositionRenderWindow(all_infos()->window);
    if (sfFloatRect_contains(&game->f_rects->quit_button_b,
    all_infos()->mouse_position.x, all_infos()->mouse_position.y)) {
        game->text->tquit = create_texture("pictures/menu_buttons/Quit2.png");
        sfSprite_setTexture(game->sprites->squit, game->text->tquit, sfTrue);
    } else {
        game->text->tquit = create_texture("pictures/menu_buttons/Quit.png");
        sfSprite_setTexture(game->sprites->squit, game->text->tquit, sfTrue);
    }
    mouse_position_pause_2(game);
}

void manage_mouse_click_pause_game_2(tags *game)
{
    if (sfFloatRect_contains(&game->f_rects->quit_button_b,
    all_infos()->mouse_click.x, all_infos()->mouse_click.y)) {
        game->text->tquit = create_texture("pictures/menu_buttons/Quit3.png");
        sfSprite_setTexture(game->sprites->squit, game->text->tquit, sfTrue);
        write_infos_to_file();
        all_infos()->in->quit_main = 1;
    }
}

void set_menu(tags *game)
{
    write_infos_to_file();
    full_perso(HUNTER, 10 * 50, 10 * 35);
    reinitialize1();
    initialize_sprite_menu(game);
    initialize_bounds_menu(game);
    inicialize_variables_option(game);
    inicialize_sprite_option(game);
    initialize_options_game(game);
    all_infos()->in->level = 0;
}

void manage_mouse_click_pause_game(tags *game)
{
    all_infos()->mouse_click =
    sfMouse_getPositionRenderWindow(all_infos()->window);
    if (sfFloatRect_contains(&game->f_rects->menu_button_b,
    all_infos()->mouse_click.x, all_infos()->mouse_click.y)) {
        game->text->trestart =
        create_texture("pictures/menu_buttons/Menu3.png");
        sfSprite_setTexture(game->sprites->srestart,
        game->text->trestart, sfTrue);
        set_menu(game);
    }
    if (sfFloatRect_contains(&game->f_rects->start_button_b,
    all_infos()->mouse_click.x, all_infos()->mouse_click.y)) {
        game->text->tstart =
        create_texture("pictures/menu_buttons/Resume3.png");
        sfSprite_setTexture(game->sprites->sstart, game->text->tstart, sfTrue);
        all_infos()->in->level = GAME;
    }
    manage_mouse_click_pause_game_2(game);
    render_pause(game);
}
