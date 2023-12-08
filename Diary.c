#include "Diary.h"
#include "contact.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
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

void sorted_insert(t_d_diary *list, t_d_contact *cell) {
    for (int i = 0; i < cell->levels; i++) {
        t_d_contact **temp = &(list->heads[i]);
        while (*temp && compareStrings(cell->surname,temp[i]->surname)==1) {
            temp = &((*temp)->next[i]);
        }
        cell->next[i] = *temp;
        *temp = cell;
    }
}