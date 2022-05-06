/*
** EPITECH PROJECT, 2021
** game_over.c
** File description:
** game_over
*/

#include "my.h"
#include "rpg_header.h"

void render_option(tags *game)
{
    sfRenderWindow_clear(all_infos()->window, sfBlack);
    sfRenderWindow_drawSprite(all_infos()->window, game->sprites->sbackground, NULL);
    sfRenderWindow_drawSprite(all_infos()->window, game->sprites->sframe, NULL);
    sfRenderWindow_drawSprite(all_infos()->window, game->sprites->sframe2, NULL);
    sfRenderWindow_drawSprite(all_infos()->window, game->sprites->srestart, NULL);
    sfRenderWindow_drawText(all_infos()->window, all_texts()->simple_text, NULL);
    sfRenderWindow_display(all_infos()->window);
}

void inicialize_variables_option(tags *game)
{
    all_texts()->simple_text = sfText_create();
    all_texts()->font = sfFont_createFromFile("font/AncientModernTales-a7Po.ttf");
    sfText_setString(all_texts()->simple_text, "Frame Rate:");
    sfText_setFont(all_texts()->simple_text, all_texts()->font);
    sfText_setCharacterSize(all_texts()->simple_text, 90);
    sfText_setPosition(all_texts()->simple_text, (sfVector2f) {180, 380});
}

void inicialize_sprite_option(tags *game)
{
    game->text->tframe = create_texture("pictures/menu_buttons/30_3.png");
    game->sprites->sframe = sfSprite_create();
    game->text->tframe2 = create_texture("pictures/menu_buttons/60.png");
    game->sprites->sframe2 = sfSprite_create();
    game->text->trestart = create_texture("pictures/menu_buttons/Menu.png");
    game->sprites->srestart = sfSprite_create();
    sfSprite_setTexture(game->sprites->sframe, game->text->tframe, sfTrue);
    sfSprite_setScale(game->sprites->sframe, (sfVector2f) {1.3, 1.3});
    sfSprite_setPosition(game->sprites->sframe, (sfVector2f) {730, 380});
    sfSprite_setTexture(game->sprites->sframe2, game->text->tframe2, sfTrue);
    sfSprite_setScale(game->sprites->sframe2, (sfVector2f) {1.3, 1.3});
    sfSprite_setPosition(game->sprites->sframe2, (sfVector2f) {1150, 380});
    sfSprite_setTexture(game->sprites->srestart, game->text->trestart, sfTrue);
    sfSprite_setScale(game->sprites->srestart, (sfVector2f) {1.3, 1.3});
    sfSprite_setPosition(game->sprites->srestart, (sfVector2f) {750, 700});
}

void initialize_options_game(tags *game)
{
    char *score;
    game->f_rects->frame30_button_b =
    sfSprite_getGlobalBounds(game->sprites->sframe);
    game->f_rects->frame30_button_b.width = 420;
    game->f_rects->frame60_button_b =
    sfSprite_getGlobalBounds(game->sprites->sframe2);
    game->f_rects->frame60_button_b.width = 420;
    game->f_rects->menu_button_b =
    sfSprite_getGlobalBounds(game->sprites->srestart);
    game->f_rects->menu_button_b.width = 420;
}

void level_option(tags *game)
{
    mouse_position_option(game);
    analyse_events_option(game);
    sfRenderWindow_setView(all_infos()->window, all_infos()->hud_view);
    render_option(game);
}