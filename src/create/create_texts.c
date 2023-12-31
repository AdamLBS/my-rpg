/*
** EPITECH PROJECT, 2021
** game file 1
** File description:
** lib csfml
*/

#include "my.h"
#include "rpg_header.h"

static sf_text *game_texts;

sf_text *all_texts(void)
{
    return game_texts;
}

void create_texts(void)
{
    game_texts = malloc(sizeof(main_screen));
    game_texts->font =
    sfFont_createFromFile("font/AncientModernTales-a7Po.ttf");
    game_texts->simple_text = sfText_create();
    sfText_setFont(game_texts->simple_text, game_texts->font);
    sfText_setColor(game_texts->simple_text, sfBlack);
    game_texts->simple_text2 = sfText_create();
    sfText_setFont(game_texts->simple_text2, game_texts->font);
    sfText_setColor(game_texts->simple_text2, sfBlack);
    game_texts->simple_text3 = sfText_create();
    sfText_setFont(game_texts->simple_text3, game_texts->font);
    sfText_setColor(game_texts->simple_text3, sfBlack);
    game_texts->code = sfText_create();
    sfText_setFont(game_texts->code, game_texts->font);
    sfText_setColor(game_texts->code, sfWhite);
    sfText_setCharacterSize(game_texts->code, 80);
    game_texts->pos_text = 0;
    game_texts->text = malloc(sizeof(char) * 100);
    return;
}
