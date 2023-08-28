#include "types.h"   // Include the types header for data types
#include "courses.h" // Include the courses header for the Scourses_t structure and related constants

// Create an array of Scourses_t structures to represent courses
Scourses_t courses[NUM_COURSES] = {
    {"Circuits", "E01", 18}, // First course: Name = "circuits", Id = "E01", Credit Hours = 18
    {"MATHs", "E02", 20},    // Second course: Name = "MAths", Id = "E02", Credit Hours = 20
    {"Physics", "E03", 21}   // Third course: Name = "Physics", Id = "E03", Credit Hours = 21
};