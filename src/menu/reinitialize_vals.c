/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** reinitialize_vals
*/

#include "my.h"
#include "rpg_header.h"

void reinitialize2(void)
{
    all_infos()->move_u = false;
    all_infos()->move_d = false;
    all_infos()->move_l = false;
    all_infos()->move_r = false;
    all_infos()->life_size = 150;
    all_infos()->doing_quest = false;
    all_infos()->clock = sfClock_create();
    all_infos()->clock_val = 0;
    all_infos()->particules = NULL;
    all_infos()->view_position.x = 960;
    all_infos()->inventory_move = 0;
    all_infos()->view_position.y = 540;
    all_infos()->view = sfView_create();
    all_infos()->hud_view = sfView_create();
    all_infos()->quest_id = 0;
    all_infos()->nb_of_enemies_outside = 0;
    sfView_setCenter(all_infos()->hud_view, (sfVector2f) {1920 / 2, 1080 / 2});
    sfView_setSize(all_infos()->hud_view, (sfVector2f) {1920, 1080});
    sfRenderWindow_setView(all_infos()->window, all_infos()->hud_view);
    all_infos()->last_move = 'd';
    sfView_setCenter(all_infos()->view, (sfVector2f) {10 * 50, (10 * 35) - 16});
    sfView_setSize(all_infos()->view, (sfVector2f) {1920 / 2, 1080 / 2});
    sfRenderWindow_setView(all_infos()->window, all_infos()->view);
}

void reinitialize1(void)
{
    all_infos()->level = 0;
    all_infos()->ennemy_id = 0;
    all_infos()->quit_main = 0;
    all_infos()->map_actual = 0;
    all_infos()->pos_player.x = 500;
    all_infos()->pos_player.y = 350;
    all_infos()->first_run = false;
    all_infos()->save = false;
    all_infos()->nb_of_zoom = 1;
    all_infos()->zoom = 1;
    all_infos()->move = '\0';
    all_infos()->life = 10;
    all_infos()->stamina = 10;
    all_infos()->opened_chest = false;
    all_infos()->quest_done[0] = '\0';
    all_infos()->quest_done[1] = '\0';
    all_infos()->quest_done[2] = '\0';
    all_infos()->banana_nb = 0;
    all_infos()->apple_nb = 0;
    struct_inventory *val = NULL;
    all_infos()->inventory = val;
    all_infos()->stamina_clock = sfClock_create();
    all_infos()->text_clock = sfClock_create();
    all_infos()->text_char = 0;
    reinitialize2();
    return;
}