#include "StackUtility.h"

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
void clearStack( StackType *stackData )
{

    // delete the array
    deleteStackStringArray(stackData->stackArray, stackData->size);

    // initialize the defaults 
    stackData->capacity = 10;
    stackData->size = 0;

}

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
void checkStackForResize( StackType *stackData )
{
    // if current size == capacity, double the capacity
    if (stackData->size ==  stackData->capacity)
    {   
        
        char **copyOfStack;
        int index;

        // create new array of strings with double capacity
        copyOfStack = createStackStringArray(stackData->size * 2);

        // copy the data over
        for (index = 0; index < stackData->size; index++)
        {
            copyOfStack[index] = stackData->stackArray[index];
        }

        // free old array
        // deleteStackStringArray(stackData->stackArray, stackData->size);

        // assign copy as new stack
        stackData->stackArray = copyOfStack;

        // resize the capacity
        stackData->capacity *= 2;


    }
}

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
void copyStackString( char *destStr, const char *sourceStr )
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
Name: createStackStringArray
Process: dynamically creates array of strings (2D array of chars)
Function input/parameters: number of strings (int)
Function output/parameters: none
Function output/returned: dynamically allocated array of strings (char **)
Device input/---: none
Device output/---: none
Dependencies: malloc, sizeof
*/ 
char **createStackStringArray( int numStrings )
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
char **deleteStackStringArray( char **deletedArrayPtr, int numStrings )
{
    int index;

    // loop through the stack
    for (index = 0; index < numStrings; index++)
    {
        // free the memory at each index of the stack array
        free(deletedArrayPtr[index]);
    }

    // free the stack array
    free(deletedArrayPtr);

    return NULL;
}

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
void displayStack( StackType *stackData )
{
    // check if stack is empty
    if(stackData->size > 0)
    {  
        int index;

        // print display
        printf("\nStack Display:\n");
        // present bottom of stack
        printf("Bottom of Stack-> ");
        // size of display
        int paddingSize = 18;

        // loop through the stack (remember the bottom is at index 0)
        for (index = 0; index < stackData->size; index++)
        {
            // print out spacing except at the start
            if (index > 0)
            {
                // display two spaces times the current index, excluding first
                printStackChars(paddingSize + 2 * index, SPACE);
            }
            
            // print name at current index
            printf("%s", stackData->stackArray[index]);

            // place a semicolon and newline at the end of each exclude last
            if (index != stackData->size - 1)
            {
                
                printf(";");
                printf("%c", NEWLINE_CHAR);
            }

        }

        // display top of stack
        printf(" <-Top of Stack");

        // display new line at the of display
        printf("%c", NEWLINE_CHAR);


    }
    // else dsplay empty stack
    else
    {
        printf("Stack is empty - Display not conducted");
    }
}

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
void initializeStack( StackType *stackData, int initialCapacity )
{
    stackData->capacity = initialCapacity;
    stackData->size = 0;
    stackData->stackArray = createStackStringArray(initialCapacity);
}

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
char *peekStackTop( StackType *stackData )
{
    // check if empty stack
    if (stackData->size > 0)
    {
        // return the top of stack
        return stackData->stackArray[stackData->size - 1];
    }
    // else return empty string
    return "";
}

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
void pop( char *returnStr, StackType *stackData )
{
    // check if the stack is empty
    if (stackData->size > 0)
    {
        // set the return string to the current top of stack
        copyStackString(returnStr, stackData->stackArray[stackData->size - 1]);

        // decrement size
        stackData->size--;
    }
}

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
void printStackChars( int numChars, char outChar )
{
    if (numChars > 0)
    {
        printf("%c", outChar);
        printStackChars(numChars - 1, outChar);
    }
}

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
void push( StackType *stackData, const char *newName )
{
    // first check stack for resize
    checkStackForResize(stackData);
    
    // push the data to the top of stack (end of array)
    copyStackString(stackData->stackArray[stackData->size], newName);

    // increment the size
    stackData->size++;
}