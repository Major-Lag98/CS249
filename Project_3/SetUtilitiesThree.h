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
         does not allow data to be added to full list,
         returns true if successful, false otherwise
Function Input/Parameters: new item (int)
Function Output/Parameters: pointer to set data (SetType)
Function Output/Returned: Boolean result of action
Device Input/---: none
Device Output/---: none
Dependencies: isInSet
*/
bool addItem( SetType *setData, int newValue );

/*
Name: copySet
Process: copies all data of one set into other
Function Input/Parameters: source set (const SetType)
Function Output/Parameters: pointer to destination set (SetType)
Function Output/Returned: none
Device Input/---: none
Device Output/---: none
Dependencies: none
*/
void copySet( SetType *dest, const SetType source );

/*
Name: deleteItem
Process: searches for item, deletes if found,
         moves array data down by one from above the removed value,
         test loop must stop as soon as item is found (if it is found),
         returns true if item found and removed, false otherwise
Function Input/Parameters: item to delete (int)
Function Output/Parameters: pointer to setData (SetType *) 
Function Output/Returned: none
Device Input/---: none
Device Output/---: none
Dependencies: none
*/
bool deleteItem( SetType *setData, int itemToDelete );

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
Function Input/Parameters: sets one and two(const SetType)
Function Output/Parameters: pointer to result set (SetType *)
Function Output/Returned: none
Device Input/---: none
Device Output/---: none
Dependencies: isInSet
*/
void findIntersection( SetType *intersectSet, 
                                 const SetType oneSet, const SetType otherSet );

/*
Name: findUnion
Process: finds the set union between two sets,
         assigns to another set,
         loop to find union must end when common value found
Function Input/Parameters: sets one and two(const SetType)
Function Output/Parameters: pointer to result set (SetType *)
Function Output/Returned: none
Device Input/---: none
Device Output/---: none
Dependencies: copySet, isInSet
*/
void findUnion( SetType *unionSet, 
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
Function Input/Parameters: start value, number of items (int),
                           capacity of array (int),
                           data values generation enum (DataSelections)
Function Output/Parameters: pointer to set data (SetType *)
Function Output/Returned: none
Device Input/---: none
Device Output/---: none
Dependencies: getRandBetween, isInSet
*/
void initializeSet( SetType *setData, int setCapacity,
                     int startVal, int numItems, DataSelections dataContained );

/*
Name: isInSet
Process: searches for given value in set,
         if found, returns true, otherwise returns false,
         must return found result immediately upon finding value
Function Input/Parameters: pointer to set (const *SetType),
                           search value
Function Output/Parameters: none
Function Output/Returned: Boolean result of test, as specified
Device Input/---: none
Device Output/---: none
Dependencies: none
*/
bool isInSet( const SetType *testSet, int searchVal );

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
Name: runMerge
Process: merges SetType arrays brought in between a low, middle, 
         and high index segment of the array,
         must dynamically create (and release) internal array
         must use three array transfer loops
Function input/parameters: pointer to set (SetType *), 
                           low index, middle index, high index (int)                           
Function output/parameters: pointer to updated set (SetType *)
Function output/returned: none
Device input/file: none
Device output/monitor: none
Dependencies: malloc, free
*/
void runMerge( SetType *setData, int lowIndex, int middleIndex, int highIndex );

/*
Name: runMergeSort
Process: sorts Set data using merge sort algorithm,
         calls helper function with appropriate indices
Function input/parameters: pointer to set data (SetType *)
Function output/parameters: pointer to updated set data (SetType *)
Function output/returned: none
Device input/file: none
Device output/monitor: none
Dependencies: runMergeSortHelper
*/
void runMergeSort( SetType *setData );

/*
Name: runMergeSortHelper
Process: recursively breaks given set segments down 
         to smaller segments between lowIndex and highIndex (inclusive),
         then sorts data using merge sort function for segments created
Function input/parameters: pointer to setData (SetType *), 
                           low & high inclusive indices (int)
Function output/parameters: pointer to updated setData (SetType *)
Function output/returned: none
Device input/file: none
Device output/monitor: none
Dependencies: runMergeSortHelper (recursive), runMerge
*/
void runMergeSortHelper( SetType *setData, int lowIndex, int highIndex );

/*
Name: runPartition
Process: partitions set data using the first value as the partition value;
         when this function is complete the partition value is
         in the correct location in the array
Function input/parameters: pointer to set data (SetType *)
Function output/parameters: pointer to updated set data (SetType *)
Function output/returned: partition value index within array
Device input/file: none
Device output/monitor: none
Dependencies: swapValues
*/
int runPartition( SetType *setData, int lowIndex, int highIndex );

/*
Name: runQuickSort
Process: sorts set data using quick sort algorithm,
         calls helper with appropriate indices to implement sort
Function input/parameters: pointer to set data (SetType *)
Function output/parameters: pointer to updated set data (SetType *)
Function output/returned: none
Device input/file: none
Device output/monitor: none
Dependencies: runQuickSortHelper
*/
void runQuickSort( SetType *setData );
      
/*
Name: runQuickSortHelper
Process: helper function run with parameters that partition arrays
         on a given (first) element of an array segment,
         then recursively sort left and right sides of given partition value
Function input/parameters: pointer to set data (SetType *) 
         low & high inclusive indices (int)
Function output/parameters: pointer to updated set data (SetType *)
Function output/returned: none
Device input/file: none
Device output/monitor: none
Dependencies: runPartition, runQuickSortHelper
*/
void runQuickSortHelper( SetType *setData, int lowIndex, int highIndex );

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


