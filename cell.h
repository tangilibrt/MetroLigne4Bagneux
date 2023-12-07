#ifndef PROJECT_DIARY_MANAGEMENT_CELL_H
#define PROJECT_DIARY_MANAGEMENT_CELL_H



typedef struct s_d_cell {
    int value;
    int levels;
    struct s_d_cell **next; // array de pointer
} t_d_cell;


t_d_cell *create_cell(int value, int levels);

#endif //PROJECT_DIARY_MANAGEMENT_CELL_H
