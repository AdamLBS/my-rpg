/*
** EPITECH PROJECT, 2021
** game file 1
** File description:
** lib csfml
*/

#include "my.h"
#include "rpg_header.h"

static sprite_pictures *value;

void full_list_sprites_next (void)
{
    value[GRASS].scale.x = 0.50;
    value[GRASS].scale.y = 0.50;
    sfSprite_setScale(value[GRASS].sprite, value[GRASS].scale);
    value[SAND].scale.x = 0.50;
    value[SAND].scale.y = 0.50;
    sfSprite_setScale(value[SAND].sprite, value[SAND].scale);
    value[WATHER].scale.x = 0.50;
    value[WATHER].scale.y = 0.50;
    sfSprite_setScale(value[WATHER].sprite, value[WATHER].scale);
    value[DIRT].scale.x = 0.50;
    value[DIRT].scale.y = 0.50;
    sfSprite_setScale(value[DIRT].sprite, value[DIRT].scale);

    value[GHOST].scale.x = 2.50;
    value[GHOST].scale.y = 2.50;
    sfSprite_setScale(value[GHOST].sprite, value[GHOST].scale);
    value[GHOST].pos.y = 1080 / 2;
    value[GHOST].pos.x = 1920 / 2;
    value[GHOST].anim = false;
    sfSprite_setPosition(value[GHOST].sprite, value[GHOST].pos);
    value[GHOST].rect.top = (16 * random_int(0, 3));
    value[GHOST].rect.left = 0;
    value[GHOST].rect.width = 15;
    value[GHOST].rect.height = 15;
    sfSprite_setTextureRect(value[GHOST].sprite, value[GHOST].rect);
}

void full_list_sprites (void)
{
    char **arr = filepath_to_arr("pictures/pictures.txt");
    int nbr = my_arraylen(arr), i;
    value = malloc(sizeof(sprite_pictures) * (nbr + 1));
    for (i = 0; arr[i]; i++) {
        value[i].sprite = sfSprite_create();
        value[i].texture = sfTexture_createFromFile(arr[i], NULL);
        sfSprite_setTexture(value[i].sprite, value[i].texture, sfTrue);
        value[i].rect.height = 0;
        value[i].rect.top = 0;
        value[i].rect.left = 0;
        value[i].rect.width = 0;
        value[i].scale.x = 1;
        value[i].scale.y = 1;
        value[i].origin.x = 0;
        value[i].origin.y = 0;
        value[i].pos.x = 0;
        value[i].pos.x = 0;
    }
    full_list_sprites_next();
    free_my_arr(arr);
}

sprite_pictures *all_sprites (void)
{
    return value;
}
