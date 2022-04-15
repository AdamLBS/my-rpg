/*
** EPITECH PROJECT, 2022
** snake_no_map.c
** File description:
** snake level 0
*/

#include "my.h"
#include "rpg_header.h"

// on png
// A-B-C-A-D-E
// on code
// a-b-c-A-B-C

// not F
void anim_perso_left_right (void)
{
    char a = all_sprites()[HUNTER].anim;
    // my_printf("on anim à partir de %c\n", a);
    if ((a < 'a' && a > 'c') || (a < 'A' && a > 'C'))
        all_sprites()[HUNTER].anim = 'a';
    if (all_sprites()[HUNTER].anim >= 'a' && all_sprites()[HUNTER].anim <= 'c') {
        if (all_sprites()[HUNTER].anim == 'c') {
            all_sprites()[HUNTER].rect.left = 0;
            all_sprites()[HUNTER].anim = 'A';
            return;
        }
        all_sprites()[HUNTER].anim++;
        all_sprites()[HUNTER].rect.left += 16;
        return;
    }
    if (all_sprites()[HUNTER].anim == 'A') {
        all_sprites()[HUNTER].anim++;
        all_sprites()[HUNTER].rect.left = 3 * 16;
        return;
    }
    if (all_sprites()[HUNTER].anim == 'B') {
        all_sprites()[HUNTER].anim++;
        all_sprites()[HUNTER].rect.left += 16;
        return;
    }
    // if (all_sprites()[HUNTER].anim == 'C') {
    all_sprites()[HUNTER].anim = 'a';
    all_sprites()[HUNTER].rect.left = 0;
    //     return;
    // }
}

// all_sprites()[sprite].rect.left -= 16;
// all_sprites()[sprite].anim--;
// a-b-A-B
void anim_perso_up_and_down (void)
{
    char a = all_sprites()[HUNTER].anim;
    // my_printf("on anim à partir de %c\n", a);
    if ((a < 'a' && a > 'b') || (a < 'A' && a > 'B'))
        all_sprites()[HUNTER].anim = 'a';
    if (all_sprites()[HUNTER].anim >= 'a' && all_sprites()[HUNTER].anim <= 'b') {
        if (all_sprites()[HUNTER].anim == 'a') {
            all_sprites()[HUNTER].anim = 'b';
            all_sprites()[HUNTER].rect.left = 16;
            return;
        } else {
        // if (all_sprites()[HUNTER].anim == 'b') {
            all_sprites()[HUNTER].anim = 'A';
            all_sprites()[HUNTER].rect.left = 0;
            return;
        }
        // all_sprites()[HUNTER].anim = 'b';
        // all_sprites()[HUNTER].rect.left += 16;
        // return;
    }
    // if (all_sprites()[HUNTER].anim >= 'A' && all_sprites()[HUNTER].anim <= 'B') {
    if (all_sprites()[HUNTER].anim == 'B') {
        all_sprites()[HUNTER].anim = 'a';
        all_sprites()[HUNTER].rect.left = 0;
        return;
    } else {
        all_sprites()[HUNTER].anim = 'B';
        all_sprites()[HUNTER].rect.left = 16 * 2;
        return;
    }
    // }
}

void anim_perso_according_to_int (void)
{
    // my_printf("top : %d\tleft : %d\n", all_sprites()[HUNTER].rect.top, all_sprites()[HUNTER].rect.left);
    if (all_sprites()[HUNTER].rect.top >= 64) {
        // my_printf("on anime son tire\n");
        if (all_sprites()[HUNTER].rect.left > 0)
            all_sprites()[HUNTER].rect.left -= 16;
    // all_sprites()[HUNTER].rect.left = 64;
    // all_infos()->move = all_infos()->last_move;
    // if (all_infos()->move == 'l' || all_infos()->move == 'd')
    //     all_sprites()[HUNTER].rect.top = 32;
    // else if (all_infos()->move == 'r' || all_infos()->move == 'u')
    //     all_sprites()[HUNTER].rect.top = 48;
        return;
    }
    if (all_sprites()[HUNTER].rect.top > 16) {
        // my_printf("L / R\n");
        anim_perso_left_right();
        return;
    }
    // my_printf("U / D\n");
    anim_perso_up_and_down();
}
