#ifndef STACK_UTILITY_H
#define STACK_UTILITY_H

// header files
#include <stdlib.h>
#include <stdio.h>
#include "StandardConstants.h"

// structure definitions

typedef struct stackStruct
   {
    char **stackArray;

    int size, capacity;
   } StackType;

// constant definitions

// prototypes

/*
Name: clearStack
Process: frees array memory, resets all struct variables to default
Function input/parameters: stack data struct pointer (StackType *)
Function output/parameters: updated stack data struct pointer (StackType *)
Function output/returned: none
Device input/file: none
Device output/monitor: none
Dependencies: deleteStringArray
*/
void clearStack( StackType *stackData );

/*
Name: checkStackForResize
Process: if stack is full, doubles capacity, creates new array,
         assigns data to new array, and frees memory from old array
Function input/parameters: stack data struct pointer (StackType *)
Function output/parameters: updated stack data struct pointer (StackType *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: createStringArray, copyString, deleteStringArray
*/
void checkStackForResize( StackType *stackData );

/*
Name: copyStackString
Process: copies one string to another, assumes destination string
         has allocated memory
Function input/parameters: c-style source string (const char *)
Function output/parameters: c-style destination string (char *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: none
*/
void copyStackString( char *destStr, const char *sourceStr );

/*
Name: createStackStringArray
Process: dynamically creates array of strings (2D array of chars)
Function input/parameters: number of strings (int)
Function output/parameters: none
Function output/returned: dynamically allocated array of strings (char **)
Device input/---: none
Device output/---: none
Dependencies: malloc, sizeof
*/
char **createStackStringArray( int numStrings );

/*
Name: deleteStackStringArray
Process: frees array of strings (2D array of characters)
Function input/parameters: string array pointer (char **),
                           number of strings (int)
Function output/parameters: none
Function output/returned: NULL
Device input/---: none
Device output/---: none
Dependencies: free
*/
char **deleteStackStringArray( char **deletedArrayPtr, int numStrings );

/*
Name: displayStack
Process: displays stack if it is not empty,
         shows bottom to top of stack data organization,
         if empty, displays "Stack is empty - Display not conducted"
Function input/parameters: stack data struct pointer (StackType *)
Function output/parameters: none
Function output/returned: none
Device input/file: none
Device output/monitor: none
Dependencies: printf, printStackChars
*/
void displayStack( StackType *stackData );

/*
Name: initializeStack
Process: initializes stack size, capacity,
         and creates array of strings
Function input/parameters: stack data struct pointer (StackType *),
                           initial capacity (int)
Function output/parameters: updated stack data struct pointer (StackType *)
Function output/returned: none
Device input/file: none
Device output/monitor: none
Dependencies: createStringArray
*/
void initializeStack( StackType *stackData, int initialCapacity );

/*
Name: peekStackTop
Process: returns value at top of stack if stack is not empty,
         otherwise returns empty string
Function input/parameters: stack data struct pointer (StackType *)
Function output/parameters: none
Function output/returned: name at stack top,
                          or empty string if empty
Device input/file: none
Device output/monitor: none
Dependencies: copyString
*/
char *peekStackTop( StackType *stackData );

/*
Name: pop
Process: returns string from top of stack if stack is not empty,
         decrements size
Function input/parameters: stack data struct pointer (StackType *)
Function output/parameters: updated stack data struct pointer (StackType *),
                            popped string (char *)
Function output/returned: none
Device input/file: none
Device output/monitor: none
Dependencies: copyString
*/
void pop( char *returnStr, StackType *stackData );

/*
Name: printStackChars
Process: recursively prints a specified number of characters
Function input/parameters: number of characters (int),
                           character to be printed (char)
Function output/parameters: none
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: printf, printStackChars (recursive)
*/
void printStackChars( int numChars, char outChar );

/*
Name: push
Process: checks for resize, sets value in array, updates top index
Function input/parameters: stack data struct pointer (StackType *),
                           new value (int)
Function output/parameters: updated stack data struct pointer (StackType *)
Function output/returned: none
Device input/file: none
Device output/monitor: none
Dependencies: checkStackForResize, copyString
*/
void push( StackType *stackData, const char *newName );


#endif     // STACK_UTILITY_H



