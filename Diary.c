#include "Diary.h"
#include "contact.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

// yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy
t_d_diary *create_mt_diary(int max){

    t_d_diary *diary = (t_d_diary *)malloc(sizeof(t_d_diary));
    diary->heads = (t_d_contact **)calloc(max, sizeof(t_d_contact *));
    diary->max_levels = max ;
}
// yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy
int compareString_car(char *string1, char *string2) {
    """Compare two strings and return the number of letters that are the same"
    "If the two strings are identical, return -1"
    "If the two strings are different, return the number of letters that are the same"
    "parameters : string1, string2 : two strings"
    "example : "
    ">>> string1 = 'abc'"
    ">>> string2 = 'abc'"
    ">>> printf('%d', compareString(string1, string2))"
    ">>> -1"
    ">>> string1 = 'abc'"
    ">>> string2 = 'abd'"
    ">>> printf('%d', compareString(string1, string2))"
    ">>> 2""";

    int count = 0;
    while (string1[count] != '\0' && string2[count] != '\0' && count<=3) {
        if (string1[count] != string2[count]) {
            return count; // return the number of letters that are the same when it detects a difference
        }
        count++; // count the number of letters that are the same
    }
    return count ; // return -1 if the two strings are identical
}
// yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy
void manage_levels( t_d_diary * diary){
    t_d_contact *temp = (t_d_contact *)malloc(sizeof (t_d_contact));
     temp->firstname = "aaaaaaaaaaaa";
     temp->surname = "aaaaaaaaaaaa";
     temp->levels = diary->max_levels;

    for (int i = 0; i < temp->levels; i++) {
        temp->next[i] = diary->heads[i];
        diary->heads[i] = temp;}
}
// yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy
int compareStrings(char *string1, char *string2) {
    int i = 0;

    while (string1[i] != '\0' && string2[i] != '\0') {
        if (string1[i] != string2[i]) {
            // determi witch char is biger
            return (string1[i] > string2[i]) ? 1 : 3;
        }
        i++;
    }
    // look if they are the same
    if (string1[i] == '\0' && string2[i] == '\0') {
        return 2; // Les chaînes sont identiques
    } else {
        // Si l'une des chaînes est plus longue que l'autre
        return (string1[i] == '\0') ? 3 : 1;
    }
}
// yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy

void sorted_insert_diary(t_d_diary *list, t_d_contact *cell) {
    for (int i = 0; i < cell->levels; i++) {
        t_d_contact **temp = &(list->heads[i]);
        while (*temp && compareStrings(cell->surname,temp[i]->surname)==1) {
            temp = &((*temp)->next[i]);
        }
        cell->next[i] = *temp;
        *temp = cell;
    }
}

// yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy
t_d_contact *optimized_searh_diary(t_d_diary *list, char *value) {
    int level = list->max_levels - 1;
    t_d_contact *current = list->heads[level];
    printf("level%d, valu%s\n", current->levels, current->firstname);
    while (level >= 0) {
        while (current != NULL && compareStrings(current->firstname, value)==3) {
            current = current->next[level];
            printf("level%d, valu%d\n", current->levels, current->firstname);
        }

        if (current != NULL && compareStrings(current->firstname, value)==2) {
            printf("trouver au niveau %d\n",level);
            return current; // Found
        }
        level--;
        if (level >= 0 && current != NULL) {
            current = list->heads[level];
            printf("level%d, valu%d\n", current->levels, current->firstname);
        }
    }
    return NULL; // Not found
}
// yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy
void insert_contact(t_d_diary *diary, t_d_contact *contact) {
    if (diary->heads[1]==NULL) {
        printf("the diary is empty\n");
        for (int level = 1; level <= 4 ; level++) {
            diary->heads[level] = (t_d_contact *)malloc(sizeof(t_d_contact));
            diary->heads[level]->next = NULL;
            diary->heads[level]->surname = NULL;
            diary->heads[level]->firstname = NULL;

            memcpy(diary->heads[level], contact, sizeof(t_d_contact));
        }
    } else {
        printf("the diary is not empty\n");
        t_d_contact **holder = (t_d_contact **)malloc(sizeof(t_d_contact *));
        t_d_contact **highestPrevious = (t_d_contact **)malloc(sizeof(t_d_contact *));
        t_d_contact **memory = diary->heads;
        highestPrevious = diary->heads;

        int foundPlace = 0;
        int level = 4;
        while (memory[level]->next != NULL && level > 0) {
            printf("entered the while loop at level %d\n", level);
            holder[level]->next[level] = memory[level]->next[level];
            if (memory[level]->next[level]->surname[4-level] == contact->surname[4-level] && foundPlace == 0) {
                printf("entered the if == statement at level %d\n", level);
                if (strcmp(memory[level]->next[level]->surname, contact->surname) == 0) {
                    contact->next[level] = memory[level]->next[level];
                    memory[level]->next[level] = contact;
                }

                level--;
                if (level == 1) {
                    foundPlace = 1;
                    contact->next[level] = memory[level]->next[level];
                    memory[level]->next[level] = contact;

                }
            }
            if (strcmp(memory[level]->next[level]->surname, contact->surname) == 0 && foundPlace == 1)
            {
                printf("entered the if strcmp & fP==1 statement at level %d\n", level);
                contact->next[level] = memory[level]->next[level];
                memory[level]->next[level] = contact;
                level--;
                memory[level] = highestPrevious[level];
            }
            else if (memory[level]->next[level]->surname[4-level] > contact->surname[4-level]) {
                printf("entered the if > statement at level %d\n", level);
                contact->next[level] = memory[level]->next[level];
                memory[level]->next[level] = contact;
                foundPlace = 1;
                for (int i = 1; i <= level; i++) {
                    highestPrevious[i] = memory[level];
                }
                level--;
            }

            else if (memory[level]->next[level]->surname[4-level] < contact->surname[4-level]){
                printf("entered the if < statement at level %d\n", level);
                memory[level] = memory[level]->next[level];
            }

        }
        if (memory[level]->next[level] == NULL) {
            printf("entered the if == NULL statement at level %d\n", level);
            memory[level]->next[level] = contact;
            level--;
        }
        free(contact);
        free(holder);
        free(highestPrevious);
    }

}
// yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy
void display_a_level_diary(t_d_diary *list, int level){
    if (level < 0 || level >= list->max_levels) {
        printf("Invalid level\n");
        return;
    }
    printf("[list head_%d]--", level);

    t_d_contact *cell_actuel = list->heads[level];

    while (cell_actuel != NULL) {
        printf(">[ %s_%s]--", cell_actuel->surname,cell_actuel->firstname);
        cell_actuel = cell_actuel->next[level];

    }
    printf(" >NULL\n");
}
// yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy
void display_all_levels_diary(t_d_diary *list){

    for (int i = 0; i < list->max_levels; i++)
    {
        display_a_level_diary( list, i);
    }
}
// yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy

void insert_cell_at_a_head_diary(t_d_diary *list, t_d_contact *cell){

    for (int i = 0; i < list->max_levels; i++) {
        list->heads[i] = cell;}

}

void creat_and_insert(t_d_diary *list){




}