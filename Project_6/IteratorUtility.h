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
    
   } StudentType;

typedef struct IteratorStruct
   {
    StudentType *array;

    int capacity;

    int size;

    int currentIndex;

   } IteratorType;

/*
Name: checkForIteratorResize
Process: checks for need to resize (increase capacity of) array,
         if necessary, creates new array with double the previous capacity,
         updates array, then returns previous data memory to OS
Function input/parameters: Iterator data (Iterator *)
Function output/parameters: updated Iterator data (Iterator *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: malloc, sizeof, copyStudentData, free
*/
void checkForIteratorResize( IteratorType *iterator );

/*
Name: clearIterator
Process: clears all data in Iterator, returns memory to OS
Function input/parameters: Iterator data (Iterator *)
Function output/parameters: updated Iterator data (Iterator *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: free
*/
void clearIterator( IteratorType *iterator );

/*
Name: copyIterator
Process: copies all parts of iterator,
         checks for destination iterator array not empty and frees as needed, 
         creates new iterator array using dynamic memory, copies array
Function input/parameters: source Iterator data (Iterator)
Function output/parameters: destination Iterator data (Iterator *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: free, malloc, sizeof, copyStudentData
*/
void copyIterator( IteratorType *destIterator, const IteratorType srcIterator );

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
Process: copies all parts of the student data
Function input/parameters: source Student data (const StudentType)
Function output/parameters: destination Student data (StudentType *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: copyIteratorString
*/
void copyStudentData( StudentType *destStudent, const StudentType srcStudent );

/*
Name: displayIterator
Process: displays iterator if it is not empty,
         shows bottom to top of iterator data organization,
         if empty, displays "Iterator is empty - Display not conducted"
Function input/parameters: iterator data struct (IteratorType)
Function output/parameters: none
Function output/returned: none
Device input/---: none
Device output/monitor: data displayed as specified
Dependencies: printf, printIteratorChars
*/
void displayIterator( IteratorType iteratorData );

/*
Name: getValueAtCurrent
Process: if data is available, returns the value at the current location 
         in the iterator,
         if data not available, returns StudentType value
         with empty name string, zeroed values, and gender 'x'
Function input/parameters: Iterator data (Iterator *)
Function output/parameters: none
Function output/returned: student item (StudentType)
Device input/---: none
Device output/---: none
Dependencies: variable options
*/
StudentType getValueAtCurrent( IteratorType *iterator );

/*
Name: hasNext
Process: reports if current index is not at the last element location,
         and list is not empty, one line of code
Function input/parameters: Iterator data (Iterator *)
Function output/parameters: none
Function output/returned: Boolean result of test (bool)
Device input/---: none
Device output/---: none
Dependencies: none
*/
bool hasNext( IteratorType *iterator );

/*
Name: hasPrev
Process: reports if current location is not at the first element location,
         and list is not empty, one line of code
Function input/parameters: Iterator data (Iterator *)
Function output/parameters: none
Function output/returned: Boolean result of test (bool)
Device input/---: none
Device output/---: none
Dependencies: none
*/
bool hasPrev( IteratorType *iterator );

/*
Name: initializeIterator
Process: initializes all data in Iterator, 
         initializes array to DEFAULT_CAPACITY initial capacity
Function input/parameters: Iterator data (Iterator *)
Function output/parameters: updated Iterator data (Iterator *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: malloc, sizeof
*/
void initializeIterator( IteratorType *iterator );

/*
Name: insertAtCurrent
Process: inserts value at current location,
         moves subsequent list up,
         maintains current location where new value was inserted
Function input/parameters: Iterator data (Iterator *), 
                           new student data (StudentType)
Function output/parameters: updated Iterator data (Iterator *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: checkForIteratorResize, copyStudentData
*/
void insertAtCurrent( IteratorType *iterator, StudentType newStudent );

/*
Name: insertAtEnd
Process: inserts value at end of list, no change to current location
Function input/parameters: Iterator data (Iterator *),
                           new student data (StudentType)
Function output/parameters: updated Iterator data (Iterator *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: checkForIteratorResize, copyStudentData
*/
void insertAtEnd( IteratorType *iterator, StudentType newStudent );

/*
Name: insertAtFront
Process: inserts value at front of list, no change to current location
Function input/parameters: Iterator data (Iterator *), 
                           new student data (StudentType)
Function output/parameters: updated Iterator data (Iterator *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: checkForIteratorResize, copyStudentData
*/
void insertAtFront( IteratorType *iterator, StudentType newStudent );

/*
Name: isEmpty
Process: checks for iterator array empty, if it is, returns true,
         otherwise returns false, one line of code
Function input/parameters: Iterator data (Iterator *)
Function output/parameters: none
Function output/returned: Boolean result of test
Device input/---: none
Device output/---: none
Dependencies: none
*/
bool isEmpty( IteratorType *iterator );

/*
Name: moveNext
Process: moves iterator to the next location in the list
         if possible (aka moveRight)
Function input/parameters: Iterator data (Iterator *)
Function output/parameters: updated Iterator data (Iterator *)
Function output/returned: Boolean result of test (bool)
Device input/---: none
Device output/---: none
Dependencies: hasNext
*/
bool moveNext( IteratorType *iterator );

/*
Name: movePrev
Process: moves iterator to the previous location in the list
         if possible (aka moveLeft)
Function input/parameters: Iterator data (Iterator *)
Function output/parameters: none
Function output/returned: Boolean result of test (bool)
Device input/---: none
Device output/---: none
Dependencies: hasPrev
*/
bool movePrev( IteratorType *iterator );

/*
Name: printIteratorChars
Process: recursively prints a specified number of characters
Function input/parameters: number of characters (int),
                           character to be printed (char)
Function output/parameters: none
Function output/returned: none
Device input/---: none
Device output/Monitor: characters displayed as specified
Dependencies: printf, printIteratorChars (recursive)
*/
void printIteratorChars( int numChars, char outChar );

/*
Name: removeAtCurrent
Process: removes value if available, returns,
         current location remains the same,
         if data not accessible, returns StudentType with empty name,
         zero values, and 'x' gender
         if last item removed, must reset iterator current location
         to new last item
Function input/parameters: Iterator data (Iterator *)
Function output/parameters: updated Iterator data (Iterator *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: copyStudentData, setToLast
*/
StudentType removeAtCurrent( IteratorType *iterator );

/*
Name: setStudentDAta
Process: sets student to a StudentType struct
Function input/parameters: student data: name (const char *),
                                         student id (int),
                                         gender (char),
                                         gpa (double)
Function output/parameters: updated Iterator data (Iterator *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: none
*/
void setStudentData( StudentType *student, 
                     const char *name, int studentId, char gender, double gpa );

/*
Name: setToFirst
Process: if data is available, sets current location to first element location,
         returns true, otherwise returns false
Function input/parameters: Iterator data (Iterator *)
Function output/parameters: updated Iterator data (Iterator *)
Function output/returned: Boolean result of operation (bool)
Device input/---: none
Device output/---: none
Dependencies: none
*/
bool setToFirst( IteratorType *iterator );

/*
Name: setToLast
Process: if data is available, sets current location to last element location,
         returns true, otherwise returns false  
Function input/parameters: Iterator data (Iterator *)
Function output/parameters: updated Iterator data (Iterator *)
Function output/returned: Boolean result of operation (bool)
Device input/---: none
Device output/---: none
Dependencies: none
*/
bool setToLast( IteratorType *iterator );

#endif   // IteratorUtility.h
   

