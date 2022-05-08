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
    all_infos()->clock = sfClock_create();
    all_infos()->in->clock_val = 0;
    all_infos()->particules = NULL;
    all_infos()->view_position.x = 960;
    all_infos()->in->inventory_move = 0;
    all_infos()->view_position.y = 540;
    all_infos()->view = sfView_create();
    all_infos()->hud_view = sfView_create();
    all_infos()->in->quest_id = 0;
    all_infos()->in->nb_of_enemies_outside = 0;
    sfView_setCenter(all_infos()->hud_view, (sfVector2f) {1920 / 2, 1080 / 2});
    sfView_setSize(all_infos()->hud_view, (sfVector2f) {1920, 1080});
    sfRenderWindow_setView(all_infos()->window, all_infos()->hud_view);
    all_infos()->last_move = 'd';
    sfView_setCenter(all_infos()->view,
    (sfVector2f) {10 * 50, (10 * 35) - 16});
    sfView_setSize(all_infos()->view, (sfVector2f) {1920 / 2, 1080 / 2});
    sfRenderWindow_setView(all_infos()->window, all_infos()->view);
}

void reset_2(void)
{
    all_infos()->quest_done[0] = '\0';
    all_infos()->quest_done[1] = '\0';
    all_infos()->quest_done[2] = '\0';
    all_infos()->in->banana_nb = 0;
    all_infos()->bo->move_u = false;
    all_infos()->bo->move_d = false;
    all_infos()->bo->move_l = false;
    all_infos()->bo->move_r = false;
    all_infos()->in->life_size = 150;
    all_infos()->bo->doing_quest = false;
    all_infos()->in->apple_nb = 0;
    struct_inventory *val = NULL;
    all_infos()->inventory = val;
    all_infos()->stamina_clock = sfClock_create();
    all_infos()->text_clock = sfClock_create();
    all_infos()->in->text_char = 0;
}

void reinitialize1(void)
{
    all_infos()->in->level = 0;
    all_infos()->in->ennemy_id = 0;
    all_infos()->in->quit_main = 0;
    all_infos()->in->map_actual = 0;
    all_infos()->pos_player.x = 500;
    all_infos()->pos_player.y = 350;
    all_infos()->bo->first_run = false;
    all_infos()->bo->save = false;
    all_infos()->in->nb_of_zoom = 1;
    all_infos()->zoom = 1;
    all_infos()->move = '\0';
    all_infos()->in->life = 10;
    all_infos()->stamina = 10;
    all_infos()->bo->opened_chest = false;
    reset_2();
    reinitialize2();
    return;
}
