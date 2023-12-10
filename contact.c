#include "contact.h"
#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

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


int isValidDate(DateTime *dt) {
    // Vérifier l'année
    if (dt->year < 1900 || dt->year > 2100) {
        return 0;
    }

    // Vérifier le mois
    if (dt->month < 1 || dt->month > 12) {
        return 0;
    }

    // Vérifier le jour
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // Vérifier les années bissextiles pour février
    if (dt->month == 2 && (dt->year % 4 == 0 && (dt->year % 100 != 0 || dt->year % 400 == 0))) {
        daysInMonth[1] = 29;
    }

    if (dt->day < 1 || dt->day > daysInMonth[dt->month - 1]) {
        return 0;
    }

    // Vérifier l'heure
    if (dt->hour < 0 || dt->hour > 23) {
        return 0;
    }

    // Vérifier les minutes
    if (dt->minute < 0 || dt->minute > 59) {
        return 0;
    }

    return 1;
}
// yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy




void scanDate(DateTime *dt) {


    char input[100];
    printf("Enter date and time (DD/MM/YYYY HH:MM): ");

    if (fgets(input, sizeof(input), stdin) == NULL) {
        printf("Error reading input.\n");
        return;
    }

    // Vérifier si le format est correct
    if (sscanf(input, "%d/%d/%d %d:%d", &dt->day, &dt->month, &dt->year, &dt->hour, &dt->minute) != 5) {
        printf("Invalid format.\n");
        return;
    }

    // Valider la date et l'heure
    if (!isValidDate(dt)) {
        printf("Invalid date or time.\n");
        return;
    }
    return;
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
    new_contact->levels=4;
    new_contact->next = (t_d_contact **)malloc(new_contact->levels * sizeof(t_d_contact *));

    new_contact->appointments = NULL;
    new_contact->next[0] = NULL;
    new_contact->next[1] = NULL;
    new_contact->next[2] = NULL;
    new_contact->next[3] = NULL;



    return new_contact;
}
// yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy
appointment *creat_apointem (void){

    appointment *new_appointment = (appointment *)malloc(sizeof(appointment));

    printf("Description of the appointement (max1024 carater):");
    new_appointment->purpose= scanString();
    if (new_appointment->purpose == NULL) {
        free(new_appointment->purpose);
    }

    printf("when dos it began:\n");
    DateTime *dt=(DateTime *)malloc(sizeof(DateTime));;
    scanDate(dt);

    new_appointment->start_time = dt;

    printf("when dos it end:\n");

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