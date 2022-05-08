/*
** EPITECH PROJECT, 2022
** B-MUL-200-MAR-2-1-myrpg-niels.ouvrard
** File description:
** save_exists2
*/

#include "my.h"
#include "rpg_header.h"

int get_type_of_data(char *line, int *type, int *run)
{
    bool enter = false;
    if (my_strstr(line, "#player_pos")) {
        *type = 1;
        enter = true;
    }
    if (my_strstr(line, "#view_info")) {
        *type = 2;
        *run = 1;
        enter = true;
    }
    if (my_strstr(line, "#map_actual")) {
        *type = 3;
        *run = 1;
        enter = true;
    }
    if (enter)
        return 1;
    return get_type_of_data2(line, type, run, enter);
}

int get_type_of_data2(char *line, int *type, int *run, bool enter)
{
    if (my_strstr(line, "#inventory")) {
        *type = 4;
        *run = 1;
        enter = true;
    }
    if (my_strstr(line, "#health_size\n")) {
        *type = 9;
        enter = true;
    }
    if (my_strstr(line, "#player_type\n")) {
        enter = true;
        *type = 10;
    }
    if (my_strstr(line, "#health\n") &&
    !my_strstr(line, "#health_size\n")) {
        *type = 8;
        enter = true;
    }
    return (get_type_of_data3(line, type, run, enter));
}

int get_type_of_data3(char *line, int *type, int *run, bool enter)
{
    if (my_strstr(line, "#closed_chests")) {
        *type = 5;
        *run = 1;
        enter = true;
    }
    if (my_strstr(line, "#quest") && !my_strstr(line, "#quest_done")) {
        *type = 6;
        *run = 1;
        enter = true;
    }
    if (my_strstr(line, "#quest_done")) {
        *type = 7;
        *run = 1;
        enter = true;
    }
    return (get_type_of_data4(line, type, run, enter));
}

int get_type_of_data4(char *line, int *type, int *run, bool enter)
{
    if (my_strstr(line, "#nb_of_enemies")) {
        *type = 11;
        enter = true;
    }
    if (enter)
        return 1;
}
