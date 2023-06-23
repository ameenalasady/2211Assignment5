#ifndef UNIVERSITY_CLASSES_H
#define UNIVERSITY_CLASSES_H

// Define the Class structure
typedef struct class
{
    int class_code;
    char class_name[101];
    int max_class_size;
    char day_of_week[4];
    int time;
    struct class *next;
} Class;

// Declare the class_head variable as extern
extern Class *class_head;

// Function prototypes for the class-related functions
void insert_class();
void search_and_print_class();
void update_class();
void print_all_class();
void erase_class();

#endif
