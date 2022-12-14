#ifndef ITERATOR_UTILITY_H
#define ITERATOR_UTILITY_H

// header files
#include <stdlib.h> // for malloc, free
#include <stdio.h>  // for printf
#include <math.h>   // for srand/rand
#include <time.h>   // for srand
#include "StandardConstants.h"

// structure definitions
typedef struct StudentStruct
   {
    char name[ STD_STR_LEN ];

    int studentId;

    char gender;

    double gpa;

    bool current;

    struct StudentStruct *nextPtr;

   } StudentType;

/*
Name: clearIterator
Process: recursively clears all data in iterator linked list, 
         returns memory to OS
Function input/parameters: working linked list pointer (StudentType *)
Function output/parameters: none
Function output/returned: NULL
Device input/file: none
Device output/monitor: none
Dependencies: free, clearIterator (recursive)
*/
StudentType *clearIterator( StudentType *wkgStudentPtr );

/*
Name: copyIterator
Process: creates new linked list with new nodes
         from given linked list, returns head pointer
Function input/parameters: source linked list head pointer (const StudentType *)
Function output/parameters: none
Function output/returned: destination linked list head pointer (StudentType *),
                          or NULL if source pointer is NULL
Device input/file: none
Device output/monitor: none
Dependencies: malloc, sizeof
*/
StudentType *copyIterator( const StudentType *studentHeadPtr );

/*
Name: copyIteratorString
Process: copies one string to another, assumes destination string
         has allocated memory
Function input/parameters: c-style source string (const char *)
Function output/parameters: c-style destination string (char *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: none
*/
void copyIteratorString( char *destStr, const char *sourceStr );

/*
Name: copyStudentData
Process: copies all parts of the student data, sets next pointer to NULL
Function input/parameters: source Student data (const StudentType)
Function output/parameters: destination Student data (StudentType *)
Function output/returned: none
Device input/file: none
Device output/monitor: none
Dependencies: copyIteratorString
*/
void copyStudentData( StudentType *destStudent, const StudentType srcStudent );

/*
Name: createStudentNodeFromStruct
Process: creates struct node,
         sets student struct to another StudentType struct,
         sets current Boolean to false, and nextPtr to NULL
Function input/parameters: student data from struct
Function output/parameters: none
Function output/returned: pointer to student data (StudentType *)
Device input/file: none
Device output/monitor: none
Dependencies: none
*/
StudentType *createStudentNodeFromStruct( StudentType studentData );

/*
Name: displayIterator
Process: displays iterator linked list if it is not empty,
         shows bottom to top of iterator data organization,
         if empty, displays "Iterator is empty - Display not conducted"
Function input/parameters: iterator linked list head pointer 
                           (StudentType *)
Function output/parameters: none
Function output/returned: none
Device input/file: none
Device output/monitor: none
Dependencies: printf, printIteratorChars
*/
void displayIterator( StudentType *wkgPtr );

/*
Name: getPtrBeforeCurrent
Process: finds pointer immediately prior to current node,
         if list is empty or first node is current, returns NULL,
         assumes list has valid current node
Function input/parameters: Iterator linked list head pointer 
                           (StudentType *)
Function output/parameters: none
Function output/returned: pointer to node prior to current (StudentType *)
Device input/file: none
Device output/monitor: none
Dependencies: none
*/
StudentType *getPtrBeforeCurrent( StudentType *studentHeadPtr );

/*
Name: getValueAtCurrent
Process: if data is available, returns the value at the current location 
         in the iterator linked list,
         if data not available, returns StudentType value
         with dummy/empty struct
Function input/parameters: Iterator linked list head pointer 
                           (StudentType *)
Function output/parameters: student item to load and return(StudentType *)
Function output/returned: none
Device input/file: none
Device output/monitor: none
Dependencies: getPtrBeforeCurrent, setEmptyStudentData
*/
void getValueAtCurrent( StudentType *resultStructHolder, 
                                                  StudentType *studentHeadPtr );

/*
Name: hasNext
Process: reports if current node is not at the last element location,
         also returns false if list is empty
Function input/parameters: Iterator linked list head pointer 
                           (StudentType *)
Function output/parameters: none
Function output/returned: Boolean result of test
Device input/file: none
Device output/monitor: none
Dependencies: none
*/
bool hasNext( StudentType *studentHeadPtr )
;

/*
Name: hasPrev
Process: reports if current location is not at the first element location,
         also returns false if list is empty, one line of code
Function input/parameters: Iterator linked list head pointer 
                           (StudentType *)
Function output/parameters: none
Function output/returned: Boolean result of test
Device input/file: none
Device output/monitor: none
Dependencies: variable options
*/
bool hasPrev( StudentType *studentHeadPtr );

/*
Name: initializeIterator
Process: initializes iterator by returning NULL to head pointer
         assigned to the function
Function input/parameters: none
Function output/parameters: none
Function output/returned: NULL
Device input/file: none
Device output/monitor: none
Dependencies: none
*/
StudentType *initializeIterator();

