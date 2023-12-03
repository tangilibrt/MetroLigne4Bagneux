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

struct contact {
    char *name;
    char *surname;
} typedef *p_contact;

struct appointment {
    char date[10]; // format : dd/mm/yyyy
    char hour[5]; // format : hh:mm
    char length[5]; // format : hh:mm
    char *purpose;
} typedef appointment;

struct entry {
    p_contact contact;
    //list of appointments
    appointment *list_appointments;
} typedef entry;

struct diary { // level list
    entry **list_entries; //equivalent of heads on the level_list.h
} typedef diary;


diary *create_diary(int n);















#endif //PROJECT_DIARY_MANAGEMENT_DIARY_H
