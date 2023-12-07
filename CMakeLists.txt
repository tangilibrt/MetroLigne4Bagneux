cmake_minimum_required(VERSION 3.24)
project(Project_Diary_management C)

set(CMAKE_C_STANDARD 11)

add_executable(Project_Diary_management main.c "cell.h" "cell.c" level_list.h level_list.c Diary.c Diary.h contact.c contact.h)
