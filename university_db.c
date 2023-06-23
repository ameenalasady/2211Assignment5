#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "university_db.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "university_db.h"

int main()
{
    // Continuously prompt the user for a command
    char command;
    do
    {
        printf("\nEnter command (h - help, q - quit, c - control classes, s - control students): ");
        scanf(" %c", &command);

        // Handle the entered command
        switch (command)
        {
        case 'h':
            print_help();
            break;
        case 'q':
            break;
        case 'c':
            control_classes();
            break;
        case 's':
            control_students();
            break;
        default:
            printf("Error: Invalid command\n");
        }
    } while (command != 'q');

    return 0;
}

void print_help()
{
    // Print a list of available commands
    printf("\nCommands:\n");
    printf("h - Print help\n");
    printf("q - Quit\n");
    printf("c - Control classes\n");
    printf("s - Control students\n");
}

void control_classes()
{
    // Continuously prompt the user for a command
    char command;
    do
    {
        printf("\nEnter command (i - insert, s - search and print, u - update, p - print all, e - erase, q - quit): ");
        scanf(" %c", &command);

        // Handle the entered command
        switch (command)
        {
        case 'i':
            insert_class();
            break;
        case 's':
            search_and_print_class();
            break;
        case 'u':
            update_class();
            break;
        case 'p':
            print_all_class();
            break;
        case 'e':
            erase_class();
            break;
        case 'q':
            break;
        default:
            printf("Error: Invalid command\n");
        }
    } while (command != 'q');
}

void control_students()
{
    // Continuously prompt the user for a command
    char command;
    do
    {
        printf("\nEnter command (i - insert, s - search and print, u - update, p - print all, e - erase, q - quit): ");
        scanf(" %c", &command);

        // Handle the entered command
        switch (command)
        {
        case 'i':
            insert_student();
            break;
        case 's':
            search_and_print_student();
            break;
        case 'u':
            update_student();
            break;
        case 'p':
            print_all_student();
            break;
        case 'e':
            erase_student();
            break;
        case 'q':
            break;
        default:
            printf("Error: Invalid command\n");
        }
    } while (command != 'q');
}
