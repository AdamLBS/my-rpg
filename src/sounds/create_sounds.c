/*
** EPITECH PROJECT, 2022
** B-MUL-200-MAR-2-1-myrpg-niels.ouvrard
** File description:
** create_sounds
*/

#include "my.h"
#include "rpg_header.h"

void create_sounds(void)
{
    all_infos()->sounds = malloc(sizeof(t_sounds));
    t_sounds *sounds = all_infos()->sounds;
    sounds->grass = create_sound("music/grass_walk.ogg");
    sounds->stone = create_sound("music/stone_walk.ogg");
    sounds->wood = create_sound("music/wood_walk.ogg");
    sounds->open_chest = create_sound("music/open_chest.ogg");
    sounds->music = sfMusic_createFromFile("music/main_theme.ogg");
    sfMusic_setVolume(sounds->music, 20);
    sfMusic_setLoop(sounds->music, sfTrue);
    sfMusic_play(sounds->music);
}

void play_sound(void)
{
    int curent_x = (all_sprites()[HUNTER].pos.x) / (SIZE_TILE);
    int current_y = (all_sprites()[HUNTER].pos.y) / (SIZE_TILE);
    if (!all_maps()[all_infos()->in->map_actual].bg[current_y])
        return;
    char bg = all_maps()[all_infos()->in->map_actual].bg[current_y][curent_x];
    char mg = all_maps()[all_infos()->in->map_actual].mg[current_y][curent_x];
    stop_all_sounds(bg, mg);
}

void stop_all_sounds(char c, char mg)
{
    if (!is_moving()) {
        stop_sound(all_infos()->sounds->grass);
        stop_sound(all_infos()->sounds->stone);
        stop_sound(all_infos()->sounds->wood);
        return;
    }
    if (c == '7' && is_moving()) {
        stop_sound(all_infos()->sounds->stone);
        stop_sound(all_infos()->sounds->wood);
        check_status(all_infos()->sounds->grass);
    }
    if (c == 'U' || c == 'L' || c == 'G' && is_moving()) {
        stop_sound(all_infos()->sounds->wood);
        check_status(all_infos()->sounds->stone);
        stop_sound(all_infos()->sounds->grass);
    }
    stop_all_sounds_2(c, mg);
}

void stop_sound(sfSound *sound)
{
    sfSoundStatus status = sfSound_getStatus(sound);
    if (status != sfStopped) {
        sfSound_stop(sound);
        return;
    }
}

void check_status(sfSound *sound)
{
    sfSoundStatus status = sfSound_getStatus(sound);
    if (status != sfStopped) {
        sfSound_setLoop(sound, sfTrue);
    } else
        sfSound_play(sound);
    return;
}
