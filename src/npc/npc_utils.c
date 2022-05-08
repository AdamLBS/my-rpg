/*
** EPITECH PROJECT, 2022
** B-MUL-200-MAR-2-1-myrpg-niels.ouvrard
** File description:
** npc_utils
*/

#include "my.h"
#include "rpg_header.h"

bool check_if_mission_was_done(char find)
{
    for (int i = 0; all_infos()->quest_done[i] != '\0'; i++) {
        if (all_infos()->quest_done[i] == find) {
            return true;
        }
    }
    return false;
}

void check_for_easter_egg(sfEvent event)
{
    npcs *expl = all_maps()[all_infos()->in->map_actual].all_npcs;
    while (expl) {
        if (event.type == sfEvtKeyPressed &&
        event.key.code == all_keys()->k_yes &&
        all_infos()->in->entering_password == 1) {
            all_infos()->in->text_char = 0;
            all_infos()->in->level = BONUS;
        }
        if (event.type == sfEvtKeyPressed && event.key.code ==
        all_keys()->k_no && all_infos()->in->entering_password == 1) {
            all_infos()->in->text_char = 0;
            all_infos()->in->level = GAME;
        }
        expl = expl->next;
    }
}

void event_level_quest(void)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(all_infos()->window, &event)) {
        if (event.type == sfEvtKeyPressed &&
        event.key.code == all_keys()->k_interact) {
            all_infos()->in->text_char = 0;
            all_infos()->in->level = GAME;
        }
        if (event.type == sfEvtClosed) {
            all_infos()->in->quit_main = 1;
            return;
        }
        check_for_easter_egg(event);
    }
    return;
}

void print_quest(char *text)
{
    int j = all_infos()->in->text_char;
    sfTime time = sfClock_getElapsedTime(all_infos()->text_clock);
    if (sfTime_asMilliseconds(time) > 0.6) {
        if (j + 1 < my_strlen(text))
            all_infos()->in->text_char += 1;
        sfClock_restart(all_infos()->text_clock);
    }
    char *tmp = my_strdup_to(text, j);
    sfText_setCharacterSize(all_texts()->simple_text, 50);
    sfText_setString(all_texts()->simple_text, tmp);
    sfText_setPosition(all_texts()->simple_text, (sfVector2f) {610, 777});
    sfRenderWindow_drawText(all_infos()->window,
    all_texts()->simple_text, NULL);
}

void npc_check_quest_3(npcs *expl)
{
    if (expl->value == 17 && expl->interaction == 1) {
        if (all_infos()->bo->doing_quest == true &&
        all_infos()->in->quest_id == 14) {
            all_infos()->bo->doing_quest = false;
            all_infos()->in->quest_id = 0;
            increase(15, 15);
            all_infos()->quest_done[my_strlen(all_infos()->quest_done)] = '2';
        }
        print_quest("Finally someone came!\nThanks for saving me!\n");
    }
    if (expl->value == 10 && expl->interaction == 1) {
        if (all_infos()->in->nb_of_enemies_outside == 0) {
            all_infos()->bo->doing_quest = false;
            all_infos()->in->quest_id = 0;
            increase(15, 15);
            all_infos()->quest_done[my_strlen(all_infos()->quest_done)] = '1';
        }
    }
}
