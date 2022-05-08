/*
** EPITECH PROJECT, 2021
** game_over.c
** File description:
** game_over
*/

#include "my.h"
#include "rpg_header.h"

void manage_mouse_click_end_game(tags *game)
{
    all_infos()->mouse_click =
    sfMouse_getPositionRenderWindow(all_infos()->window);
    if (sfFloatRect_contains(&game->f_rects->menu_button_b,
    all_infos()->mouse_click.x, all_infos()->mouse_click.y)) {
        game->text->trestart = sfTexture_createFromFile
        ("pictures/menu_buttons/Menu3.png", NULL);
        sfSprite_setTexture(game->sprites->srestart,
        game->text->trestart, sfTrue);
        all_infos()->in->level = 0;
        set_menu(game);
    }
    if (sfFloatRect_contains(&game->f_rects->quit_button_b,
    all_infos()->mouse_click.x, all_infos()->mouse_click.y)) {
        game->text->tquit = sfTexture_createFromFile
        ("pictures/menu_buttons/Quit3.png", NULL);
        sfSprite_setTexture(game->sprites->squit,
        game->text->tquit, sfTrue);
        write_infos_to_file();
        all_infos()->in->quit_main = 1;
    }
}

void mouse_position_end_game(tags *game)
{
    all_infos()->mouse_position =
    sfMouse_getPositionRenderWindow(all_infos()->window);
    if (sfFloatRect_contains(&game->f_rects->menu_button_b,
    all_infos()->mouse_position.x, all_infos()->mouse_position.y)) {
        game->text->trestart =
        create_texture("pictures/menu_buttons/Menu2.png");
        sfSprite_setTexture(game->sprites->srestart,
        game->text->trestart, sfTrue);
    } else {
        game->text->trestart =
        create_texture("pictures/menu_buttons/Menu.png");
        sfSprite_setTexture(game->sprites->srestart,
        game->text->trestart, sfTrue);
    }
    utils_gameover(game);
}

void render_end_game(tags *game)
{
    sfRenderWindow_clear(all_infos()->window, sfBlack);
    sfRenderWindow_drawSprite(all_infos()->window,
    game->sprites->sbackground, NULL);
    sfRenderWindow_drawSprite(all_infos()->window,
    game->sprites->srestart, NULL);
    sfRenderWindow_drawSprite(all_infos()->window,
    game->sprites->squit, NULL);
    sfRenderWindow_drawText(all_infos()->window,
    all_texts()->simple_text, NULL);
    sfRenderWindow_display(all_infos()->window);
}

void inicialize_sprite_end_game(tags *game)
{
    game->text->tbackground =
    create_texture("pictures/Background.jpg");
    game->text->trestart = create_texture("pictures/menu_buttons/Menu.png");
    game->sprites->srestart = sfSprite_create();
    game->text->tquit = create_texture("pictures/menu_buttons/Quit.png");
    game->sprites->squit = sfSprite_create();
    sfSprite_setTexture(game->sprites->sbackground,
    game->text->tbackground, sfTrue);
    sfSprite_setTexture(game->sprites->srestart, game->text->trestart, sfTrue);
    sfSprite_setScale(game->sprites->srestart, (sfVector2f) {1.3, 1.3});
    sfSprite_setPosition(game->sprites->srestart, (sfVector2f) {740, 300});
    sfSprite_setTexture(game->sprites->squit, game->text->tquit, sfTrue);
    sfSprite_setScale(game->sprites->squit, (sfVector2f) {1.3, 1.3});
    sfSprite_setPosition(game->sprites->squit, (sfVector2f) {740, 460});
    sfText_setString(all_texts()->simple_text, "YOU ARE DEAD!");
    sfText_setPosition(all_texts()->simple_text, (sfVector2f) {670, 120});
}

void level_end(tags *game)
{
    inicialize_sprite_end_game(game);
    initialize_bounds_end_game(game);
    analyse_events_end_game(game);
    mouse_position_end_game(game);
    sfRenderWindow_setView(all_infos()->window, all_infos()->hud_view);
    render_end_game(game);
}
