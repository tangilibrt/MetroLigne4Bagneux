//
// Created by tangi on 03/12/2023.
//

#ifndef PROJECT_DIARY_MANAGEMENT_DIARY_H
#define PROJECT_DIARY_MANAGEMENT_DIARY_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "cell.h"
#include "level_list.h"

// we will create a list of fixed depth n = 4

typedef struct contact {
    char *name;
    char *surname;
} *p_contact;

typedef struct appointment {
    char date[10]; // format : dd/mm/yyyy
    char hour[5]; // format : hh:mm
    char length[5]; // format : hh:mm
    char *purpose;
} appointment;

typedef struct entry {
    p_contact contact;
    //list of appointments
    appointment *list_appointments;
    struct entry **next;
} entry;

typedef struct diary { // level list
    entry **list_entries; //equivalent of heads on the level_list.h
} diary;


diary *create_diary();
entry *create_entry(char *name, char *surname);
void add_entry(diary *diary, entry *entry);
void align_and_display_diary(diary *diary);














#endif //PROJECT_DIARY_MANAGEMENT_DIARY_H
