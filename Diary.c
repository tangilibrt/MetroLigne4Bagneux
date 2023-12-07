#include "Diary.h"
#include "contact.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
void manage_levels( t_d_diary * diary){
    t_d_contact *temp ;
     temp->firstname = "aaaaaaaaaaaa";
     temp->surname = "aaaaaaaaaaaa";
     temp->levels = diary->max_levels;

    for (int i = 0; i < temp->levels; i++) {
        temp->next[i] = diary->heads[i];
        diary->heads[i] = temp;}
}
