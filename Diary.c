#include "Diary.h"
#include "contact.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

t_d_diary *create_mt_diary(int max){

    t_d_diary *diary = (t_d_diary *)malloc(sizeof(t_d_diary));
    diary->heads = (t_d_contact **)calloc(max, sizeof(t_d_contact *));
    diary->max_levels = max ;
}
void manage_levels( t_d_diary * diary){
    t_d_contact *temp = (t_d_contact *)malloc(sizeof (t_d_contact));
     temp->firstname = "aaaaaaaaaaaa";
     temp->surname = "aaaaaaaaaaaa";
     temp->levels = diary->max_levels;

    for (int i = 0; i < temp->levels; i++) {
        temp->next[i] = diary->heads[i];
        diary->heads[i] = temp;}
}

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
