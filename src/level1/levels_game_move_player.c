/*
** EPITECH PROJECT, 2022
** snake_no_map.c
** File description:
** snake level 0
*/

#include "my.h"
#include "rpg_header.h"

void recalculate_the_sprite_perso (void)
{
    all_sprites()[HUNTER].rect.left = 0;
    if (all_infos()->bo->move_u)
        all_sprites()[HUNTER].rect.top = 0;
    if (all_infos()->bo->move_d)
        all_sprites()[HUNTER].rect.top = 16;
    if (all_infos()->bo->move_l)
        all_sprites()[HUNTER].rect.top = 2 * 16;
    if (all_infos()->bo->move_r)
        all_sprites()[HUNTER].rect.top = 3 * 16;
    sfSprite_setTextureRect(all_sprites()[HUNTER].sprite,
    all_sprites()[HUNTER].rect);
}

void change_pos_and_views (int x, int y)
{
    all_infos()->pos_player.y += y;
    all_infos()->pos_player.x += x;
    all_sprites()[HUNTER].pos.y += y;
    all_sprites()[HUNTER].pos.x += x;
    sfView_move(all_infos()->view, (sfVector2f) {x, y});
}

void move_pos_player_next(char a)
{
    if (all_infos()->bo->move_l && can_move(-5, 0)) {
        all_infos()->bo->can_move = true;
        all_infos()->move = 'l';
        move_sprint(-5, 0);
        if (!all_infos()->bo->move_u && !all_infos()->bo->move_d)
            change_pos_and_views(-3, 0);
    }
    if (all_infos()->move != 'c' && all_infos()->move != '\0')
        all_infos()->last_move = all_infos()->move;
    if (a != all_infos()->move)
        recalculate_the_sprite_perso();
    sfSprite_setPosition(all_sprites()[HUNTER].sprite,
    all_sprites()[HUNTER].pos);
    sfRenderWindow_setView(all_infos()->window, all_infos()->view);
    if (all_infos()->move != 'c' && all_infos()->bo->can_move)
        add_particules(all_sprites()[HUNTER].pos, 10,
        sfColor_fromRGBA(255, 255, 255, 200));
}

void move_pos_player(void)
{
    char a = all_infos()->move;
    all_infos()->bo->can_move = false;
    if (all_infos()->bo->move_d && can_move(0, 5)) {
        all_infos()->bo->can_move = true;
        all_infos()->move = 'd';
        move_sprint(0, 5);
        if (!all_infos()->bo->move_l && !all_infos()->bo->move_r)
            change_pos_and_views(0, 3);
    }
    if (all_infos()->bo->move_u && can_move(0, -5)) {
        all_infos()->bo->can_move = true;
        all_infos()->move = 'u';
        move_sprint(0, -5);
        if (!all_infos()->bo->move_l && !all_infos()->bo->move_r)
            change_pos_and_views(0, -3);
    }
    move_pos_player_utils(a);
    move_pos_player_next(a);
}

void move_sprint(int x, int y)
{
    int sprint_x = x;
    int sprint_y = y;
    if (sprint_x != 0 && sprint_x > 0)
        sprint_x += 2;
    if (sprint_y != 0 && sprint_y > 0)
        sprint_y += 2;
    if (sprint_x != 0 && sprint_x < 0)
        sprint_x -= 2;
    if (sprint_y != 0 && sprint_y < 0)
        sprint_y -= 2;
    if (all_infos()->bo->sprint && can_move(sprint_x, sprint_y)
    && all_infos()->stamina > 0) {
        change_pos_and_views(sprint_x, sprint_y);
    } else
        change_pos_and_views(x, y);
}
