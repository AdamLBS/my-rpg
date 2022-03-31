/*
** EPITECH PROJECT, 2022
** snake_no_map.c
** File description:
** snake level 0
*/

#include "my.h"
#include "rpg_header.h"

void modify_var_move_editor(sfEvent event)
{
    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeyUp)
            all_infos()->move = 'u';
        if (event.key.code == sfKeyLeft)
            all_infos()->move = 'l';
        if (event.key.code == sfKeyDown)
            all_infos()->move = 'd';
        if (event.key.code == sfKeyRight)
            all_infos()->move = 'r';
    }
    if (event.type == sfEvtKeyReleased && !sfKeyboard_isKeyPressed(sfKeyLeft)
    && !sfKeyboard_isKeyPressed(sfKeyRight) && !sfKeyboard_isKeyPressed(sfKeyUp)
    && !sfKeyboard_isKeyPressed(sfKeyDown))
        all_infos()->move = '\0';
}

void level_map_editor_event(sfEvent event)
{
    while (sfRenderWindow_pollEvent(all_infos()->window, &event)) {
        if (event.type == sfEvtClosed) {
            all_infos()->quit_main = 1;
            return;
        }
        if (sfKeyboard_isKeyPressed(sfKeyP) && all_editor()->map_editor) {
            my_show_word_array(all_editor()->map_editor);
            free_my_arr(all_editor()->map_editor);
            all_editor()->map_editor = NULL;
        }
        la_bonne_touche_editor(event);
        le_bon_click_editor(event);
        if (all_editor()->map_editor)
            modify_var_move_editor(event);
        else
            change_map_size(event);
    }
}
// pb avec dernier char des str du char **

// 0 fichier = default
// si param, modif map existante

void disp_tile_sprite_seet_e(int i, int j, int top, int left)
{
    int type = SPRITE_SHEET;
    all_sprites()[type].rect.top = top;
    all_sprites()[type].rect.left = left;
    sfSprite_setTextureRect(all_sprites()[type].sprite, all_sprites()[type].rect);

    all_sprites()[type].pos.x = all_infos()->pos_player.x + (all_sprites()[type].scale.x * 16) * all_infos()->zoom * j;
    all_sprites()[type].pos.y = all_infos()->pos_player.y + (all_sprites()[type].scale.x * 16) * all_infos()->zoom * i;
    sfSprite_setPosition(all_sprites()[type].sprite, all_sprites()[type].pos);
    sfRenderWindow_drawSprite(all_infos()->window,
    all_sprites()[type].sprite, NULL);
}

void disp_map_editor_next(char **map, int i, int j)
{
    if (!(map[i][j] >= '0' && map[i][j] <= '0' + 35))
        return;
    int x = map[i][j] - '0';
    x *= 16;
    int y = 0;
    while (x >= 96) {
        y += 16;
        x -= 96;
    }
    disp_tile_sprite_seet_e(i, j, y, x);
}

void disp_map_editor(void)
{
    for (int i = 0; all_editor()->map_editor[i]; i++)
        for (int j = 0; all_editor()->map_editor[i][j]; j++)
            disp_map_editor_next(all_editor()->map_editor, i, j);
}

void disp_value_to_print(void)
{
    // sfSprite_setScale(all_sprites()[SPRITE_SHEET].sprite, (sfVector2f){2, 2});
    sfSprite_setTextureRect(all_sprites()[SPRITE_SHEET].sprite, (sfIntRect){0, 0, 96, 96});
    sfSprite_setPosition(all_sprites()[SPRITE_SHEET].sprite, (sfVector2f){0, 0});
    sfRenderWindow_drawSprite(all_infos()->window,
    all_sprites()[SPRITE_SHEET].sprite, NULL);
}

void level_map_editor_clock(sfEvent event)
{
    if (all_infos()->move && !(all_infos()->clock_val % 2)) {
        move_pos_player();
    }
}

