#ifndef UNIVERSITY_STUDENTS_H
#define UNIVERSITY_STUDENTS_H

// Define the Student structure
typedef struct student
{
    int student_number;
    char student_name[51];
    int student_age;
    char home_department[51];
    struct student *next;
} Student;

// Declare the student_head variable as extern
extern Student *student_head;

// Function prototypes for the student-related functions
void insert_student();
void search_and_print_student();
void update_student();
void print_all_student();
void erase_student();

#endif
