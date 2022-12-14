#ifndef QUEUE_UTILITY_H
#define QUEUE_UTILITY_H

// header files
#include <stdlib.h>
#include <stdio.h>
#include "StandardConstants.h"

// structure definitions

typedef struct queueStruct
   {
    char **queueArray;

    int size, capacity;

    int rearIndex, frontIndex;
   } QueueType;

// constant definitions
typedef enum { FRONT, REAR } INDEX_CTRL_CODE;

// prototypes

/*
Name: clearQueue
Process: frees array memory, resets all struct variables to defaults
Function input/parameters: queue data struct pointer (QueueType *)
Function output/parameters: updated queue data struct pointer (QueueType *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: deleteStringArray
*/
void clearQueue( QueueType *queueData );

/*
Name: checkQueueForResize
Process: if queue is full, doubles capacity, creates new array,
         assigns data to new array while resetting indices,
         and frees memory from old array
Function input/parameters: queue data struct pointer (QueueType *)
Function output/parameters: updated queue data struct pointer (QueueType *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: createStringArray, dequeue, copyString, deleteStringArray
*/
void checkQueueForResize( QueueType *queueData );

/*
Name: copyQueueString
Process: copies one string to another, assumes destination string
         has allocated memory
Function input/parameters: c-style source string (const char *)
Function output/parameters: c-style destination string (char *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: none
*/
void copyQueueString( char *destStr, const char *sourceStr );

/*
Name: createQueueStringArray
Process: dynamically creates array of strings (2D array of chars)
Function input/parameters: number of strings (int)
Function output/parameters: none
Function output/returned: dynamically allocated array of strings (char **)
Device input/---: none
Device output/---: none
Dependencies: malloc
*/
char **createQueueStringArray( int numStrings );

/*
Name: deleteQueueStringArray
Process: frees array of strings (2D array of characters)
Function input/parameters: string array pointer (char **),
                           number of strings (int)
Function output/parameters: none
Function output/returned: NULL
Device input/---: none
Device output/---: none
Dependencies: malloc
*/
char **deleteQueueStringArray( char **deletedArrayPtr, int numStrings );

/*
Name: dequeue
Process: returns data from front of queue if queue is not empty,
         decrements size, advances front index
Function input/parameters: queue data struct pointer (QueueType *)
Function output/parameters: updated queue data struct pointer (QueueType *),
                            c-style string dequeued
Function output/returned: dequeued value (char *), 
                          or empty string if empty queue
Device input/---: none
Device output/---: none
Dependencies: copyString, incrementQueueIndex
*/
void dequeue( char *dequeuedStr, QueueType *queueData );

/*
Name: displayQueue
Process: displays queue if it is not empty,
         shows rear (at left) to front (at right) of queue data organization;
         provides two space offset for each name,
         displays "Queue is empty - Display not conducted" if empty queue
Function input/parameters: queue data struct pointer (QueueType *)
Function output/parameters: none
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: printf, printQueueChars
*/
void displayQueue( QueueType *queueData );

/*
Name: enqueue
Process: checks for resize, advances rear index, sets data at rear of queue,
         updates size
Function input/parameters: queue data struct pointer (QueueType *),
                           new name (const char *)
Function output/parameters: updated queue data struct pointer (QueueType *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: checkForQueueResize, incrementQueueIndex, copyString
*/
void enqueue( QueueType *queueData, const char *newName );

/*
Name: incrementQueueIndex
Process: depending on control code, either advances front or rear queue index
Function input/parameters: control code (FRONT, REAR) (INDEX_CTRL_CODE),
                           queue data struct pointer (QueueType *),
                           has one "if" and one "else"
Function output/parameters: updated queue data struct pointer (QueueType *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: none
*/
void incrementQueueIndex( INDEX_CTRL_CODE frontRearCtrl, QueueType *queueData );

/*
Name: initializeQueue
Process: initializes queue indices, size, capacity,
         and creates array of integers
Function input/parameters: queue data struct pointer (QueueType *),
                           initial capacity (int)
Function output/parameters: updated queue data struct pointer (QueueType *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: createStringArray
*/
void initializeQueue( QueueType *queueData, int initialCapacity );

/*
Name: peekQueueFront
Process: returns value at front of queue if queue is not empty,
         otherwise returns NULL_CHAR
Function input/parameters: queue data struct pointer (QueueType *)
Function output/parameters: none
Function output/returned: name at front (char *),
                          or empty string if queue is empty
Device input/---: none
Device output/---: none
Dependencies: none
*/
char *peekQueueFront( QueueType *queueData );

/*
Name: printQueueChars
Process: recursively prints a specified number of characters
Function input/parameters: number of characters (int),
                           character to be printed (char)
Function output/parameters: none
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: printf, printQueueChars (recursive)
*/
void printQueueChars( int numChars, char outChar );


#endif    // QUEUE_UTILITY_H