/*
Name: insertAtCurrent
Process: inserts value at current location,
         maintains current location where new value was inserted,
         if list was empty, sets new node to current
Function input/parameters: Iterator linked list head pointer (StudentType *),
                           new student to insert (StudentType)
Function output/parameters: none
Function output/returned: pointer to possibly updated head pointer 
                          (StudentType *)
Device input/file: none
Device output/monitor: none
Dependencies: createStudentNodeFromStruct, getPtrBeforeCurrent
*/
StudentType *insertAtCurrent( StudentType *studentHeadPtr,
                                                       StudentType newStudent );

/*
Name: insertAtEnd
Process: inserts value at front of list,
         if list empty, set node to current, 
         otherwise, no change to current location
Function input/parameters: Iterator linked list head pointer (StudentType *),
                           new student data (StudentType)
Function output/parameters: none
Function output/returned: pointer to possibly updated head pointer 
                          (StudentType *)
Device input/file: none
Device output/monitor: none
Dependencies: createStudentNodeFromStruct
*/
StudentType *insertAtEnd( StudentType *studentHeadPtr, 
                                                       StudentType newStudent );

/*
Name: insertAtFront
Process: inserts value at front of list,
         if list empty, set node to current, 
         otherwise, no change to current location
Function input/parameters: Iterator linked list head pointer (StudentType *),
                           new student to insert (StudentType)
Function output/parameters: none
Function output/returned: possibly updated head pointer (StudentType *)
Device input/file: none
Device output/monitor: none
Dependencies: checkForIteratorResize, copyStudentData
*/
StudentType *insertAtFront( StudentType *studentHeadPtr, 
                                                       StudentType newStudent );

/*
Name: isEmpty
Process: checks for iterator linked list empty, if it is, returns true,
         otherwise returns false, one line of code
Function input/parameters: Iterator linked list head pointer data 
                           (StudentType *)
Function output/parameters: none
Function output/returned: Boolean result of test
Device input/file: none
Device output/monitor: none
Dependencies: none
*/
bool isEmpty( const StudentType *studentHeadPtr );

/*
Name: moveNext
Process: moves current node to the next location in the list
         if possible (aka moveRight)
Function input/parameters: Iterator linked list head pointer 
                           (StudentType *)
Function output/parameters: none
Function output/returned: Boolean result of test
Device input/file: none
Device output/monitor: none
Dependencies: variable options
*/
bool moveNext( StudentType *studentHeadPtr );

/*
Name: movePrev
Process: moves iterator to the previous location in the list
         if possible (aka moveLeft)
Function input/parameters: Iterator linked list head pointer 
                           (StudentType *)
Function output/parameters: none
Function output/returned: Boolean result of test
Device input/file: none
Device output/monitor: none
Dependencies: variable options
*/
bool movePrev( StudentType *studentHeadPtr );

/*
Name: printIteratorChars
Process: recursively prints a specified number of characters
Function input/parameters: number of characters (int),
                           character to be printed (char)
Function output/parameters: none
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: printf, printIteratorChars (recursive)
*/
void printIteratorChars( int numChars, char outChar );

/*
Name: removeAtCurrent
Process: removes current value if data is available, returns the value
         if data not available, returns StudentType value
         with dummy/empty struct
Function input/parameters: Iterator linked list head pointer 
                           (StudentType *)
Function output/parameters: pointer to removed student (StudentType *)
Function output/returned: pointer to possibly updated linked list head
Device input/file: none
Device output/monitor: none
Dependencies: getPtrBeforeCurrent, copyStudentData, free
*/
StudentType *removeAtCurrent( StudentType *resultStructHolder, 
                                                  StudentType *studentHeadPtr );

/*
Name: setEmptyStudentData
Process: sets student node to empty data, one line of code
Function input/parameters: 
Function output/parameters: pointer to student data holder (StudentType *)
Function output/returned: none
Device input/file: none
Device output/monitor: none
Dependencies: none
*/
void setEmptyStudentData( StudentType *studentDataHolder );

/*
Name: setStudentData
Process: sets student data to a StudentType struct,
         sets current Boolean to false, and nextPtr to NULL
Function input/parameters: student data: name (const char *),
                                         student id (int),
                                         gender (char),
                                         gpa (double)
Function output/parameters: updated student data (StudentType *)
Function output/returned: none
Device input/file: none
Device output/monitor: none
Dependencies: none
*/
void setStudentData( StudentType *studentDataHolder, 
                     const char *name, int studentId, char gender, double gpa );

/*
Name: setToFirst
Process: if data is available, sets current location to first element location,
         returns true, otherwise returns false
Function input/parameters: Iterator linked list head pointer (StudentType *)
Function output/parameters: possibly updated Iterator linked list head pointer 
                            (StudentType *)
Function output/returned: Boolean result of operation
Device input/file: none
Device output/monitor: none
Dependencies: variable options
*/
bool setToFirst( StudentType *studentHeadPtr );

/*
Name: setToLast
Process: if data is available, sets current location to last element location,
         returns true, otherwise returns false  
Function input/parameters: Iterator linked list head pointer (StudentType *)
Function output/parameters: possibly updated iterator linked list head pointer 
                            (StudentType *)
Function output/returned: Boolean result of operation
Device input/file: none
Device output/monitor: none
Dependencies: variable options
*/
bool setToLast( StudentType *studentHeadPtr );

#endif   // IteratorUtility.h
   

