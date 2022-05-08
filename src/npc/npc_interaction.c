/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** rpg_npc_interaction
*/

#include "my.h"
#include "rpg_header.h"

void npc_check_quest_2(npcs *expl, char *text)
{
    if (expl->value == 14 && expl->interaction == 1) {
        if (check_if_mission_was_done('2') == true) {
            print_quest("Thanks for your help!\n");
            return;
        }
        if (all_infos()->bo->doing_quest == false ||
        all_infos()->in->quest_id == expl->value) {
            all_infos()->in->quest_id = expl->value;
            all_infos()->bo->doing_quest = true;
            text = my_strcpy(text, "My son went to the dungeon!!!\n ");
            text = my_strcat(text, "I need someone to save him and\nI do not");
            text = my_strcat(text, " know what to do!\nCould you help me?\n");
            print_quest(text);
        } else {
            print_quest("You are already in a quest...\nCome back later!\n");
        }
    }
    npc_check_quest_3(expl, text);
}

void npc_check_quest(npcs *expl, char *text)
{
    if (expl->value == 10 && expl->interaction == 1) {
        if (check_if_mission_was_done('1') == true) {
            print_quest("Thanks for your help!\n");
            return;
        }
        if (all_infos()->bo->doing_quest == false ||
        all_infos()->in->quest_id == expl->value) {
            all_infos()->in->quest_id = expl->value;
            all_infos()->bo->doing_quest = true;
            text = my_strcpy(text, "Hello hero,\nI'm glad you are here! The ");
            text = my_strcat(text, "demons and ninjas\nare attacking our ");
            text = my_strcat(text, "village.. \nPlease kill them!");
            print_quest(text);
        } else {
            print_quest("You are already in a quest...\nCome back later!\n");
        }
    }
    npc_check_quest_2(expl, text);
}

void npc_quest(void)
{
    npcs *expl = all_maps()[all_infos()->in->map_actual].all_npcs;
    char *text = malloc(sizeof(char) * 200);
    all_infos()->in->entering_password = 0;
    while (expl) {
        npc_check_quest(expl, text);
        expl = expl->next;
    }
}

void disp_interaction_button(void)
{
    npcs *expl = all_maps()[all_infos()->in->map_actual].all_npcs;
    for (; expl; expl = expl->next) {
        sfFloatRect rect_player =
        sfSprite_getGlobalBounds(all_sprites()[HUNTER].sprite);
        sfFloatRect rect_npc =
        sfSprite_getGlobalBounds(all_sprites()[expl->value].sprite);
        rect_npc.height = 60, rect_npc.width = 60;
        expl->interaction = 0;
        if (sfFloatRect_intersects(&rect_player, &rect_npc, NULL)) {
            expl->interaction = 1;
            sfSprite_setScale(all_sprites()[INTERACTION_BT].sprite,
            (sfVector2f) {2, 2});
            sfSprite_setPosition(all_sprites()[INTERACTION_BT].sprite,
            (sfVector2f) {expl->pos.x - 13, expl->pos.y - 85});
            sfRenderWindow_drawSprite(all_infos()->window,
            all_sprites()[INTERACTION_BT].sprite, NULL);
            return;
        }
    }
}

void level_quest(void)
{
    event_level_quest();
    if (all_infos()->in->quit_main == 1) {
        close_sounds();
        write_infos_to_file();
        return;
    }
    disp_map(all_maps()[all_infos()->in->map_actual].bg);
    print_all_particules();
    disp_mg();
    disp_map(all_maps()[all_infos()->in->map_actual].fg);
    disp_all_npcs();
    disp_interaction_button();
    sfRenderWindow_setView(all_infos()->window, all_infos()->hud_view);
    display_hud();
    sfRenderWindow_drawSprite(all_infos()->window,
    all_sprites()[BALLON].sprite, NULL);
    npc_quest();
    sfRenderWindow_setView(all_infos()->window, all_infos()->view);
    return;
}
