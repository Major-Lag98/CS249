#ifndef SET_UTILITIES_H
#define SET_UTILITIES_H

// headers/libraries
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

// derived data types
typedef enum { INCREMENTED = 101, ODD, EVEN, RANDOM } DataSelections;
typedef enum { MAX_SET_CAPACITY = 100, 
                                   MAX_INIT_SET_CAPACITY = 50 } ArrayCapacities;
typedef enum { THREE_DIGIT_LOW = 100, THREE_DIGIT_HIGH = 999 } RandomLimits;

typedef struct SetStruct
   {
    int setArray[ MAX_SET_CAPACITY ];

    int capacity;

    int size;
   } SetType;

// prototypes

/*
Name: addItem
Process: adds item to set, does not allow duplicates,
         does not allow data to be added to full list
Function Input/Parameters: set data (SetType), new item (int)
Function Output/Parameters: none
Function Output/Returned: updated set data (SetType)
Device Input/---: none
Device Output/---: none
Dependencies: isInSet
*/
SetType addItem( SetType setData, int newValue );

/*
Name: copySet
Process: copies all data of one set into other
Function Input/Parameters: source & destination set (const SetType)
Function Output/Parameters: none
Function Output/Returned: updated destination set (SetType)
Device Input/---: none
Device Output/---: none
Dependencies: none
*/
SetType copySet( SetType dest, const SetType source );

/*
Name: deleteItem
Process: searches for item, deletes if found,
         moves array data down by one from above the removed value
         test loop must stop as soon as item is found (if it is found)         
Function Input/Parameters: setData (SetType), item to delete (int)
Function Output/Parameters: none
Function Output/Returned: updated set data (SetType)
Device Input/---: none
Device Output/---: none
Dependencies: none
*/
SetType deleteItem( SetType setData, int itemToDelete );

/*
Name: displaySet
Process: displays series of set values, or displays "Empty Set" if no values
Function Input/Parameters: name of set array (const char *),
                           set data (SetType)
Function Output/Parameters: none
Function Output/Returned: none
Device Input/---: none
Device Output/monitor: data displayed as specified
Dependencies: printf
*/
void displaySet( const char *setName, const SetType setData );

/*
Name: findIntersection
Process: finds the set intersection between two sets,
         assigns to another set,
         loop to find intersection must end when common value found
Function Input/Parameters: sets one and two(const SetType),
                           result set (SetType)
Function Output/Parameters: none
Function Output/Returned: updated result set (SetType)
Device Input/---: none
Device Output/---: none
Dependencies: isInSet
*/
SetType findIntersection( SetType intersectSet, 
                                 const SetType oneSet, const SetType otherSet );

/*
Name: findUnion
Process: finds the set union between two sets,
         assigns to another set,
         loop to find union must end when common value found
Function Input/Parameters: sets one and two(const SetType),
                           result set (SetType)
Function Output/Parameters: none
Function Output/Returned: updated result set (SetType)
Device Input/---: none
Device Output/---: none
Dependencies: copySet, isInSet
*/
SetType findUnion( SetType unionSet, 
                                 const SetType oneSet, const SetType otherSet );

/*
Name: getRandBetween
Process: generates and returns a random value
         between two given values, inclusive
Function Input/Parameters: low, high limits (int)
Function Output/Parameters: none
Function Output/Returned: random value as specified
Device Input/---: none
Device Output/---: none
Dependencies: rand
*/
int getRandBetween( int lowVal, int highVal );

/*
Name: initializeSet
Process: initializes a set with all EVEN values, all ODD values,
         continually INCREMENTED values, or RANDOM three digit values
         depending on the DataSelections constant provided
Function Input/Parameters: set data (SetType),
                           start value, number of items (int),
                           capacity of array (int),
                           data values generation enum (DataSelections)
Function Output/Parameters: none
Function Output/Returned: updated set data (SetType)
Device Input/---: none
Device Output/---: none
Dependencies: getRandBetween, isInSet
*/
SetType initializeSet( SetType setData, int setCapacity,
                     int startVal, int numItems, DataSelections dataContained );

/*
Name: isInSet
Process: searches for given value in set,
         if found, returns true, otherwise returns false,
         must return found result immediately upon finding value
Function Input/Parameters: set (const SetType),
                           search value
Function Output/Parameters: none
Function Output/Returned: Boolean result of test, as specified
Device Input/---: none
Device Output/---: none
Dependencies: none
*/
bool isInSet( const SetType testSet, int searchVal );

/*
Name: isSubsetOf
Process: compares two sets to find if one is a subset of the other,
         returns Boolean result of test,
         function must return false as soon as a subset value is not found
Function Input/Parameters: two sets (const SetType)
Function Output/Parameters: none
Function Output/Returned: Boolean result of test, as specified
Device Input/---: none
Device Output/---: none
Dependencies: none
*/
bool isSubSetOf( const SetType oneSet, const SetType psbleSubset );

/*
Name: runBubbleSort
Process: sorts Set values using bubble sort algorithm
Function input/parameters: set data (SetType)                           
Function output/parameters: none
Function output/returned: updated set data (SetType)
Device input/---: none
Device output/---: none
Dependencies: swapValues
*/
SetType runBubbleSort( SetType setData );

/*
Name: runInsertionSort
Process: sorts set values using insertion sort algorithm
Function input/parameters: set data (SetType)
Function output/parameters: none
Function output/returned: updated set data (SetType)
Device input/---: none
Device output/---: none
Dependencies: none
*/
SetType runInsertionSort( SetType setData );

/*
Name: runSelectionSort
Process: sorts set values using selection sort algorithm
Function input/parameters: set data (SetType)
Function output/parameters: none
Function output/returned: updated set data (SetType)
Device input/---: none
Device output/---: none
Dependencies: swapValues
*/
SetType runSelectionSort( SetType setData );

/*
Name: swapValues
Process: swaps data between two set data quantities (integers)
Function input/parameters: two value pointers (int *),
                           function must be called with addresses
Function output/parameters: none
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: none
*/
void swapValues( int *one, int *other );


#endif     // SET_UTILITIES_H


