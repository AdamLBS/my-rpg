/*
** EPITECH PROJECT, 2021
** my_hunter
** File description:
** pause
*/

#include "my.h"
#include "rpg_header.h"

void render_pause(tags *game)
{
    sfRenderWindow_drawSprite(all_infos()->window,
    game->sprites->squit, NULL);
    sfRenderWindow_drawSprite(all_infos()->window,
    game->sprites->sstart, NULL);
    sfRenderWindow_drawSprite(all_infos()->window,
    game->sprites->srestart, NULL);
}

void pause_event(tags *game)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(all_infos()->window, &event)) {
        if ((event.type == sfEvtKeyPressed) &&
        (event.key.code == sfKeyEscape))
            all_infos()->level = GAME;
        if (event.type == sfEvtClosed)
            all_infos()->quit_main = 1;
        if (event.type == sfEvtMouseButtonReleased)
            manage_mouse_click_pause_game(game);
    }
}

void set_sprite_pause(tags *game)
{
    game->text->tstart =
    sfTexture_createFromFile("pictures/menu_buttons/Resume.png", NULL);
    sfSprite_setTexture(game->sprites->sstart, game->text->tstart, sfTrue);
    sfSprite_setScale(game->sprites->sstart, (sfVector2f) {1.3, 1.3});
    sfSprite_setPosition(game->sprites->sstart, (sfVector2f) {780, 440});
    sfSprite_setTexture(game->sprites->squit, game->text->tquit, sfTrue);
    sfSprite_setScale(game->sprites->squit, (sfVector2f) {1.3, 1.3});
    sfSprite_setPosition(game->sprites->squit, (sfVector2f) {780, 760});
    sfSprite_setTexture(game->sprites->srestart, game->text->trestart, sfTrue);
    sfSprite_setScale(game->sprites->srestart, (sfVector2f) {1.3, 1.3});
    sfSprite_setPosition(game->sprites->srestart, (sfVector2f) {780, 600});
    game->f_rects->menu_button_b =
    sfSprite_getGlobalBounds(game->sprites->srestart);
    game->f_rects->quit_button_b =
    sfSprite_getGlobalBounds(game->sprites->squit);
    game->f_rects->start_button_b =
    sfSprite_getGlobalBounds(game->sprites->sstart);
}

void level_pause(tags *game)
{
    set_sprite_pause(game);
    pause_event(game);
    disp_map(all_maps()[all_infos()->map_actual].bg);
    print_all_particules();
    disp_mg();
    disp_map(all_maps()[all_infos()->map_actual].fg);
    disp_all_npcs();
    disp_interaction_button();
    mouse_position_pause(game);
    sfRenderWindow_setView(all_infos()->window, all_infos()->hud_view);
    render_pause(game);
    display_hud();
    sfRenderWindow_setView(all_infos()->window, all_infos()->view);
}
