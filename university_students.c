#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "university_students.h"

Student *student_head = NULL;

void insert_student()
{
    // Allocate memory for a new student
    Student *new_student = (Student *)malloc(sizeof(Student));
    if (new_student == NULL)
    {
        printf("Error: Memory allocation failed\n");
        return;
    }

    // Prompt the user for the student number
    printf("Enter student number: ");
    scanf("%d", &new_student->student_number);
    // Check if the student number is valid
    if (new_student->student_number < 251000000 || new_student->student_number > 251999999)
    {
        printf("Error: Invalid student number\n");
        free(new_student);
        return;
    }

    // Check if the student number already exists
    Student *current = student_head;
    while (current != NULL)
    {
        if (current->student_number == new_student->student_number)
        {
            printf("Error: Student number already exists\n");
            free(new_student);
            return;
        }
        current = current->next;
    }

    // Prompt the user for the student name
    printf("Enter student name: ");
    scanf(" %[^\n]s", new_student->student_name);

    // Prompt the user for the student age
    printf("Enter student age: ");
    scanf("%d", &new_student->student_age);
    // Check if the student age is valid
    if (new_student->student_age < 18 || new_student->student_age > 99)
    {
        printf("Error: Invalid student age\n");
        free(new_student);
        return;
    }

    // Prompt the user for the home department
    printf("Enter home department: ");
    scanf(" %[^\n]s", new_student->home_department);

    // Add the new student to the linked list
    new_student->next = student_head;
    student_head = new_student;

    printf("Student added successfully\n");
}

void search_and_print_student()
{
    // Prompt the user for the student number
    int number;
    printf("Enter student number: ");
    scanf("%d", &number);

    // Search for the student in the linked list
    Student *current = student_head;
    while (current != NULL)
    {
        if (current->student_number == number)
        {
            // If the student is found, print their information
            printf("\nStudent Number: %d\n", current->student_number);
            printf("Student Name: %s\n", current->student_name);
            printf("Student Age: %d\n", current->student_age);
            printf("Home Department: %s\n", current->home_department);
            return;
        }
        current = current->next;
    }

    // If the student is not found, print an error message
    printf("Error: Student not found\n");
}

void update_student()
{
    // Prompt the user for the student number
    int number;
    printf("Enter student number: ");
    scanf("%d", &number);

    // Search for the student in the linked list
    Student *current = student_head;
    while (current != NULL)
    {
        if (current->student_number == number)
        {
            // If the student is found, prompt the user to update their information
            printf("Enter new student name: ");
            scanf(" %[^\n]s", current->student_name);

            printf("Enter new student age: ");
            scanf("%d", &current->student_age);
            // Check if the new student age is valid
            if (current->student_age < 18 || current->student_age > 99)
            {
                printf("Error: Invalid student age\n");
                return;
            }

            printf("Enter new home department: ");
            scanf(" %[^\n]s", current->home_department);

            printf("Student updated successfully\n");
            return;
        }
        current = current->next;
    }

    // If the student is not found, print an error message
    printf("Error: Student not found\n");
}

void print_all_student()
{
    // Iterate over the linked list of students
    Student *current = student_head;
    while (current != NULL)
    {
        // Print the information for each student
        printf("\nStudent Number: %d\n", current->student_number);
        printf("Student Name: %s\n", current->student_name);
        printf("Student Age: %d\n", current->student_age);
        printf("Home Department: %s\n", current->home_department);
        current = current->next;
    }
}

void erase_student()
{
    // Prompt the user for the student number
    int number;
    printf("Enter student number: ");
    scanf("%d", &number);

    // Search for the student in the linked list
    Student *current = student_head;
    Student *prev = NULL;
    while (current != NULL)
    {
        if (current->student_number == number)
        {
            // If the student is found, remove them from the linked list
            if (prev == NULL)
            {
                student_head = current->next;
            }
            else
            {
                prev->next = current->next;
            }
            free(current);
            printf("Student erased successfully\n");
            return;
        }
        prev = current;
        current = current->next;
    }

    // If the student is not found, print an error message
    printf("Error: Student not found\n");
}
