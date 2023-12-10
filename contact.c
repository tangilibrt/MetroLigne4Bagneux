#include "contact.h"
#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "Diary.h"



// yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy
char *scanString(void) {
    char tempchar[1024];
    if (fgets(tempchar, sizeof(tempchar), stdin) == NULL) {
        return NULL; // En cas derreur
    }

    size_t length = strlen(tempchar);
    if (length > 0 && tempchar[length - 1] == '\n') { //enlever les saut de ligne
        tempchar[length - 1] = '\0';
    }

    // Alou la memoir pour le char
    char *str = (char *)malloc(strlen(tempchar) + 1);
    if (str == NULL) {
        return NULL;
    }    strcpy(str, tempchar);

    return str;
}
// yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy
void scanDate(DateTime *dt) {
    char input[100];
    printf("Enter date and time (DD/MM/YYYY HH:MM):");

    fgets(input, sizeof(input), stdin);

    // Analyse de l'entrer
    sscanf(input, "%d/%d/%d %d:%d", &dt->day, &dt->month, &dt->year, &dt->hour, &dt->minute);

}

// yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy
void convertir(char *chaine ) {
    for (int i = 0; chaine[i] != '\0'; i++) {
            chaine[i] = tolower(chaine[i]); // Convertir en minuscule
    }
}
// yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy
t_d_contact *create_contact(void) {
    t_d_contact *new_contact = (t_d_contact *)malloc(sizeof(t_d_contact));
    if (new_contact == NULL) {
        printf("t'a pas de memoire dans ton pc la hont");
        return NULL;
    }

    printf("Enter surname:");
    new_contact->surname = scanString();
    convertir(new_contact->surname);
    if (new_contact->surname == NULL) {
        free(new_contact);
        return NULL;
    }

    printf("Enter firstname:");
    new_contact->firstname = scanString();
    convertir(new_contact->firstname);
    if (new_contact->firstname == NULL) {
        free(new_contact->surname);
        free(new_contact);
        return NULL;
    }

    new_contact->appointments = NULL;
    new_contact->levels=0;

    return new_contact;
}
// yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy
appointment *creat_apointem (void){

    appointment *new_appointment = (appointment *)malloc(sizeof(appointment));

    printf("Description of the appointment (max1024 character):");
    new_appointment->purpose= scanString();
    if (new_appointment->purpose == NULL) {
        free(new_appointment->purpose);
    }

    printf("when does it begin:\n");
    DateTime *dt = NULL;
    scanDate(dt);
    new_appointment->start_time = dt;

    printf("when does it ends:\n");

    scanDate(dt);
    new_appointment->duration= dt;

    new_appointment->next = NULL;

    return new_appointment;
}
// yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy

void view_apo(t_d_contact *cont){

    appointment *apo = cont->appointments ;
    while (apo != NULL){
        printf("\n\n\nThe next appointment will take place in the :%d/%d/%d",apo->start_time->day,apo->start_time->month,apo->start_time->year);
        printf("\nAnd its will last forme %d:%d to %d:%d",apo->start_time->hour,apo->start_time->minute,apo->duration->hour,apo->duration->minute);
        printf("\n\nThe appointment is :%s",apo->purpose);
        printf("\n\n----------------------------------------------------------------------------------------------\n");
        apo = apo->next;
    }


}