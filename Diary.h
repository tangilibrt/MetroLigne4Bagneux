#include "contact.h"
#ifndef PROJECT_DIARY_MANAGEMENT_DIARY_H
#define PROJECT_DIARY_MANAGEMENT_DIARY_H

typedef struct s_d_diary {
    t_d_contact **heads;
    int max_levels;
} t_d_diary;

void manage_levels( t_d_diary * diary);
int compareStrings(char *string1, char *string2);
#endif //PROJECT_DIARY_MANAGEMENT_DIARY_H
