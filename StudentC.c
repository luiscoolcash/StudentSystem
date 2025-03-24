/*
INSTRUCTIONS---------

Create a program that manages a dynamic array of student records using pointers and malloc
Define a struct called Student with:

1.   A char array for name
     An integer for ID
     A float for GPA


2. Write a function to dynamically allocate memory for an array of Student structures.
3. Write a function to add a new student to the array (reallocating memory as needed).
4. Write a function to display all students.
5. Write a function to search for a student by ID.
6. Write a function to free all allocated memory.
7. In your main function, demonstrate all these operations.

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 50
typedef struct //defining a struct called student
{
    char name[MAX]; 
    int id;
    float gpa;
}Student; 

// function to initialize the student array (Creating a student)
Student *initializeStudentArray(int intitialSize);

// function to add a new student to the array
Student *addStudent(Student *students, int *currentSize, int *capacity, Student newStudent);

// function to display all students
void displayStudents(Student *students, int size);


int main(void)
{
    
    int capacity = 2; //initial capacity of the array
    int size = 0; 
    int choice, searchId;
    Student newStudent, *foundStudent; //*foundStudent is a pointer to a student

    Student *studentArray = initializeStudentArray(capacity); //creating a student array
    printf("Student management system initialized with capacity: %d\n", capacity);

    // Menu-driven program
    do
    {
        printf("\n----- Student Management System -----\n");
        printf("1. Add a new student\n");
        printf("2. Display all students\n");
        printf("3. Search for a student by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice:  ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                // Get student details
                printf("Enter student name:  "); 
                scanf(" %[^\n]", newStudent.name); //%[^\n] is used to read a string with spaces

                printf("Enter student ID:  ");
                scanf("%d", &newStudent.id);

                printf("Enter atudent GPA:  ");
                scanf("%f", &newStudent.gpa);

                // Add student to the array
                studentArray = addStudent(studentArray, &size, &capacity, newStudent);
                printf("Student added sucessfully.\n");
                break;

            case 2: 
                //Display all students
                //displayStudent(studentArray, size);

            case 3:


        
                
        }

    } while (choice != 4);

}

// function to initialize the student array (Creating a student)
Student *initializeStudentArray(int intitialSize)
{
    Student *students = (Student*)malloc(intitialSize * sizeof(Student));

    if (students == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1); //exiting the program if memory allocation fails
    }
    
    return students; // Return the array we created
}

// function to add a new student to the array
Student *addStudent(Student *students, int *currentSize, int *capacity, Student newStudent)
{
    //check if the array is full to reize the array
    if(*currentSize >= *capacity)
    {
        int newCapacity = *capacity * 2; //double the capacity 

        //reallocating memory to the new capacity
        Student* temp = (Student*)realloc(students, newCapacity * sizeof(Student));

        if(temp == NULL) //check if the memory reallocation failed
        {
            printf("Memory reallocation failed!\n");
            return students;
        }

        students = temp; //updating the pointer to the new array
        *capacity = newCapacity; //updating the capacity
        printf("Array resized to capacity: %d\n", *capacity);
    }

    students[*currentSize] = newStudent; //adding the new student to the array
    (*currentSize)++; //incrementing the current size

    return students; 
}

// function to display all students
void displayStudents(Student *students, int size)
{
    printf("\n---- Student Records (%d total) ----\n", size);

    if(size == 0)
    {
        printf("No students in database.\n");
        return;
    }

    for(int i = 0; i < size; i++)
    {
        printf("Student %d:\n", i + 1);
        printf("  Name: %s\n", students[i].name); 
        printf("  ID: %d\n", students[i].id);
        printf("  GPA: %.2f", students[i].gpa);
        printf("\n");
    }

// TEST
// test commit
// test commit 2

}
