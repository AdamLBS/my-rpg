/*
** EPITECH PROJECT, 2022
** B-MUL-200-MAR-2-1-myrpg-niels.ouvrard
** File description:
** menu_utils3
*/

#include "my.h"
#include "rpg_header.h"

void mouse_position_menu2(tags *game)
{
    if (sfFloatRect_contains(&game->f_rects->option_button_b,
        all_infos()->mouse_position.x, all_infos()->mouse_position.y)) {
        game->text->toption =
        create_texture("pictures/menu_buttons/Options2.png");
        sfSprite_setTexture(game->sprites->soption,
        game->text->toption, sfTrue);
    } else {
        game->text->toption =
        create_texture("pictures/menu_buttons/Options.png");
        sfSprite_setTexture(game->sprites->soption,
        game->text->toption, sfTrue);
    }
}

void mouse_position_pause2(tags *game)
{
    if (sfFloatRect_contains(&game->f_rects->start_button_b,
        all_infos()->mouse_position.x, all_infos()->mouse_position.y)) {
        game->text->tstart = create_texture
        ("pictures/menu_buttons/Resume2.png");
        sfSprite_setTexture(game->sprites->sstart, game->text->tstart, sfTrue);
    } else {
        game->text->tstart =
        create_texture("pictures/menu_buttons/Resume.png");
        sfSprite_setTexture(game->sprites->sstart, game->text->tstart, sfTrue);
    }
}
