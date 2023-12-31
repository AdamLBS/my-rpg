/*
** EPITECH PROJECT, 2021
** game file 1
** File description:
** lib csfml
*/

#include "my.h"
#include "rpg_header.h"

static struct_maps *map_dictionary;

struct_maps edit_bg_pas_gabriel(struct_maps autr)
{
    int size = 0;
    for (int i = 0; autr.bg[i]; i++)
        if (autr.bg[i][0] == '$')
            size = i;
    if (size == 0)
        return autr;
    char **new_bg = malloc(sizeof(char *) * (size + 1));
    for (int i = 0; i < size; i++)
        new_bg[i] = autr.bg[i];
    new_bg[size] = NULL;
    autr.interact = NULL;
    for (int i = size + 1; autr.bg[i]; i++)
        autr.interact = interactions_of_map(autr.bg[i], autr);
    autr.bg = new_bg;
    struct_interact *list = autr.interact;
    while (list)
        list = list->next;
    return autr;
}

char **array_of_printed(char **size)
{
    int size_x = my_strlen(size[0]);
    int size_y = my_arraylen(size);
    char **array = malloc(sizeof(char *) * (size_y + 1));
    for (int i = 0; i < size_y; i++) {
        array[i] = malloc(sizeof(char) * (size_x + 1));
        my_memset(array[i], size_y, 'N');
        array[i][size_x] = '\0';
    }
    array[size_y] = NULL;
    return array;
}

void list_of_map(char *filepath, int i, char **arr)
{
    my_memset(filepath, 511, '\0');
    my_strcpy(filepath, "map/");
    my_strcat(filepath, arr[i]);
    my_strcat(filepath, "bg");
    int size = my_strlen(filepath);
    map_dictionary[i].bg = filepath_to_arr(filepath);
    map_dictionary[i] = edit_bg_pas_gabriel(map_dictionary[i]);
    filepath[size - 2] = '\0';
    my_strcat(filepath, "mg");
    map_dictionary[i].mg = filepath_to_arr(filepath);
    map_dictionary[i].is_printed = array_of_printed(map_dictionary[i].mg);
    filepath[size - 2] = '\0';
    my_strcat(filepath, "fg");
    map_dictionary[i].fg = filepath_to_arr(filepath);
    explore_map_find_all_ennemis(i);
    explore_map_find_all_npcs(i);
}

void fill_map_dictionary(void)
{
    char **arr = filepath_to_arr("map/list_maps.txt");
    int nbr = my_arraylen(arr), i;
    map_dictionary = malloc(sizeof(struct_maps) * (nbr + 1));
    char *filepath = malloc(sizeof(char) * 512);
    for (i = 0; arr[i]; i++)
        list_of_map(filepath, i, arr);
    free_my_arr(arr);
}

struct_maps *all_maps(void)
{
    return map_dictionary;
}
