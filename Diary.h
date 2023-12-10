#include "contact.h"
#ifndef PROJECT_DIARY_MANAGEMENT_DIARY_H
#define PROJECT_DIARY_MANAGEMENT_DIARY_H

typedef struct s_d_diary {
    t_d_contact **heads;
    int max_levels;
} t_d_diary;

void manage_levels( t_d_diary * diary);
int compareStrings(char *string1, char *string2);
int compareString_car(char *string1, char *string2);
void sorted_insert_diary(t_d_diary *list, t_d_contact *cell);
t_d_diary *create_mt_diary(int max);
t_d_contact *optimized_searh_diary(t_d_diary *list, char *value);
void insert_contact(t_d_diary *diary, t_d_contact *contact);
void display_a_level_diary(t_d_diary *list, int level);
void display_all_levels_diary(t_d_diary *list);
void insert_cell_at_a_head_diary(t_d_diary *list, t_d_contact *cell);
void creat_and_insert(t_d_diary *list);
#endif //PROJECT_DIARY_MANAGEMENT_DIARY_H
