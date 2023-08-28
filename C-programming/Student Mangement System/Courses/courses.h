#ifndef COURSES_H_
#define COURSES_H_

// Define maximum length for course name and number of courses
#define MAX_NAME_SIZE 100
#define NUM_COURSES 3

// Define the structure for courses
typedef struct
{
    s8 name[MAX_NAME_SIZE]; // Name of the course (up to MAX_NAME_SIZE characters)
    u8 Id[4];               // Unique course identifier (4 bytes)
    u8 credit_hours;        // Number of credit hours for the course (1 bute)

} Scourses_t;

#endif /*COURSES_H_*/
