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

void le_bon_click_editor_pos_map (sfEvent event, sfVector2i pos_mouse)
{
    if (pos_mouse.x <= 300 && pos_mouse.y < 300) {
        all_editor()->value_to_print = '0';
        all_editor()->value_to_print += (pos_mouse.y / 50) * 6;
        all_editor()->value_to_print += (pos_mouse.x / 50);
        return;
    } else if (pos_mouse.x >= 1920 - 150 && pos_mouse.y <= 260) {
        editor_click_infos_right(pos_mouse);
        change_size_map();
        return;
    }
}

void le_bon_click_editor (sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed)
        if (event.mouseButton.button == sfMouseLeft)
            all_editor()->is_writing = true;
    if (event.type == sfEvtMouseButtonReleased)
        if (event.mouseButton.button == sfMouseLeft)
            all_editor()->is_writing = false;
    if (!all_editor()->is_writing)
        return;
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(all_infos()->window);
    le_bon_click_editor_pos_map(event, pos_mouse);
    int y = (pos_mouse.y / 50) - round_sup(all_infos()->pos_player.y / 50);
    int x = (pos_mouse.x / 50) - round_sup(all_infos()->pos_player.x / 50);
    if (all_editor()->ptr_map_edit && x >= 0 && y >= 0 &&
    y < my_arraylen(all_editor()->ptr_map_edit) &&
    x < my_strlen(all_editor()->ptr_map_edit[0])) {
        all_editor()->ptr_map_edit[y][x] = all_editor()->value_to_print;
        return;
    }
}
