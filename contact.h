#ifndef PROJECT_DIARY_MANAGEMENT_CONTACT_H
#define PROJECT_DIARY_MANAGEMENT_CONTACT_H

typedef struct {
    int day;
    int month;
    int year;
    int hour;
    int minute;
} DateTime;

typedef struct s_appointment {
    DateTime *start_time;
    DateTime *duration;
    char *purpose;
    struct s_appointment *next;
} appointment;


typedef struct s_d_contact{
    char *surname;
    char *firstname;
    int levels ;
    struct s_d_contact **next; // array de pointer
    appointment *appointments;
} t_d_contact;

char *scanString(void);
t_d_contact *create_contact(void);
appointment *creat_apointem (void);
void scanDate(DateTime *dt);
void convertir(char *chaine );
void view_apo(t_d_contact *cont);

#endif //PROJECT_DIARY_MANAGEMENT_CONTACT_H
