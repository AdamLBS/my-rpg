/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** option_utils2
*/

#include "my.h"
#include "rpg_header.h"

void manage_mouse_click_util_2(tags *game)
{
    all_infos()->mouse_click =
    sfMouse_getPositionRenderWindow(all_infos()->window);
    if (sfFloatRect_contains(&game->f_rects->sound_button_b,
    all_infos()->mouse_click.x, all_infos()->mouse_click.y)) {
        if (game->f_rects->sound == 0) {
            game->text->tsound =
            create_texture("pictures/menu_buttons/sound2.png");
            sfSprite_setTexture(game->sprites->ssound,
            game->text->tsound, sfTrue);
            sfSound_setVolume(all_infos()->sounds->grass, 0.0);
            sfSound_setVolume(all_infos()->sounds->open_chest, 0.0);
            sfSound_setVolume(all_infos()->sounds->stone, 0.0);
            sfSound_setVolume(all_infos()->sounds->wood, 0.0);
            game->f_rects->sound = 1;
        } else {
            manage_mouse_click_util_3(game);
        }
    }
}

void inicialize_sprite_option_2(tags *game)
{
    game->text->tsound = create_texture("pictures/menu_buttons/sound.png");
    game->sprites->ssound = sfSprite_create();
    sfSprite_setTexture(game->sprites->ssound, game->text->tsound, sfTrue);
    sfSprite_setScale(game->sprites->ssound, (sfVector2f) {1.8, 1.8});
    sfSprite_setPosition(game->sprites->ssound, (sfVector2f) {730, 120});
    game->text->tkey = create_texture("pictures/menu_buttons/wasd.png");
    game->sprites->skey = sfSprite_create();
    game->text->tkey2 = create_texture("pictures/menu_buttons/zqsd.png");
    game->sprites->skey2 = sfSprite_create();
    sfSprite_setTexture(game->sprites->skey, game->text->tkey, sfTrue);
    sfSprite_setScale(game->sprites->skey, (sfVector2f) {1.8, 1.8});
    sfSprite_setPosition(game->sprites->skey, (sfVector2f) {730, 700});
    sfSprite_setTexture(game->sprites->skey2, game->text->tkey2, sfTrue);
    sfSprite_setScale(game->sprites->skey2, (sfVector2f) {1.8, 1.8});
    sfSprite_setPosition(game->sprites->skey2, (sfVector2f) {730, 120});
}

void manage_mouse_click_util_3(tags *game)
{
    if (game->f_rects->sound != 0) {
        game->text->tsound =
        create_texture("pictures/menu_buttons/sound.png");
        sfSprite_setTexture(game->sprites->ssound, game->text->tsound, sfTrue);
        sfSound_setVolume(all_infos()->sounds->grass, 10.0);
        sfSound_setVolume(all_infos()->sounds->open_chest, 10.0);
        sfSound_setVolume(all_infos()->sounds->stone, 10.0);
        sfSound_setVolume(all_infos()->sounds->wood, 10.0);
        game->f_rects->sound = 0;
    }
}
