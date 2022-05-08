/*
** EPITECH PROJECT, 2022
** B-MUL-200-MAR-2-1-myrpg-niels.ouvrard
** File description:
** write_to_file2
*/

#include "my.h"
#include "rpg_header.h"

void save_healthpoints(FILE *fd)
{
    fwrite("#health\n", 1, my_strlen("#health\n"), fd);
    fwrite(my_itoa(all_infos()->in->life), 1,
    my_strlen(my_itoa(all_infos()->in->life)), fd);
    fwrite("\n", 1, 1, fd);
    return;
}

void save_healthsize(FILE *fd)
{
    fwrite("#health_size\n", 1, my_strlen("#health_size\n"), fd);
    fwrite(my_itoa(all_infos()->in->life_size), 1,
    my_strlen(my_itoa(all_infos()->in->life_size)), fd);
    fwrite("\n", 1, 1, fd);
}

void save_player_type(FILE *fd)
{
    fwrite("#player_type\n", 1, my_strlen("#player_type\n"), fd);
    fwrite(my_itoa(all_infos()->in->player_type), 1,
    my_strlen(my_itoa(all_infos()->in->player_type)), fd);
    fwrite("\n", 1, 1, fd);
}

void save_nb_enemies(FILE *fd)
{
    fwrite("#nb_of_enemies\n", 1, my_strlen("#nb_of_enemies\n"), fd);
    fwrite(my_itoa(all_infos()->in->nb_of_enemies_outside), 1,
    my_strlen(my_itoa(all_infos()->in->nb_of_enemies_outside)), fd);
    fwrite("\n", 1, 1, fd);
}
