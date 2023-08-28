# Student Database Management System 👩‍🎓📚

Welcome to the **Student Database Management System** project repository! This project is a C programming implementation of a system that allows you to manage student records within a database. With features such as adding, deleting, searching for students, and enrolling in courses, this project streamlines student information management efficiently.

## Features

### 🌟 Add Student
Functionality to add a new student to the database with unique attributes:
- Name: Full name of the student (avoiding special characters).
- Gender: Male or Female.
- ID: Unique identifier for each student (7 digits starting with 1000000).
- Academic Year: The academic year the student is currently enrolled in.

### ❌ Delete Student
Capability to remove a student from the database based on their ID. This function helps maintain an updated and accurate student list.

### 🔍 Search Student
Function to search for a specific student using their ID. This aids in quickly accessing a student's information from the database.

### 📚 Enroll Course
Enables students to enroll in available courses within the database. The courses provide additional information, such as the course name, instructor, and schedule.

## Handling Wrong User Input 🚫

The Student Database Management System is designed to handle incorrect user input effectively:
- **Name Validation**: Special characters and invalid inputs are detected and rejected to ensure accurate and meaningful student records.
- **ID Uniqueness**: The system ensures that student IDs are unique and follow the required format (7 digits starting with 1000000).
- **Academic Year Validation**: The system verifies the academic year input to prevent incorrect data entry.

## How to Use

1. Clone this repository to your local machine.

2. Compile the C source code using a C compiler. For example, using GCC:
   ```sh
   gcc *.c  -o studentMngmt.exe