void disp_boxes (void)
{
    int sprite = EMPTY_BOX;
    sprite = all_editor()->edit_ground == 'f' ? CHECK_BOX : EMPTY_BOX;
    sfSprite_setPosition(all_sprites()[sprite].sprite, (sfVector2f){1920 - 80, 65});
    sfRenderWindow_drawSprite(all_infos()->window, all_sprites()[sprite].sprite, NULL);

    sprite = all_editor()->edit_ground == 'm' ? CHECK_BOX : EMPTY_BOX;
    sfSprite_setPosition(all_sprites()[sprite].sprite, (sfVector2f){1920 - 80, 115});
    sfRenderWindow_drawSprite(all_infos()->window, all_sprites()[sprite].sprite, NULL);

    sprite = all_editor()->edit_ground == 'b' ? CHECK_BOX : EMPTY_BOX;
    sfSprite_setPosition(all_sprites()[sprite].sprite, (sfVector2f){1920 - 80, 165});
    sfRenderWindow_drawSprite(all_infos()->window, all_sprites()[sprite].sprite, NULL);

    sprite = all_editor()->v_fg ? CHECK_BOX : EMPTY_BOX;
    sfSprite_setPosition(all_sprites()[sprite].sprite, (sfVector2f){1920 - 30, 65});
    sfRenderWindow_drawSprite(all_infos()->window, all_sprites()[sprite].sprite, NULL);

    sprite = all_editor()->v_mg ? CHECK_BOX : EMPTY_BOX;
    sfSprite_setPosition(all_sprites()[sprite].sprite, (sfVector2f){1920 - 30, 115});
    sfRenderWindow_drawSprite(all_infos()->window, all_sprites()[sprite].sprite, NULL);

    sprite = all_editor()->v_bg ? CHECK_BOX : EMPTY_BOX;
    sfSprite_setPosition(all_sprites()[sprite].sprite, (sfVector2f){1920 - 30, 165});
    sfRenderWindow_drawSprite(all_infos()->window, all_sprites()[sprite].sprite, NULL);
}

void disp_text_and_boxes (void)
{
    sfText_setCharacterSize(all_editor()->editor_text, 20);

    sfText_setString(all_editor()->editor_text, "Edit");
    sfText_setPosition(all_editor()->editor_text, (sfVector2f){1920 - 100, 20});
    sfRenderWindow_drawText(all_infos()->window, all_editor()->editor_text, NULL);

    sfText_setString(all_editor()->editor_text, "View");
    sfText_setPosition(all_editor()->editor_text, (sfVector2f){1920 - 50, 20});
    sfRenderWindow_drawText(all_infos()->window, all_editor()->editor_text, NULL);

    sfText_setString(all_editor()->editor_text, "FG");
    sfText_setPosition(all_editor()->editor_text, (sfVector2f){1920 - 150, 50});
    sfRenderWindow_drawText(all_infos()->window, all_editor()->editor_text, NULL);

    sfText_setString(all_editor()->editor_text, "MG");
    sfText_setPosition(all_editor()->editor_text, (sfVector2f){1920 - 150, 100});
    sfRenderWindow_drawText(all_infos()->window, all_editor()->editor_text, NULL);

    sfText_setString(all_editor()->editor_text, "BG");
    sfText_setPosition(all_editor()->editor_text, (sfVector2f){1920 - 150, 150});
    sfRenderWindow_drawText(all_infos()->window, all_editor()->editor_text, NULL);

    disp_boxes();

    sfText_setCharacterSize(all_editor()->editor_text, 40);

    sfText_setString(all_editor()->editor_text, "-           +");
    sfText_setPosition(all_editor()->editor_text, (sfVector2f){1920 - 150, 180});
    sfRenderWindow_drawText(all_infos()->window, all_editor()->editor_text, NULL);

    char *size_x = my_int_to_str(all_editor()->size_edit.x);
    sfText_setString(all_editor()->editor_text, size_x);
    sfText_setPosition(all_editor()->editor_text, (sfVector2f){1920 - 120, 180});
    sfRenderWindow_drawText(all_infos()->window, all_editor()->editor_text, NULL);
    free(size_x);

    sfText_setString(all_editor()->editor_text, "-           +");
    sfText_setPosition(all_editor()->editor_text, (sfVector2f){1920 - 150, 230});
    sfRenderWindow_drawText(all_infos()->window, all_editor()->editor_text, NULL);

    char *size_y = my_int_to_str(all_editor()->size_edit.y);
    sfText_setString(all_editor()->editor_text, size_y);
    sfText_setPosition(all_editor()->editor_text, (sfVector2f){1920 - 120, 230});
    sfRenderWindow_drawText(all_infos()->window, all_editor()->editor_text, NULL);
    free(size_y);
}

void level_map_editor(sfEvent event)
{
    level_map_editor_event(event);
    if (all_editor()->map_editor)
        disp_map_editor();
    disp_value_to_print();
    disp_text_and_boxes();
}