/*
** EPITECH PROJECT, 2022
** snake_no_map.c
** File description:
** snake level 0
*/

#include "my.h"
#include "rpg_header.h"

#define f2 sfVector2f
#define N NULL

void display_boxes(void)
{
    int s = EMPTY_BOX;
    s = all_editor()->edit_ground == 'f' ? CHECK_BOX : EMPTY_BOX;
    sfSprite_setPosition(all_sprites()[s].sprite, (f2){1920 - 80, 65});
    sfRenderWindow_drawSprite(all_infos()->window, all_sprites()[s].sprite, N);
    s = all_editor()->edit_ground == 'm' ? CHECK_BOX : EMPTY_BOX;
    sfSprite_setPosition(all_sprites()[s].sprite, (f2){1920 - 80, 115});
    sfRenderWindow_drawSprite(all_infos()->window, all_sprites()[s].sprite, N);
    s = all_editor()->edit_ground == 'b' ? CHECK_BOX : EMPTY_BOX;
    sfSprite_setPosition(all_sprites()[s].sprite, (f2){1920 - 80, 165});
    sfRenderWindow_drawSprite(all_infos()->window, all_sprites()[s].sprite, N);
    s = all_editor()->v_fg ? CHECK_BOX : EMPTY_BOX;
    sfSprite_setPosition(all_sprites()[s].sprite, (f2){1920 - 30, 65});
    sfRenderWindow_drawSprite(all_infos()->window, all_sprites()[s].sprite, N);
    s = all_editor()->v_mg ? CHECK_BOX : EMPTY_BOX;
    sfSprite_setPosition(all_sprites()[s].sprite, (f2){1920 - 30, 115});
    sfRenderWindow_drawSprite(all_infos()->window, all_sprites()[s].sprite, N);
    s = all_editor()->v_bg ? CHECK_BOX : EMPTY_BOX;
    sfSprite_setPosition(all_sprites()[s].sprite, (f2){1920 - 30, 165});
    sfRenderWindow_drawSprite(all_infos()->window, all_sprites()[s].sprite, N);
}

void disp_text_size(void)
{
    sfText_setCharacterSize(all_editor()->editor_text, 40);
    sfText_setString(all_editor()->editor_text, "-           +");
    sfText_setPosition(all_editor()->editor_text, (f2){1920 - 150, 180});
    sfRenderWindow_drawText(all_infos()->window, all_editor()->editor_text, N);
    char *size_x = my_int_to_str(all_editor()->size_edit.x);
    sfText_setString(all_editor()->editor_text, size_x);
    sfText_setPosition(all_editor()->editor_text, (f2){1920 - 120, 180});
    sfRenderWindow_drawText(all_infos()->window, all_editor()->editor_text, N);
    free(size_x);
    sfText_setString(all_editor()->editor_text, "-           +");
    sfText_setPosition(all_editor()->editor_text, (f2){1920 - 150, 230});
    sfRenderWindow_drawText(all_infos()->window, all_editor()->editor_text, N);
    char *size_y = my_int_to_str(all_editor()->size_edit.y);
    sfText_setString(all_editor()->editor_text, size_y);
    sfText_setPosition(all_editor()->editor_text, (f2){1920 - 120, 230});
    sfRenderWindow_drawText(all_infos()->window, all_editor()->editor_text, N);
    free(size_y);
}

void disp_text_and_boxes(void)
{
    sfText_setCharacterSize(all_editor()->editor_text, 20);
    sfText_setString(all_editor()->editor_text, "Edit");
    sfText_setPosition(all_editor()->editor_text, (f2){1920 - 100, 20});
    sfRenderWindow_drawText(all_infos()->window, all_editor()->editor_text, N);
    sfText_setString(all_editor()->editor_text, "View");
    sfText_setPosition(all_editor()->editor_text, (f2){1920 - 50, 20});
    sfRenderWindow_drawText(all_infos()->window, all_editor()->editor_text, N);
    sfText_setString(all_editor()->editor_text, "FG");
    sfText_setPosition(all_editor()->editor_text, (f2){1920 - 150, 50});
    sfRenderWindow_drawText(all_infos()->window, all_editor()->editor_text, N);
    sfText_setString(all_editor()->editor_text, "MG");
    sfText_setPosition(all_editor()->editor_text, (f2){1920 - 150, 100});
    sfRenderWindow_drawText(all_infos()->window, all_editor()->editor_text, N);
    sfText_setString(all_editor()->editor_text, "BG");
    sfText_setPosition(all_editor()->editor_text, (f2){1920 - 150, 150});
    sfRenderWindow_drawText(all_infos()->window, all_editor()->editor_text, N);
    display_boxes();
    disp_text_size();
}
