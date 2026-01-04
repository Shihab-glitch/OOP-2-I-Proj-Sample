# Student Management System - OOP Project Sample

A comprehensive C++ Object-Oriented Programming (OOP) project demonstrating file handling, class implementation, and CRUD operations through a Student Management System.

## Project Overview

This project serves as a sample implementation for learning OOP concepts in C++. It provides a complete student records management system with persistent file storage, showcasing fundamental OOP principles including:
- Class design and encapsulation
- File I/O operations
- Data persistence
- Menu-driven user interface

## Features

The Student Management System supports the following operations:

1. **Add Student Record** - Create and save new student records with name, roll number, and marks in three subjects
2. **Display All Student Records** - View all stored student records
3. **Search Student Record** - Find and display a specific student by roll number
4. **Update Student Record** - Modify marks for an existing student
5. **Delete Student Record** - Remove a student record from the system
6. **Exit** - Close the application

## Project Structure

```
OOP-2-I-Proj-Sample/
├── OOP_G6_Sample_Proj.cpp    # Main source file with Student class and operations
├── README.md                  # This file
├── LICENSE                    # CC0 1.0 Universal License
└── students.txt               # Data file (created at runtime)
```

## Requirements

- C++ compiler with C++11 support or later (g++, clang++, MSVC, etc.)
- Standard C++ library

## Compilation

### Using g++:
```bash
g++ OOP_G6_Sample_Proj.cpp -o student_management
```

### Using clang++:
```bash
clang++ OOP_G6_Sample_Proj.cpp -o student_management
```

### Using MSVC (Windows):
```bash
cl OOP_G6_Sample_Proj.cpp
```

## Usage

1. Compile the program using one of the methods above
2. Run the executable:
   ```bash
   ./student_management          # On Linux/Mac
   student_management.exe        # On Windows
   ```
3. Follow the on-screen menu to perform operations

### Example Workflow

```
1. Add Student Record
2. Display All Student Records
3. Search Student Record
4. Update Student Record
5. Delete Student Record
6. Exit
Choose an option: 1

Enter name: John Doe
Enter roll number: 101
Enter marks in three subjects: 85 90 88
Record added successfully.
```

## Data Storage

Student records are stored in a text file named `students.txt` in the following format:
```
Student Name
Roll Number
Mark1 Mark2 Mark3
```

The file is automatically created when the first record is added and persists between program executions.

## Class Design

### Student Class
- **Private Members:**
  - `string name` - Student's name
  - `int rollNumber` - Unique roll number
  - `int marks[3]` - Marks in three subjects

- **Public Methods:**
  - `void input()` - Input student details from console
  - `void display() const` - Display student information
  - `int getRollNumber() const` - Get student's roll number
  - `void updateMarks()` - Update student's marks
  - `void writeToFile(ofstream&) const` - Write record to file
  - `bool readFromFile(ifstream&)` - Read record from file

## Learning Objectives

This project demonstrates:
- Class definition with private and public members
- Constructor initialization with member initializer lists
- Const correctness
- File handling with `ifstream` and `ofstream`
- Stream manipulation with `istringstream`
- Safe input handling with `getline` and `ws` manipulator
- File operations (create, read, update, delete)
- Menu-driven program design
- Error handling for file operations
