#include "contact.h"
#include <malloc.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#ifndef PROJECT_DIARY_MANAGEMENT_DIARY_H
#define PROJECT_DIARY_MANAGEMENT_DIARY_H


typedef struct s_d_diary {
    t_d_contact **heads;
    int max_levels;
} t_d_diary;


void insert_contact(t_d_diary *diary, t_d_contact *contact);
//* Function to insert a contact in the diary
// * takes the diary and the contact as parameters
// * inserts the contact in the diary
// * returns nothing

t_d_diary *create_mt_diary(int max);
//* Function to create a new diary
// * takes the max number of levels as a parameter (always 4)
// * returns a pointer to the new diary

void display_a_level_names(t_d_diary *diary, int level);
//* Function to display the names of the contacts in a level
// * takes the diary and the level as parameters
// * prints the names of the contacts in the level
// * returns nothing

void display_all_levels_names(t_d_diary *diary);
//* Function to display the names of the contacts in all the levels
// * takes the diary as a parameter
// * prints the names of the contacts in all the levels
// * returns nothing

#endif //PROJECT_DIARY_MANAGEMENT_DIARY_H
