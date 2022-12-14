#include "IteratorUtilityLL.h"

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
StudentType *clearIterator( StudentType *wkgStudentPtr )
{
    StudentType *temp;

    // if current isnt null
    if (wkgStudentPtr != NULL)
    {
        // assign temp to current
        temp = wkgStudentPtr;

        // move current to next
        wkgStudentPtr = wkgStudentPtr->nextPtr;

        // delete previous
        free(temp);

        // recurse until wkgPtr is null
        clearIterator(wkgStudentPtr);
    }

    // once done, return null
    return NULL;
}

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
StudentType *copyIterator( const StudentType *studentHeadPtr )
{

    const StudentType *wkgPtr = studentHeadPtr;
    StudentType *destWkgPtr = NULL;
    StudentType *destHeadPtr = NULL;

    while (wkgPtr != NULL)
    {
        if (destWkgPtr == NULL)
        {
            destWkgPtr = createStudentNodeFromStruct(*wkgPtr);

            destWkgPtr->current = wkgPtr->current;

            destHeadPtr = destWkgPtr;
        }
        else
        {
            destHeadPtr->nextPtr = createStudentNodeFromStruct(*wkgPtr);

            destHeadPtr = destHeadPtr->nextPtr;

            destHeadPtr->current = wkgPtr->current;
        }

        wkgPtr = wkgPtr->nextPtr;
        
    }

    return destWkgPtr;
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
    // printf("Copying string\n");

    // copy the string
    int index = 0;
    while (sourceStr[index] != NULL_CHAR)
    {
        // printf("Copying %c\n", sourceStr[index]);
        destStr[index] = sourceStr[index];
        index++;
    }

    // end string with nullchar
    destStr[index] = NULL_CHAR;
}

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
void copyStudentData( StudentType *destStudent, const StudentType srcStudent )
{
    // copy name
    copyIteratorString(destStudent->name, srcStudent.name);
    // copy current
    destStudent->current = srcStudent.current;
    // copy gender
    destStudent->gender = srcStudent.gender;
    // copy gpa
    destStudent->gpa = srcStudent.gpa;
    // copy student id
    destStudent->studentId = srcStudent.studentId;
    // set next pointer to null
    destStudent->nextPtr = NULL;
}

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
Dependencies: malloc, sizeof
*/
StudentType *createStudentNodeFromStruct( StudentType studentData )
{
    // copy the head before the loop

    StudentType *newNode;

    newNode = malloc(sizeof(StudentType));

    setStudentData(newNode, studentData.name, studentData.studentId, 
                                           studentData.gender, studentData.gpa);

    // working pointer will point to the head pointers next pointer

    newNode->current = false;

    newNode->nextPtr = NULL;

    return newNode;
}

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
void displayIterator( StudentType *wkgPtr )
{
    int index = 0;
    int padding = 24;


    // if the list is not empty
    if (wkgPtr != NULL)
    {
        printf("\nIterator Display:\n");

        // mark the front of the list
        printf("Left side of iterator-> ");


        // while we havent reached the end of the list
        while (wkgPtr != NULL)
        {
            // print the padding
            if (index > 0)
            {
                printIteratorChars(padding + PRECISION * index, SPACE);
            }

            // mark current
            if (wkgPtr->current)
            {
                printf("[ ");
            }

            // display current pointer data with newline
            printf("%s, %d, %c, %.4lf", wkgPtr->name,
                                        wkgPtr->studentId,
                                        wkgPtr->gender,
                                        wkgPtr->gpa);

            // mark current
            if (wkgPtr->current)
            {
                printf(" ]");
            }

            // mark the end of the list if the next is null
            if (wkgPtr->nextPtr == NULL)
            {
                printf(" <-Right side of iterator");
            }
            else
            {
                // else set end of line to semicolon
                printf(";");
                printf("%c", NEWLINE_CHAR);
            }

            // increment the index and move working pointer to next
            index++;
            wkgPtr = wkgPtr->nextPtr;
        }
    }
    else
    {
        printf("Iterator is empty - Display not conducted\n");
    }

    // insert new line after display
    printf("%c", NEWLINE_CHAR);
}

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
StudentType *getPtrBeforeCurrent( StudentType *studentHeadPtr )
{

    StudentType *wkgPtr;

    // check if list is empty or current is the head return null: guard clause
    if (studentHeadPtr == NULL || studentHeadPtr->current)
    {
        return NULL;
    }

    // set the working pointer to head
    wkgPtr = studentHeadPtr;

    // loop through until we find the current
    while (!wkgPtr->nextPtr->current)
    {   
        // set wkgptr to ptr before current
        wkgPtr = wkgPtr->nextPtr;
    }

    return wkgPtr;
}

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
                                                  StudentType *studentHeadPtr )
{   
    // set result data as empty
    setEmptyStudentData(resultStructHolder);

    // if list isnt empty
    if (studentHeadPtr != NULL)
    {   
        // copy the current pointer data to the result holder
        copyStudentData(resultStructHolder, 
                                 *getPtrBeforeCurrent(studentHeadPtr)->nextPtr);
    }
    
}

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
{
    // false if the next of the current pointer is null or empty list
    return !(studentHeadPtr == NULL || 
                 getPtrBeforeCurrent(studentHeadPtr)->nextPtr->nextPtr == NULL);
}

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
bool hasPrev( StudentType *studentHeadPtr )
{

    // false if current is at head or empty set
    return !(studentHeadPtr->current || studentHeadPtr == NULL);
}

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
StudentType *initializeIterator()
{
    return NULL;
}

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
                                                       StudentType newStudent )
{
    StudentType *tempPtr = NULL;
    StudentType *prevPtr = NULL;

    // check if list is empty
    if( studentHeadPtr == NULL )
    {
        // create new node
        studentHeadPtr = createStudentNodeFromStruct(newStudent);

        // set current to true
        studentHeadPtr->current = true;
    }

    //check if current is first
    else if(!hasPrev(studentHeadPtr))
    {
        // set temp to headPtr
        tempPtr = studentHeadPtr;

        // set rest of list behind temp pointer
        studentHeadPtr->nextPtr = tempPtr;

        // set temp pointer current to false
        tempPtr->current = false;

        // set studentHeadPtr current to true
        studentHeadPtr->current = true;
    }

    // check if current is last
    else if(!hasNext(studentHeadPtr))
    {
        // get current node
        tempPtr = getPtrBeforeCurrent(studentHeadPtr)->nextPtr;

        // create new node
        tempPtr = createStudentNodeFromStruct(newStudent);

        // set temp pointer current to false
        tempPtr->current = false;

        // set temp pointer nextPtr current to true
        tempPtr->nextPtr->current = true;
    }

    // current at middle
    else
    {
        // get previous
        prevPtr = getPtrBeforeCurrent(studentHeadPtr);

        // assign temp to previous nextPtr
        tempPtr = prevPtr->nextPtr;

        // place previous nextPtr to the new node
        prevPtr->nextPtr = createStudentNodeFromStruct(newStudent);

        // set rest of list after new node
        prevPtr->nextPtr->nextPtr = tempPtr;

        // set previous nextPtr current to true
        prevPtr->nextPtr->current = true;

        // set temp current to false
        tempPtr->current = true;
    }

    // return head
    return studentHeadPtr;
}

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
Dependencies: copyStudentData
*/
StudentType *insertAtEnd( StudentType *studentHeadPtr, 
                                                       StudentType newStudent )
{
    StudentType *newEnd, *wkgPtr;

    // if list is empty set current to true
    if (studentHeadPtr == NULL)
    {
        newStudent.current = true;
    }

    // set the new head as the new student
    newEnd = malloc(sizeof(StudentType));
    copyStudentData(newEnd, newStudent);

    // set working pointer to the front of the list
    wkgPtr = studentHeadPtr;

    // loop to the end of the list
    while (wkgPtr->nextPtr != NULL && wkgPtr != NULL)
    {
        wkgPtr = wkgPtr->nextPtr;
    }

    if (wkgPtr != NULL)
    {
        // set the end to point at the inserted
        wkgPtr->nextPtr = newEnd;
    }
    else
    {
        studentHeadPtr = newEnd;
    }
    

    // return the head
    return studentHeadPtr;
}

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
Dependencies: copyStudentData
*/
StudentType *insertAtFront( StudentType *studentHeadPtr, 
                                                       StudentType newStudent )
{
    // if list is empty
    if (studentHeadPtr == NULL)
    {
        newStudent.current = true;
    }

    // set the new head as the new student
    StudentType *newHead = malloc(sizeof(StudentType));
    copyStudentData(newHead, newStudent);

    // set the current head pointer as the next of the new student
    newHead->nextPtr = studentHeadPtr;

    // return the new head
    return newHead;
}

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
bool isEmpty( const StudentType *studentHeadPtr )
{
    return studentHeadPtr == NULL;
}

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
bool moveNext( StudentType *studentHeadPtr )
{
    StudentType *wkgPtr;

    // if we dont have a next, return failure: guard clause
    if (!hasNext(studentHeadPtr))
    {
        return false;
    }

    // set the working pointer to head
    wkgPtr = studentHeadPtr;

    // loop through until we find the current
    while (!wkgPtr->current)
    {   
        wkgPtr = wkgPtr->nextPtr;
    }
    
    // if there exists a next, set it to next and return success
    if (wkgPtr->nextPtr != NULL)
    {
        wkgPtr->current = false;
        wkgPtr->nextPtr->current = true;
        return true;
    }
    // else current is already at the end of list, return failure
    return false;
}

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
bool movePrev( StudentType *studentHeadPtr )
{
    StudentType *wkgPtr;

    // if we dont have a previous, return failure: guard clause
    if (!hasPrev(studentHeadPtr))
    {
        return false;
    }

    // set the working pointer to head
    wkgPtr = studentHeadPtr;

    // loop through until we find the current
    while (!wkgPtr->nextPtr->current)
    {   
        // set wkgptr to ptr before current
        wkgPtr = wkgPtr->nextPtr;
    }

    // once we found current set next to false and current to true
    wkgPtr->nextPtr->current = false;
    wkgPtr->current = true;

    return true;

}

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
                                                  StudentType *studentHeadPtr )
{
    StudentType *wkgPtr, *tempPtr;

    // if the head is current
    if (studentHeadPtr->current)
    {
        // set temp to the current head
        tempPtr = studentHeadPtr;

        // move the head pointer over one
        studentHeadPtr = studentHeadPtr->nextPtr;

        // set nwe head as current
        studentHeadPtr->current = true;

        // set result holder
        copyStudentData(resultStructHolder, *tempPtr);

        // free old head
        free(tempPtr);

    }
    else
    {
        // set wkgPtr to the pointer becore current
        wkgPtr = getPtrBeforeCurrent(studentHeadPtr);

        // set temp pointer to current
        StudentType *oldCurrentPtr = wkgPtr->nextPtr;

        // set next ptr to after current if it exists
        if (wkgPtr->nextPtr->nextPtr != NULL)
        {
            // set next pointer to next next
            wkgPtr->nextPtr = wkgPtr->nextPtr->nextPtr;

            // then set next to current
            wkgPtr->nextPtr->current = true;
        }
        else
        {
            // set next pointer to null
            wkgPtr->nextPtr = NULL;

            // and set wkgpointer to current
            wkgPtr->current = true;
        }

        // set result holder
        copyStudentData(resultStructHolder, *oldCurrentPtr);

        // free temp pointer (old current pointer)
        free(oldCurrentPtr);

    }
    

    // and return the head of list pointer
    return studentHeadPtr;
}

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
void setEmptyStudentData( StudentType *studentDataHolder )
{
    setStudentData(studentDataHolder, NULL, 0, 'x', 0);
}

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
                     const char *name, int studentId, char gender, double gpa )
{

    // copy student name
    copyIteratorString(studentDataHolder->name, name);

    // assign student id
    studentDataHolder->studentId = studentId;

    // assign gender
    studentDataHolder->gender = gender;

    // assign gpa
    studentDataHolder->gpa = gpa;

    // assign current
    studentDataHolder->current = false;

    // assign next pointer
    studentDataHolder->nextPtr = NULL;
}

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
bool setToFirst( StudentType *studentHeadPtr )
{
    // if we dont have data, return failure: guard clause
    if (studentHeadPtr == NULL)
    {
        return false;
    }

    // if the head is not already current
    if (!studentHeadPtr->current)
    {
        // set the old current to false
        getPtrBeforeCurrent(studentHeadPtr)->nextPtr->current = false;

        // set the head to current
        studentHeadPtr->current = true;
    }
    

    // return success
    return true;
}

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
bool setToLast( StudentType *studentHeadPtr )
{
    StudentType *wkgPtr;

    // check if list is empty: guard clause
    if (studentHeadPtr == NULL)
    {
        return false;
    }

    // set working pointer to the front of list
    wkgPtr = studentHeadPtr;

    // while the working pointer next is not null
    while (wkgPtr->nextPtr != NULL)
    {
        // if we find a current along the way set it to false
        if (wkgPtr->current)
        {
            wkgPtr->current = false;
        }

        // move the pointer down the list
        wkgPtr = wkgPtr->nextPtr;
    }

    // once loop is done we are at the end so set to current
    wkgPtr->current = true;

    return true;
    
}