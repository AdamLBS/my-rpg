/*
** EPITECH PROJECT, 2022
** B-MUL-200-MAR-2-1-myrpg-niels.ouvrard
** File description:
** save_exists
*/

#include "my.h"
#include "rpg_header.h"

int does_save_exists(int check)
{
    FILE *fd = fopen("save.txt", "r");
    if (fd == NULL)
        return 0;
    size_t len;
    char *buf = NULL;
    int save = 0;
    while (getline(&buf, &len, fd) != -1) {
        if (my_strstr(buf, "#player_pos"))
            save = 1;
    }
    if (!save)
        return 0;
    if (!check)
    get_info_save();
}

int get_info_save(void)
{
    FILE *fd = fopen("save.txt", "r");
    char *line = NULL, *buf = NULL;
    int type = 0, run = 1;
    size_t len;
    sfVector2f pos;
    while (getline(&line, &len, fd) != -1) {
        if (get_type_of_data(line, &type, &run))
            continue;
        handle_infos(line, &type, &run, &pos);
        run++;
    }
}

void handle_infos(char *line, int *type, int *run, sfVector2f *pos)
{
    handle_map_actual(type, line);
    handle_player_pos(line, type, *run);
    *pos = handle_view_pos(line, type, *run, *pos);
    handle_inventory(line, type);
    handle_save_chests(line, type);
    restore_quests(line, type);
    restore_quests_done(line, type);
    restore_health_points(*type, line);
    restore_life_size(*type, line);
    restore_player_type(*type, line);
    restore_nb_of_enemies(*type, line);
}
