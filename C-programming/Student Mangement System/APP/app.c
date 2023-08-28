
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "types.h"        // Include custom data type definitions
#include "courses.h"      // Include course-related data
#include "studentMngmt.h" // Include student management functions

int main()
{
    SstudentsPtr_t head = NULL; // Initialize the linked list of students

    u8 choice; // user's choice for what to do with the DataBase

    instructions(); // Display instructions for user interaction

    while (scanf("%hhu", &choice) != 1) // Used to avoid infinte loops with scanf on wrong choices
    {
        clearInputBuffer(); // Clear any remaining input
        instructions();     // Display instructions again due to invalid input
    }

    // Loop to repeatedly get user input and perform actions until the user chooses to end
    while (choice != End)
    {
        switch (choice)
        {
        case Add:
            AddStudent(&head); // Call function to add a student
            break;
        case Remove:
            RemoveStudent(&head); // Call function to remove a student
            break;
        case Search:
            // Call function to search for a student and display their data
            SstudentsPtr_t targetStudent = SearchStudent(&head);
            if (targetStudent == NULL)
            {
                printf("Student not found in the DataBase\n");
            }
            else
            {
                PrintStudentdata(&targetStudent);
            }
            break;
        case Enroll:
            EnrollCourse(&head); // Call function to enroll a student in a course
            break;
        case End:
            choice = End; // End the loop and program execution
            break;
        default:
            break;
        }

        instructions(); // Display instructions for user interaction

        while (scanf("%hhu", &choice) != 1) // To prevent infinite loops with scanf
        {
            clearInputBuffer(); // Clear any remaining input
            instructions();     // Display instructions again due to invalid input
        }
    }

    return 0;
}
