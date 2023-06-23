#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "university_classes.h"

// Define the class_head variable
Class *class_head = NULL;
void insert_class()
{
    // Allocate memory for a new class
    Class *new_class = (Class *)malloc(sizeof(Class));
    if (new_class == NULL)
    {
        printf("Error: Memory allocation failed\n");
        return;
    }

    // Prompt the user for the class code
    printf("Enter class code: ");
    scanf("%d", &new_class->class_code);
    // Check if the class code is valid
    if (new_class->class_code < 0 || new_class->class_code > 999)
    {
        printf("Error: Invalid class code\n");
        free(new_class);
        return;
    }

    // Check if the class code already exists
    Class *current = class_head;
    while (current != NULL)
    {
        if (current->class_code == new_class->class_code)
        {
            printf("Error: Class code already exists\n");
            free(new_class);
            return;
        }
        current = current->next;
    }

    // Prompt the user for the class name
    printf("Enter class name: ");
    scanf(" %[^\n]s", new_class->class_name);

    // Prompt the user for the maximum class size
    printf("Enter maximum class size: ");
    scanf("%d", &new_class->max_class_size);
    // Check if the maximum class size is valid
    if (new_class->max_class_size < 10 || new_class->max_class_size > 500)
    {
        printf("Error: Invalid maximum class size\n");
        free(new_class);
        return;
    }

    // Prompt the user for the day of the week
    printf("Enter day of the week: ");
    scanf("%s", new_class->day_of_week);
    // Check if the day of the week is valid
    if (strcmp(new_class->day_of_week, "Mon") != 0 && strcmp(new_class->day_of_week, "Tue") != 0 && strcmp(new_class->day_of_week, "Wed") != 0 && strcmp(new_class->day_of_week, "Thu") != 0 && strcmp(new_class->day_of_week, "Fri") != 0)
    {
        printf("Error: Invalid day of the week\n");
        free(new_class);
        return;
    }

    // Prompt the user for the time of day
    printf("Enter time of day: ");
    scanf("%d", &new_class->time);
    // Check if the time of day is valid
    if (new_class->time != 1 && new_class->time != 2 && new_class->time != 3 && new_class->time != 4 && new_class->time != 9 && new_class->time != 10 && new_class->time != 11 && new_class->time != 12)
    {
        printf("Error: Invalid time of day\n");
        free(new_class);
        return;
    }

    // Add the new class to the linked list
    new_class->next = class_head;
    class_head = new_class;

    printf("Class added successfully\n");
}

void search_and_print_class()
{
    // Prompt the user for the class code
    int code;
    printf("Enter class code: ");
    scanf("%d", &code);

    // Search for the class in the linked list
    Class *current = class_head;
    while (current != NULL)
    {
        if (current->class_code == code)
        {
            // If the class is found, print its information
            printf("\nClass Code: %d\n", current->class_code);
            printf("Class Name: %s\n", current->class_name);
            printf("Maximum Class Size: %d\n", current->max_class_size);
            printf("Class Day: %s\n", current->day_of_week);
            printf("Class Time: %d\n", current->time);
            return;
        }
        current = current->next;
    }

    // If the class is not found, print an error message
    printf("Error: Class not found\n");
}

void update_class()
{
    // Prompt the user for the class code
    int code;
    printf("Enter class code: ");
    scanf("%d", &code);

    // Search for the class in the linked list
    Class *current = class_head;
    while (current != NULL)
    {
        if (current->class_code == code)
        {
            // If the class is found, prompt the user to update its information
            printf("Enter new class name: ");
            scanf(" %[^\n]s", current->class_name);

            printf("Enter new maximum class size: ");
            scanf("%d", &current->max_class_size);
            // Check if the new maximum class size is valid
            if (current->max_class_size < 10 || current->max_class_size > 500)
            {
                printf("Error: Invalid maximum class size\n");
                return;
            }

            printf("Enter new day of the week: ");
            scanf("%s", current->day_of_week);
            // Check if the new day of the week is valid
            if (strcmp(current->day_of_week, "Mon") != 0 && strcmp(current->day_of_week, "Tue") != 0 && strcmp(current->day_of_week, "Wed") != 0 && strcmp(current->day_of_week, "Thu") != 0 && strcmp(current->day_of_week, "Fri") != 0)
            {
                printf("Error: Invalid day of the week\n");
                return;
            }

            printf("Enter new time of day: ");
            scanf("%d", &current->time);
            // Check if the new time of day is valid
            if (current->time != 1 && current->time != 2 && current->time != 3 && current->time != 4 && current->time != 9 && current->time != 10 && current->time != 11 && current->time != 12)
            {
                printf("Error: Invalid time of day\n");
                return;
            }

            printf("Class updated successfully\n");
            return;
        }
        current = current->next;
    }

    // If the class is not found, print an error message
    printf("Error: Class not found\n");
}

void print_all_class()
{
    // Iterate over the linked list of classes
    Class *current = class_head;
    while (current != NULL)
    {
        // Print the information for each class
        printf("\nClass Code: %d\n", current->class_code);
        printf("Class Name: %s\n", current->class_name);
        printf("Maximum Class Size: %d\n", current->max_class_size);
        printf("Class Day: %s\n", current->day_of_week);
        printf("Class Time: %d\n", current->time);
        current = current->next;
    }
}

void erase_class()
{
    // Prompt the user for the class code
    int code;
    printf("Enter class code: ");
    scanf("%d", &code);

    // Search for the class in the linked list
    Class *current = class_head;
    Class *prev = NULL;
    while (current != NULL)
    {
        if (current->class_code == code)
        {
            // If the class is found, remove it from the linked list
            if (prev == NULL)
            {
                class_head = current->next;
            }
            else
            {
                prev->next = current->next;
            }
            free(current);
            printf("Class erased successfully\n");
            return;
        }
        prev = current;
        current = current->next;
    }

    // If the class is not found, print an error message
    printf("Error: Class not found\n");
}
