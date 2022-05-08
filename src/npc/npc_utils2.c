/*
** EPITECH PROJECT, 2022
** B-MUL-200-MAR-2-1-myrpg-niels.ouvrard
** File description:
** npc_utils2
*/

#include "my.h"
#include "rpg_header.h"

void npc_check_quest_4(npcs *expl, char *text)
{
    if (expl->value == 12 && expl->interaction == 1) {
        if (check_if_mission_was_done('3') == true) {
            print_quest("Password already done!\n");
            return;
        }
        text = my_strcpy(text, "Do you have the password?\nPress");
        text = my_strcat(text, " Y for 'yes' and N for 'no'\n");
        print_quest(text);
        all_infos()->in->entering_password = 1;
    }
}
