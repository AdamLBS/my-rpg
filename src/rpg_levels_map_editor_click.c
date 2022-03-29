/*
** EPITECH PROJECT, 2022
** snake_no_map.c
** File description:
** snake level 0
*/

#include "my.h"
#include "rpg_header.h"

int round_sup (float a)
{
    int b = (int)a;
    if ((float)b + 0.5 < a) {
        return ++b;
    }
    return b;
}

void change_tile_to_print(sfEvent event)
{
    if (event.key.code == sfKeyNum1)
        all_infos()->value_to_print = 'g';
    if (event.key.code == sfKeyNum2)
        all_infos()->value_to_print = 'd';
    if (event.key.code == sfKeyNum3)
        all_infos()->value_to_print = 'w';
    if (event.key.code == sfKeyNum4)
        all_infos()->value_to_print = 's';
}

void change_map_size(sfEvent event)
{
    if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeyUp)
            all_infos()->size_edit.y--;
        if (event.key.code == sfKeyLeft)
            all_infos()->size_edit.x--;
        if (event.key.code == sfKeyDown)
            all_infos()->size_edit.y++;
        if (event.key.code == sfKeyRight)
            all_infos()->size_edit.x++;
    }
}

void le_bon_click_editor (sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed) {
        if (event.mouseButton.button == sfMouseLeft)
            all_infos()->is_writing = true;
        if (event.mouseButton.button == sfMouseLeft)
            all_infos()->is_writing = false;
    }
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(
        all_infos()->window);
    if (all_infos()->is_writing) {
        int val_y = (pos_mouse.y / 50) -
        round_sup(all_infos()->pos_player.y / 50);
        int val_x = (pos_mouse.x / 50) -
        round_sup(all_infos()->pos_player.x / 50);
        if (all_infos()->map_editor && val_x >= 0 && val_y >= 0 &&
        val_y < my_arraylen(all_infos()->map_editor) && val_x <
        my_strlen(all_infos()->map_editor[0])) {
            all_infos()->map_editor[val_y][val_x] =
            all_infos()->value_to_print;
        }
    }
}

void la_bonne_touche_editor (sfEvent event)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape) {
        all_infos()->level = 0;
    }
    change_tile_to_print(event);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyN) {
        if (all_infos()->map_editor)
            free_my_arr(all_infos()->map_editor);
        all_infos()->map_editor = editor_create_map(
        all_infos()->size_edit.x, all_infos()->size_edit.y);
    }
}