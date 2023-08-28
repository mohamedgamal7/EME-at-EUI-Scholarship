#ifndef STUDENT_H_
#define STUDENT_H_

// Define maximum values for student ID digits, name size, and academic years
#define MAX_ID_DIGITS 7
#define MAX_NAME_SIZE 100
#define MAX_TEMP_ID_ENTERED 100
#define MAX_YEAR_ACADEMIC 5

// External reference to the 'courses' array from 'courses.h'
extern Scourses_t courses[NUM_COURSES];

// Enumeration for student gender
typedef enum
{
    Male,
    Female
} EGender_t;

// Enumeration for boolean values
typedef enum
{
    false,
    true
} bool_t;

// Enumeration for enrollment status
typedef enum
{
    Enrolled,
    NotEnrolled
} EnrollCheck_t;

// Enumeration for choices
typedef enum
{
    Add = 1,
    Remove,
    Search,
    Enroll,
    End
} Choices_t;

// Structure to represent student data
struct Sstudents
{
    char name[MAX_NAME_SIZE];          // Student name (100 bytes)
    f32 Grades[NUM_COURSES];           // Grades for enrolled courses (12 bytes)
    u32 Id;                            // Student ID (4 bytes)
    f32 GPA;                           // Grade Point Average of the student (4 bytes)
    EGender_t student_Gender;          // Gender of the student (4 bytes)
    struct Sstudents *link;            // Pointer to the next student (4 bytes)
    u8 enrolled_courses : NUM_COURSES; // Number of enrolled courses (1 byte)
    u8 academic_year;                  // Academic year of the student (1 byte)
};

// Typedef for struct Sstudents
typedef struct Sstudents Sstudents_t;

// Typedef for a pointer to Sstudents_t
typedef Sstudents_t *SstudentsPtr_t;

// Function prototypes
void AddStudent(SstudentsPtr_t *head);                                     // Add a student to the list
void RemoveStudent(SstudentsPtr_t *head);                                  // Remove a student from the list
void instructions(void);                                                   // Instruct the user how to use the DBMngmt system
void PrintStudentdata(SstudentsPtr_t *studentPtr);                         // Prints all the data related to the student
void clearInputBuffer();                                                   // clear input buffer for scanf
void GetStringinput(u8 *prompt, u8 *temp_Id, bool_t (*PtrFunction)(u8 *)); // A helper function to get string input from user and avoid overflows
SstudentsPtr_t SearchStudent(SstudentsPtr_t *head);                        // Search for a student by ID
EnrollCheck_t EnrollCourse(SstudentsPtr_t *head);                          // Enroll a student in a course

bool_t check_name(u8 *name);                               // Check the validity of a student name
bool_t check_Id(u8 *Id);                                   // Check the validity of a student ID
bool_t check_Id_uniqueness(u32 *Id, SstudentsPtr_t *head); // Check if a student ID is unique
bool_t check_year(u8 academic_year);                       // Check if the entered year is a valid academic year
bool_t check_gender(EGender_t gender);                     // Check that the student gender is a valid choice
f32 calculate_GPA(SstudentsPtr_t *head);                   // calculate student GPA based on enrolled courses

#endif /*STUDENT_H_*/