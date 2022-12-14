#include "QueueUtility.h"

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
void clearQueue( QueueType *queueData )
{
    // free the queue
    deleteQueueStringArray(queueData->queueArray, queueData->size);

    // initialize struct variables to default
    queueData->capacity = 10;
    queueData->frontIndex = 0;
    queueData->rearIndex = -1;
    queueData->size = 0;
    queueData->queueArray = createQueueStringArray(queueData->capacity);
}

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
void checkQueueForResize( QueueType *queueData )
{
    // if size = capacity
    if (queueData->size == queueData->capacity)
    {
        int oldCap = queueData->capacity;
        int oldFront = queueData->frontIndex;

        // double the capacity
        // create new array of strings with double capacity
        char **copyOfArray;

        int index;


        // create new array of strings
        copyOfArray = createQueueStringArray(queueData->size * 2);

        // copy the old array to the new one
        for (index = 0; index < queueData->size; index++)
        {

            // copy the old queue string to new at new index
            copyQueueString(copyOfArray[index],
                            queueData->queueArray[(oldFront + index) % oldCap]);
            
        }

        // free old array
        queueData->queueArray = deleteQueueStringArray(queueData->queueArray,
                                                                        oldCap);

        // assign the new array in place of the old
        queueData->queueArray = copyOfArray;
        // resize the capacity
        queueData->capacity = oldCap * 2;
        // reassign the new indices
        queueData->frontIndex = 0;
        queueData->rearIndex = queueData->size - 1;

    }
}

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
void copyQueueString( char *destStr, const char *sourceStr )
{
    // remember c strings always end with '\0' - Null Char
    int index = 0;
    // while we have yet to reach a null char
    while (sourceStr[index] != NULL_CHAR)
    {
        // add the character to the dest index and increment
        destStr[index] = sourceStr[index];
        // remember to always end strings with nullchar
        destStr[index + 1] = NULL_CHAR;
        index++;
    }
}

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
char **createQueueStringArray( int numStrings )
{
    int index;
    char **newArrPtr;
    
    newArrPtr = (char **)malloc( numStrings * sizeof( char * ) );

    for( index = 0; index < numStrings; index++ )
       {
        newArrPtr[ index ] = (char *)malloc( STD_STR_LEN * sizeof( char ) );
       }

    return newArrPtr;
}

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
char **deleteQueueStringArray( char **deletedArrayPtr, int numStrings )
{
    int index;

    // loop through the array
    for (index = 0; index < numStrings; index++)
    {
        // delete data at each index of queue array
        free(deletedArrayPtr[index]); 
    }

    // delete the queue array
    free(deletedArrayPtr);

    return NULL;
}

/*
Name: dequeue
Process: returns data from front of queue if queue is not empty,
         decrements size, advances front index
Function input/parameters: queue data struct pointer (QueueType *)
Functio
n output/parameters: updated queue data struct pointer (QueueType *),
                            c-style string dequeued
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: copyString, incrementQueueIndex
*/
void dequeue( char *dequeuedStr, QueueType *queueData )
{
    // if the queue is not empty
    if (queueData->size > 0)
    {
        // shorten variable
        int frontIndex = queueData->frontIndex;

        // copy the string at the front of the index
        copyQueueString(dequeuedStr, queueData->queueArray[frontIndex]);

        // increment the front index forgetting the name that was there
        incrementQueueIndex(FRONT, queueData);

        // decrement the size
        queueData->size--;
    }

    
}

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
void displayQueue( QueueType *queueData )
{
    // check if queue is empty
    if (queueData->size > 0)
    {
        // print queue display
        printf("%cQueue Display:%c", NEWLINE_CHAR, NEWLINE_CHAR);

        // print the front of queue indication
        printf("Rear of Queue-> ");

        // size of the above display
        int paddingSize = 16;

        // keep count of how many times we loop
        int count = 0;

        // Start at the rear
        int index = queueData->rearIndex;

        // loop until we reach the front
        while ( index != queueData->frontIndex)
        {
            
            // exclude spacing at the rear of queue
            if (index != queueData->rearIndex)
            {
                // display two spaces times the current index, excluding first
                printQueueChars(paddingSize + 2 * count, SPACE);
            }
            
            // if we underflow
            if (index < 0)
            {
                // loop the index to the opp side
                index = queueData->capacity - 1;
            }

            // print name at current index
            printf("%s", queueData->queueArray[index]);

            // decrement the index
            index--;

            // place a semicolon and newline at the end of each
            printf(";");
            printf("%c", NEWLINE_CHAR);
            
            // increment loop counter
            count++;
        }

        // print name at front
        printQueueChars(paddingSize + 2 * count, SPACE);
        printf("%s", queueData->queueArray[index]);
        

        printf(" <-Front of Queue");

        // display new line at the of display
        printf("%c", NEWLINE_CHAR);

    }
    // indicate queue is empty
    else
    {
        printf("Queue is empty - Display not conducted");
    }
}

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
Dependencies: checkForQueueResize, incrementQueueIndex, copyQueueString
*/
void enqueue( QueueType *queueData, const char *newName )
{
    // check if we are at capacity and need to resize
    checkQueueForResize(queueData);

    // increment the rear to place the string
    incrementQueueIndex(REAR, queueData);

    // copy the queue string to the rear index
    copyQueueString(queueData->queueArray[queueData->rearIndex], newName);

    // increment the size
    queueData->size++;
}

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
void incrementQueueIndex( INDEX_CTRL_CODE frontRearCtrl, QueueType *queueData )
{
    // check for front control code
    if (frontRearCtrl == FRONT)
    {
        
        queueData->frontIndex++;
        queueData->frontIndex %= queueData->capacity;
    }
    // else assume its rear
    else
    {

        queueData->rearIndex++;
        queueData->rearIndex %= queueData->capacity;
    }
    
}

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
void initializeQueue( QueueType *queueData, int initialCapacity )
{
    queueData->capacity = initialCapacity;
    queueData->frontIndex = 0;
    queueData->rearIndex = -1;
    queueData->size = 0;
    queueData->queueArray = createQueueStringArray(initialCapacity);
}

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
char *peekQueueFront( QueueType *queueData )
{
    // if queue is not empty
    if (queueData->size > 0)
    {
        // return the front
        return queueData->queueArray[queueData->frontIndex];
    }
    // else return null char
    return NULL_CHAR;
}

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
void printQueueChars( int numChars, char outChar )
{
    if (numChars > 0)
    {
        printf("%c", outChar);
        printQueueChars(numChars - 1, outChar);
    }
}