/*
** EPITECH PROJECT, 2022
** B-MUL-200-MAR-2-1-myrpg-niels.ouvrard
** File description:
** story
*/

#include "my.h"
#include "rpg_header.h"

void story(void)
{
    event_level_story();
    if (all_infos()->in->quit_main == 1) {
        close_sounds();
        return;
    }
    sfRenderWindow_setView(all_infos()->window, all_infos()->hud_view);
    sfRenderWindow_setView(all_infos()->window, all_infos()->view);
    print_story(START_TEXT);
}

void print_story(char *text)
{
    int j = all_infos()->in->text_char;
    sfTime time = sfClock_getElapsedTime(all_infos()->text_clock);
    if (sfTime_asMilliseconds(time) > 50) {
        if (j + 1 < my_strlen(text))
        all_infos()->in->text_char += 1;
        sfClock_restart(all_infos()->text_clock);
    }
    char *tmp = my_strdup_to(text, j);
    sfText_setCharacterSize(all_texts()->simple_text, 20);
    sfText_setString(all_texts()->simple_text, tmp);
    sfRenderWindow_drawText(all_infos()->window,
    all_texts()->simple_text, NULL);
}

void event_level_story(void)
{
    sfEvent event;
    while (sfRenderWindow_pollEvent(all_infos()->window, &event)) {
        if (event.type == sfEvtClosed) {
            all_infos()->in->quit_main = 1;
            return;
        }
        if (event.type == sfEvtKeyPressed &&
            event.key.code == all_keys()->k_interact) {
                all_infos()->in->text_char = 0;
                all_infos()->in->level = GAME;
        }
    }
    return;
}
