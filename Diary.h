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
void sorted_insert(t_d_diary *list, t_d_contact *cell);
t_d_diary *create_mt_diary(int max);
#endif //PROJECT_DIARY_MANAGEMENT_DIARY_H
