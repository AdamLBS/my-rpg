/*
** EPITECH PROJECT, 2021
** game file 1
** File description:
** lib csfml
*/

#include "my.h"
#include "rpg_header.h"

static main_screen *infos;

main_screen *all_infos(void)
{
    return infos;
}

void main_vals_utils(void)
{
    infos->bo->move_u = false;
    infos->bo->move_d = false;
    infos->bo->move_l = false;
    infos->bo->move_r = false;
    infos->in->life_size = 150;
    infos->bo->doing_quest = false;
    infos->clock = sfClock_create();
    infos->in->player_type = 0;
    infos->zoom = 1;
    infos->move = '\0';
    infos->in->life = 10;
    infos->stamina = 10;
    infos->bo->opened_chest = false;
    infos->quest_done[0] = '\0';
    infos->quest_done[1] = '\0';
    infos->quest_done[2] = '\0';
    all_infos()->in->banana_nb = 0;
    all_infos()->in->apple_nb = 0;
}

void initialize_main_vals(void)
{
    main_vals_utils();
    infos->in->level = 0;
    infos->in->ennemy_id = 0;
    infos->in->quit_main = 0;
    infos->in->clock_val = 0;
    infos->particules = NULL;
    infos->view_position.x = 960;
    infos->in->inventory_move = 0;
    infos->view_position.y = 540;
    infos->view = sfView_create();
    infos->hud_view = sfView_create();
    infos->in->quest_id = 0;
    infos->in->nb_of_enemies_outside = 0;
    sfView_setCenter(infos->hud_view, (sfVector2f) {1920 / 2, 1080 / 2});
    sfView_setSize(infos->hud_view, (sfVector2f) {1920, 1080});
    sfRenderWindow_setView(infos->window, infos->hud_view);
    infos->last_move = 'd';
    sfView_setCenter(infos->view, (sfVector2f) {10 * 50, (10 * 35) - 16});
    sfView_setSize(infos->view, (sfVector2f) {1920 / 2, 1080 / 2});
    sfRenderWindow_setView(infos->window, infos->view);
}

void add_to_inventory (struct_inventory **list, int value)
{
    struct_inventory *new_node = malloc(sizeof(struct_inventory));
    new_node->object = value;
    new_node->next = NULL;
    if (*list == NULL) {
        *list = new_node;
        return;
    }
    struct_inventory *last = *list;
    while (last->next)
        last = last->next;
    last->next = new_node;
}

void create_main(void)
{
    infos = malloc(sizeof(main_screen));
    infos->bo = malloc(sizeof(t_bo));
    infos->in = malloc(sizeof(t_in));
    create_sounds();
    sfVideoMode mode = {SCREEN_MAX_X, SCREEN_MAX_Y, 60};
    infos->window = sfRenderWindow_create(mode, "RPG",
    sfResize | sfClose, NULL);
    infos->in->map_actual = 0;
    infos->pos_player.x = 500;
    infos->pos_player.y = 350;
    infos->bo->first_run = false;
    infos->bo->save = false;
    infos->in->nb_of_zoom = 1;
    struct_inventory *val = NULL;
    infos->inventory = val;
    all_infos()->stamina_clock = sfClock_create();
    all_infos()->text_clock = sfClock_create();
    all_infos()->in->text_char = 0;
    initialize_main_vals();
    return;
}
