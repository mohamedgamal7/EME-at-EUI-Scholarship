// standard libraries
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// user defined libraries
#include "Bit_math.h"
#include "types.h"

// courses and stdmngmt headers
#include "courses.h"
#include "studentMngmt.h"

bool_t check_name(u8 *name)
{
    u32 length = strlen(name);
    u8 spaceCount = 0;
    bool_t foundFirstName = false;
    bool_t foundSecondName = false;

    for (int i = 0; i < length; i++)
    {

        if (name[i] == ' ')
        {
            spaceCount++;
            if (spaceCount > 1)
            {
                return false; // More than one space, not two words
            }
        }
        // Check for special characters except space
        else if (!isalpha(name[i]) && !isspace(name[i]))
        {
            return false; // Special characters are not allowed
        }
        // Check if a second name is encountered after the first name
        else if (foundFirstName && isalpha(name[i]))
        {
            foundSecondName = true; // Mark the second name as found
        }
        else
        {
            foundFirstName = true; // Mark the first name as found
        }
    }

    // Return true if exactly one space is found and both first and second names are found
    return (spaceCount == 1 && foundFirstName && foundSecondName) ? (true) : (false);
}

bool_t check_grade(f32 Grade)
{
    // Check if the grade is within the valid range (0.0 to 4.0)
    if (Grade > 0.0 && Grade <= 4.0 + 0.0001) // Adding a small tolerance for precision
    {
        return true; // Grade is valid
    }
    else
    {
        return false; // Grade is not valid
    }
}

f32 calculate_GPA(SstudentsPtr_t *head)
{
    f32 GPA = 0;    // Initialize GPA accumulator
    u8 counter = 0; // Initialize counter for enrolled courses

    // Loop through the courses (assuming a maximum of 3)
    for (u8 i = 0; i < 3; i++)
    {
        // Check if the student is enrolled in the current course
        if (GET_BIT(((*head)->enrolled_courses), i) == 1)
        {
            GPA += (*head)->Grades[i]; // Add the grade to the GPA
            counter++;                 // Increment the counter
        }
    }

    // Calculate the GPA by dividing the total grade by the number of enrolled courses
    return (counter != 0) ? (GPA / counter) : (0.0);
}

bool_t check_Id(u8 *Id)
{
    // Check if the ID has exactly 7 characters
    if (strlen(Id) == 7)
    {
        if (!strcmp(Id, "0000000")) // ID zero is not acceptable
        {

            return false;
        }
        // Loop through each character in the ID
        for (int i = 0; i < 7; ++i)
        {
            // Check if digits are numeric
            if (Id[0] != '0' && Id[i] >= '0' && Id[i] <= '9')
            {
                continue; // Digit is valid, continue to the next iteration
            }
            else
            {
                return false; // Invalid digit found, return false
            }
        }
    }
    else
    {
        return false; // ID length is not 7, return false
    }

    return true; // All conditions are satisfied, ID is valid
}

bool_t check_Id_uniqueness(u32 *Id, SstudentsPtr_t *head)
{
    // If the linked list is empty, IDs are unique
    if (*head == NULL)
    {
        return true;
    }

    SstudentsPtr_t current = *head; // Initialize a pointer to traverse the linked list

    // Traverse the linked list to check for duplicate IDs
    while (current != NULL)
    {
        if (current->Id == *Id) // Compare the ID with the current student's ID
        {
            return false; // Found a duplicate ID, return false
        }
        current = current->link; // Move to the next student in the list
    }

    return true; // No duplicate IDs found, return true
}

bool_t check_gender(EGender_t gender)
{
    // Check if the gender is either Male or Female
    if (gender == Male || gender == Female)
    {
        return true; // Gender is valid
    }
    else
    {
        return false; // Gender is not valid
    }
}

bool_t check_year(u8 academic_year)
{
    // Check if the academic year is within the valid range
    return (academic_year > 0 && academic_year <= MAX_YEAR_ACADEMIC) ? (true) : (false);
}

bool_t check_courseId(u8 *course_Id)
{
    // Check if the course ID has exactly 3 characters
    if (strlen(course_Id) == 3)
    {
        // Check if the first character is a letter (uppercase or lowercase)
        if (!((course_Id[0] >= 'a' && course_Id[0] <= 'z') || (course_Id[0] >= 'A' && course_Id[0] <= 'Z')))
        {
            return false; // First character is not a letter, return false
        }

        // Loop through the remaining characters in the course ID
        for (u8 i = 1; i < 3; i++)
        {
            // Check if each character is a digit
            if (!((course_Id[i] >= '0' && course_Id[i] <= '9')))
            {
                return false; // Character is not a digit, return false
            }
        }
    }
    else
    {
        return false; // Course ID length is not 3, return false
    }

    return true; // All conditions are satisfied, course ID is valid
}

void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        // Consume characters from the buffer
    }
}

