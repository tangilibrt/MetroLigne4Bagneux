#include "cell.h"
#include "level_list.h"
#include <malloc.h>
#include <stdio.h>
#include <time.h>
#include "contact.h"
int main() {
    t_d_contact *contact1 = create_contact();
    printf("nom = %s \nprenom = %s\n",contact1->surname, contact1->firstname);
    appointment *test_entretien = creat_apointem();
    contact1->appointments[0] = test_entretien;
    printf(" march ici 1");
    view_apo(contact1);

    return 0;
}
