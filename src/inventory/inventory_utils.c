/*
** EPITECH PROJECT, 2022
** B-MUL-200-MAR-2-1-myrpg-niels.ouvrard
** File description:
** inventory_utils
*/

#include "my.h"
#include "rpg_header.h"

void inventory_utils_event(sfEvent event)
{
    if (event.type == sfEvtKeyPressed &&
        event.key.code == all_keys()->k_inv_right)
            change_val_box(1);
    if (event.type == sfEvtKeyPressed &&
        event.key.code == all_keys()->k_inv_left)
            change_val_box(2);
    if (event.type == sfEvtClosed) {
        write_infos_to_file();
        all_infos()->quit_main = 1;
        return;
    }
}