void instructions(void) // Instruct the user how to use the DBMngmt system
{
    puts("                  \n"
         " Enter your choice:\n"
         " 1 - To add a student into the DataBase.\n"
         " 2 - To remove a student from the DataBase.\n"
         " 3 - To search for a student in the DataBase and Display all his information.\n"
         " 4 - To Enroll a new course.\n"
         " 5 - To end.\n");
}

void GetStringinput(u8 *prompt, u8 *temp_Id, bool_t (*PtrFunction)(u8 *))
{
    clearInputBuffer(); // Clear any remaining input from the buffer

    // Prompt the user and read input until a newline character is encountered
    scanf("%[^\n]", temp_Id);

    // Check if the provided input satisfies the validation function
    if (!PtrFunction(temp_Id))
    {
        // Loop until valid input is provided
        while (!PtrFunction(temp_Id))
        {
            printf("%s\n", prompt);   // Display the prompt for user input
            clearInputBuffer();       // Clear any remaining input from the buffer
            scanf("%[^\n]", temp_Id); // Read input until a newline character is encountered
        }
    }
}

void PrintStudentdata(SstudentsPtr_t *studentPtr)
{
    // Print basic student information
    printf("The data of the student with the provided Id is:\n");
    printf("Name: %s\n", (*studentPtr)->name);
    printf("Id: %d\n", (*studentPtr)->Id);

    // Print gender based on the enumeration value
    printf("Gender: %s\n", ((*studentPtr)->student_Gender == Female) ? "Female" : "Male");

    printf("Academic year: %hhu\n", (*studentPtr)->academic_year);

    // Print GPA if available, otherwise print "None"
    if ((*studentPtr)->GPA < 0)
    {
        printf("GPA: None\n");
    }
    else
    {
        printf("GPA: %.2f\n", (*studentPtr)->GPA); // Use "%.2f" to show GPA with 2 decimal places
    }

    // Check if the student is enrolled in any courses
    if ((*studentPtr)->enrolled_courses == 0)
    {
        printf("Enrolled courses: None\n");
    }
    else
    {
        printf("Enrolled courses:\n");

        // Loop through each course and print details for enrolled courses
        for (u8 i = 0; i < NUM_COURSES; i++) // Use NUM_COURSES instead of hardcoded value
        {
            // Check if the student is enrolled in the current course
            if (GET_BIT((*studentPtr)->enrolled_courses, i) == 1)
            {
                // Print course details and grade
                printf("Course: %s (ID: %s, Credits: %hhu)\n", courses[i].name, courses[i].Id, courses[i].credit_hours);
                printf("Grade in %s: %.1f\n", courses[i].name, (*studentPtr)->Grades[i]);
            }
        }
    }
}

void AddStudent(SstudentsPtr_t *head)
{
    // Allocate memory for a new student
    Sstudents_t *new_student = malloc(sizeof(Sstudents_t));
    if (new_student == NULL)
    {
        printf("Memory allocation for the new student failed..\n");
        return;
    }

    // Prompt and get student's name
    printf("Please enter the first and second name of the student separated by a single space:\n");
    u8 temp_name[MAX_NAME_SIZE];
    u8 *name_prompt = "Please enter a correct student name";
    GetStringinput(name_prompt, temp_name, check_name);
    strcpy(new_student->name, temp_name);

    // Prompt and get student's ID
    printf("Please enter the student ID (it should be a unique 7-digit number):\n");
    u8 temp_Id[MAX_TEMP_ID_ENTERED];
    u8 *Id_prompt = "Please enter a correct student ID";
    GetStringinput(Id_prompt, temp_Id, check_Id);

    u32 u32_temp_Id = atoi(temp_Id);
    if (!check_Id_uniqueness(&u32_temp_Id, head))
    {
        while (!check_Id_uniqueness(&u32_temp_Id, head))
        {
            printf("The ID you entered is not unique, please enter another student ID:\n");
            clearInputBuffer();
            scanf("%[^\n]", temp_Id);
            u32_temp_Id = atoi(temp_Id);
        }
    }
    new_student->Id = u32_temp_Id;

    // Prompt and get student's gender
    printf("Please enter the student gender (0-> Male, 1-> Female):\n");
    EGender_t temp_Gender;
    s32 is_successful = scanf("%d", &temp_Gender);
    if (is_successful != 1 || !check_gender(temp_Gender))
    {
        while (is_successful != 1 || !check_gender(temp_Gender))
        {
            clearInputBuffer();
            printf("You entered a wrong number for gender, 0-> Male, 1-> Female:\n");
            is_successful = scanf("%d", &temp_Gender);
        }
    }

    // Prompt and get student's academic year
    printf("Please enter the academic year:\n");
    u8 temp_year;
    is_successful = scanf("%hhu", &temp_year);
    if (!check_year(temp_year))
    {
        while (!check_year(temp_year))
        {
            clearInputBuffer();
            printf("You entered a wrong year:\n");
            is_successful = scanf("%hhu", &temp_year);
        }
    }
    new_student->academic_year = temp_year;

    // Initialize enrolled courses to 0 and grades to -1
    new_student->enrolled_courses = 0;
    for (u8 i = 0; i < NUM_COURSES; i++)
    {
        new_student->Grades[i] = -1;
    }

    // Initialize GPA to -1.0

    new_student->GPA = -1.0;

    // Sorted insertion in the linked list
    if (*head == NULL || (*head)->Id > new_student->Id)
    {
        new_student->link = *head;
        *head = new_student;
    }
    else
    {
        SstudentsPtr_t current = *head;
        while (current->link != NULL && current->link->Id < new_student->Id)
        {
            current = current->link;
        }
        new_student->link = current->link;
        current->link = new_student;
    }

    printf("Student added successfully.\n");
}

