/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** check_win_lose_game
*/

#include "my.h"
#include "rpg_header.h"

void check_win_lose(void)
{
    int q1 = 0, q2 = 0;
    for (int i = 0; all_infos()->quest_done[i] != '\0'; i++) {
        if (all_infos()->quest_done[i] == '1')
            q1 = 1;
        if (all_infos()->quest_done[i] == '2')
            q2 = 1;
    }
    if (q1 == 1 && q2 == 1) {
        all_infos()->level = END;
        all_texts()->text = my_strdup("YOU WON!");
    }
    if (all_infos()->life <= 0) {
        all_texts()->text = my_strdup("YOU ARE DEAD!");
        all_infos()->level = END;
    }
}
