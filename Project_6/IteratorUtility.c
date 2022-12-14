#include "IteratorUtility.h"

const int DEFAULT_CAPACITY = 10;

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
void checkForIteratorResize( IteratorType *iterator )
{
    int index;
    StudentType *resizedArr;

    // if size == capacity
    if (iterator->size == iterator->capacity)
    {
        // allocate memory to new array with double previous capacity
        resizedArr = malloc(iterator->capacity * PRECISION 
                                                         * sizeof(StudentType));

        // copy the data from the old array to the new array
        for (index = 0; index < iterator->capacity; index++)
        {
            copyStudentData(&resizedArr[index], iterator->array[index]);
        }
    }


}

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
void clearIterator( IteratorType *iterator )
{
    // free the allocated array
    free(iterator->array);
    iterator->array = NULL;

    // set iterator default values
    iterator->capacity = DEFAULT_CAPACITY;
    iterator->currentIndex = 0;
    iterator->size = 0;

}

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
void copyIterator( IteratorType *destIterator, const IteratorType srcIterator )
{
    int index;

    // check if the size of source is 0
    if (srcIterator.size > 0)
    {
        // copy the capacity
        destIterator->capacity = srcIterator.capacity;
        
        // copy the current index
        destIterator->currentIndex = srcIterator.currentIndex;

        // copy the size
        destIterator->size = srcIterator.size;

        // allocate memory for the new array
        destIterator->array = malloc(destIterator->capacity * 
                                                           sizeof(StudentType));
        // copy each piece of data to the new iterator student array
        for (index = 0; index < srcIterator.size; index++)
        {
            copyStudentData(&destIterator->array[index], 
                                                      srcIterator.array[index]);
        }
    }
}

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
void copyIteratorString( char *destStr, const char *sourceStr )
{
    // copy the string
    int index = 0;
    while (sourceStr[index] != NULL_CHAR)
    {
        destStr[index] = sourceStr[index];
        index++;
    }
    // always end with null char
    destStr[index] = NULL_CHAR;
}

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
void copyStudentData( StudentType *destStudent, const StudentType srcStudent )
{

    // copy all data from src to dest
    destStudent->gender = srcStudent.gender;
    destStudent->gpa = srcStudent.gpa;
    destStudent->studentId = srcStudent.studentId;

    // copy the string over
    copyIteratorString(destStudent->name, srcStudent.name);
}

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
void displayIterator( IteratorType iteratorData )
{
    int index;
    int padding = 22;

    // if iterator has data
    if (iteratorData.size > 0)
    {
        printf("Iterator Display:\n");
        printf("Left side of iterator-> ");
        for (index = 0; index < iteratorData.size; index++)
        {
            // print out the padding before each except the first
            if (index > 0)
            {
                printIteratorChars(padding + PRECISION * index, SPACE);
            }

            // if we are at the current, indicate so in the output
            if (iteratorData.currentIndex == index)
            {
                printf("[ ");
            }
            
            // print out the student data at the index
            printf("%s, %d, %c, %.4lf", iteratorData.array[index].name,
                                        iteratorData.array[index].studentId, 
                                        iteratorData.array[index].gender, 
                                        iteratorData.array[index].gpa);
            
            // if we are at the current, indicate so in the output
            if (iteratorData.currentIndex == index)
            {
                printf(" ]");
            }

            // print colon newline at the end of each except the last
            if (index != iteratorData.size - 1)
            {
                printf(";");
                printf("%c", NEWLINE_CHAR);
            }
        }

        // indicate the right side of iterator
        printf(" <-Right side of iterator");


    }
    // else iterator is empty
    else 
    {
        printf("Iterator is empty - Display not conducted");
    }
}

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
StudentType getValueAtCurrent( IteratorType *iterator )
{
    StudentType returnedStudent;

    // if there exists data
    if (iterator->size > 0)
    {
        copyStudentData(&returnedStudent, 
                                       iterator->array[iterator->currentIndex]);
    
    }
    else
    {
        returnedStudent.gender = 'x';
        returnedStudent.gpa = 0;
        returnedStudent.studentId = 0;
        returnedStudent.name[0] = NULL_CHAR;

    }

    return returnedStudent;
}

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
bool hasNext( IteratorType *iterator )
{
    // if the current index is not the last index
    return iterator->currentIndex < iterator->size - 1;
}

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
bool hasPrev( IteratorType *iterator )
{
    return iterator->currentIndex > 0 && iterator->size > 0;
}

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
void initializeIterator( IteratorType *iterator )
{
    // set the iterator capacity to default capacity
    iterator->capacity = DEFAULT_CAPACITY;

    // set current size to 0
    iterator->size = 0;

    // set current index to 0
    iterator->currentIndex = 0;

    // create and allocate memory for new array of studentTypes
    iterator->array = malloc(DEFAULT_CAPACITY * sizeof(StudentType));
    
}

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
void insertAtCurrent( IteratorType *iterator, StudentType newStudent )
{
    int index;

    // check for resize
    checkForIteratorResize(iterator);

    // move all data forward in the array
    for (index = iterator->size; index > 0; index--)
    {
        iterator->array[index] = iterator->array[index - 1];
    }

    // inset data into current index
    copyStudentData(&iterator->array[iterator->currentIndex], newStudent);
}

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
void insertAtEnd( IteratorType *iterator, StudentType newStudent )
{
    StudentType localCopy;

    // first check if we need a resize
    checkForIteratorResize(iterator);

    // copy the data to the local copy
    copyStudentData(&localCopy, newStudent);

    // assign the copy to the end of array
    iterator->array[iterator->size] = localCopy;

    // increment the size
    iterator->size++;
}

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
void insertAtFront( IteratorType *iterator, StudentType newStudent )
{
    int index;

    // check if current size == cap, resize if true
    checkForIteratorResize(iterator); 

    // move all data forward in the array
    for (index = iterator->size; index > 0; index--)
    {
        iterator->array[index] = iterator->array[index - 1];
    }

    // copy the data to the local copy
    copyStudentData(&iterator->array[0], newStudent);

    // increase the size
    iterator->size++;
}

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
bool isEmpty( IteratorType *iterator )
{
    return iterator->size == 0;
}

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
bool moveNext( IteratorType *iterator )
{
    // if there is a next
    if (hasNext(iterator))
    {
        // move the current index forward by 1
        iterator->currentIndex++;
        // return true
        return true;
    }
    // else return false
    return false;
    
}

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
bool movePrev( IteratorType *iterator )
{
    // if there exists a previous
    if (hasPrev(iterator))
    {
        // move current back by one
        iterator->currentIndex--;
        
        // return success
        return true;
    }
    // else return failure
    return false;
}

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
void printIteratorChars( int numChars, char outChar )
{
    if (numChars > 0)
    {
        printf("%c", outChar);
        printIteratorChars(numChars - 1, outChar);
    }
}

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
StudentType removeAtCurrent( IteratorType *iterator )
{
    int index;
    StudentType deletedStudent;

    // if the array is empty
    if (iterator->size == 0)
    {
        // set student to empty name, 'x' gender, and zero values
        deletedStudent.name[0] = NULL_CHAR;
        deletedStudent.gender = 'x';
        deletedStudent.gpa = 0;
        deletedStudent.studentId = 0;
    }
    // if the current is the last
    else if (iterator->currentIndex == iterator->size - 1)
    {
        // copy the student to delete to the return value
        copyStudentData(&deletedStudent, 
                                       iterator->array[iterator->currentIndex]);
        // decrement the size forgetting the current
        iterator->size--;
        setToLast(iterator);
    }
    else
    {
        // copy the student to delete to the return value
        copyStudentData(&deletedStudent, 
                                       iterator->array[iterator->currentIndex]);
        
        // move all the data backward by one starting at current
        for (index = iterator->currentIndex; index < iterator->size - 1; 
                                                                        index++)
        {
            iterator->array[index] = iterator->array[index + 1];
        }

        // decrement the size
        iterator->size--;
    }

    

    return deletedStudent;
}

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
                     const char *name, int studentId, char gender, double gpa )
{
    // set student struct data to data given
    student->gender = gender;
    student->gpa = gpa;
    student->studentId = studentId;

    // possibly use copyIteratorString here

    // copy the name of the student
    int index = 0;
    // while we are not at the end of string
    while (name[index] != NULL_CHAR)
    {
        // copy the current char
        student->name[index] = name[index];
        index++;
    }
    // remember to maintain null char ending strings
    student->name[index] = NULL_CHAR;

}

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
bool setToFirst( IteratorType *iterator )
{
    // if the array has data
    if (iterator->size > 0)
    {
        // set the current to the start
        iterator->currentIndex = 0;

        // return success
        return true;
    }
    // else return failure
    return false;
}

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
bool setToLast( IteratorType *iterator )
{
    // if there is data
    if (iterator->size > 0)
    {
        // set the current to the last index
        iterator->currentIndex = iterator->size - 1;
        
        // return success
        return true;
    } 
    // else return failure
    return false;
}