void RemoveStudent(SstudentsPtr_t *head)
{
    // Prompt and get student's ID to be removed
    printf("Please enter the ID of the student to be removed:\n");
    u8 student_Id[MAX_TEMP_ID_ENTERED];
    u8 *Id_prompt = "Please enter a correct student ID";
    GetStringinput(Id_prompt, student_Id, check_Id);
    u32 student_Id_int = atoi(student_Id);

    // Check if the list is empty
    if (*head == NULL)
    {
        printf("Couldn't remove student, the Database is empty.\n");
        return;
    }
    // Check if the head node is the target to be removed
    else if ((*head)->Id == student_Id_int)
    {
        SstudentsPtr_t temp = *head;
        *head = (*head)->link;
        free(temp);
        printf("Student removed successfully.\n");
        return;
    }

    // Traverse the list to find the student with the provided ID
    SstudentsPtr_t previousPtr = *head;
    SstudentsPtr_t currentPtr = (*head)->link;
    SstudentsPtr_t temp;
    while (currentPtr != NULL && currentPtr->Id != student_Id_int)
    {
        previousPtr = currentPtr;
        currentPtr = currentPtr->link;
    }

    // Remove the student if found
    if (currentPtr != NULL)
    {
        temp = currentPtr;
        previousPtr->link = currentPtr->link;
        free(temp);
        printf("Student removed successfully.\n");
        return;
    }
    else
    {
        printf("Student not found in the Database.\n");
        return;
    }
}

SstudentsPtr_t SearchStudent(SstudentsPtr_t *head)
{
    // Prompt and get student's ID to be searched
    printf("Please enter the student ID to search for:\n");
    u8 student_Id[MAX_TEMP_ID_ENTERED];
    u8 *prompt = "Please enter a correct student ID";
    GetStringinput(prompt, student_Id, check_Id);
    u32 student_Id_int = atoi(student_Id);

    // Initialize the left and right pointers for binary search
    SstudentsPtr_t left = *head;
    SstudentsPtr_t right = NULL; // Not initialized for now

    // Perform binary search in the linked list
    while (left != right)
    {
        SstudentsPtr_t mid = left;
        int count = 0;
        while (mid != right)
        {
            mid = mid->link;
            count++;
        }
        int steps = count / 2;
        mid = left;
        for (int i = 0; i < steps; i++)
        {
            mid = mid->link;
        }
        if (mid->Id == student_Id_int)
        {
            return mid; // Student found
        }
        else if (mid->Id < student_Id_int)
        {
            left = mid->link;
        }
        else
        {
            right = mid;
        }
    }

    return NULL; // Student not found
}

EnrollCheck_t EnrollCourse(SstudentsPtr_t *head)
{
    SstudentsPtr_t student;

    // Prompt and get the desired course ID
    printf("Please enter the course ID of the desired course:\n");
    u8 *prompt = "Please enter a correct course ID format starting with a letter and followed by two numbers (e.g., A32, E03, F43)";
    u8 course_Id[MAX_ID_DIGITS];
    GetStringinput(prompt, course_Id, check_courseId);

    // Iterate through available courses to find the selected one
    for (u8 i = 0; i < NUM_COURSES; i++)
    {
        if (!strcmp(course_Id, courses[i].Id))
        {
            // Search for student
            student = SearchStudent(head);
            if ((student) != NULL) // Student found in DB
            {
                f32 temp_Grade;
                printf("Please enter your grade in the selected course:\n");
                s32 is_successful = scanf("%f", &temp_Grade);
                if (is_successful != 1 || !check_grade(temp_Grade))
                {
                    while (is_successful != 1 || !check_grade(temp_Grade))
                    {
                        clearInputBuffer();
                        printf("You entered a wrong grade. Grades are from 0 to 4:\n");
                        is_successful = scanf("%f", &temp_Grade);
                    }
                }

                // Enroll the student and update grades
                SET_BIT((student)->enrolled_courses, i);
                (student)->Grades[i] = temp_Grade;
                student->GPA = calculate_GPA(&student);

                return Enrolled; // Enrollment successful
            }
            else
            {
                printf("The provided Student ID is not in the database.\n");
                return NotEnrolled; // Enrollment failed
            }
        }
    }

    printf("The provided course ID is not in the list of available courses.\n");
    return NotEnrolled; // Enrollment failed
}