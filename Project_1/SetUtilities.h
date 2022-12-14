#ifndef SET_UTILITIES_H
#define SET_UTILITIES_H

// headers/libraries
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// derived data types
typedef enum { INCREMENTED = 101, ODD, EVEN } DataSelections;
typedef enum { MAX_SET_CAPACITY = 100, MAX_INIT_SET_CAPACITY = 50 }
                                                                ArrayCapacities;

// prototypes

/*
Name: copyArray
Process: copies one array into other, uses source size
Function Input/Parameters: source array (const int *), source array size (int)                         
Function Output/Parameters: destination array (int *)
Function Output/Returned: none
Device Input/---: none
Device Output/---: none
Dependencies: none
*/
void copyArray( int *dest, const int *source, int sourceSize );

/*
Name: displaySet
Process: displays series of set values, or displays "Empty Set" if no values
Function Input/Parameters: name of set array (const char *),
                           set array (const int *, array size (int)
Function Output/Parameters: none
Function Output/Returned: none
Device Input/---: none
Device Output/monitor: data displayed as specified
Dependencies: printf
*/
void displaySet( const char *setName, const int *setArr, int setArrSize );

/*
Name: findIntersection
Process: finds the set intersection between two set arrays,
         assigns to another array,
         loop to find intersection must end when common value found
Function Input/Parameters: sets one and two arrays (const int *),
                           sets one and two array sizes (int)
Function Output/Parameters: found intersection set array (int *)
Function Output/Returned: size of found intersection set array (int)
Device Input/---: none
Device Output/---: none
Dependencies: none
*/
int findIntersection( int *intersectArray, 
                             const int *oneArray, int oneArrSize, 
                                      const int *otherArray, int otherArrSize );

/*
Name: findUnion
Process: finds the set union between two set arrays,
         assigns to another array,
         loop to find union must end when common value found
Function Input/Parameters: sets one and two arrays (const int *),
                           sets one and two array sizes (int)
Function Output/Parameters: none
Function Output/Returned: size of found intersection set array (int)
Device Input/---: none
Device Output/---: none
Dependencies: none
*/
int findUnion( int *unionArray,
                             const int *oneArray, int oneArrSize, 
                                      const int *otherArray, int otherArrSize );

/*
Name: initializeSetArray
Process: initializes a set array with all EVEN values, all ODD values,
         or continually INCREMENTED values, 
         depending on the DataSelections constant provided
Function Input/Parameters: start value, number of items (int),
                           data values generation enum (DataSelections)
Function Output/Parameters: initialized set array (int *)
Function Output/Returned: none
Device Input/---: none
Device Output/---: none
Dependencies: none
*/
void initializeSetArray( int *intArray, 
                     int startVal, int numItems, DataSelections dataContained );

/*
Name: isInSet
Process: searches for given value in set array,
         if found, returns true, otherwise returns false,
         must return found result immediately upon finding value
Function Input/Parameters: set array (const int *),
                           size of array (int),
                           search value
Function Output/Parameters: none
Function Output/Returned: Boolean result of test, as specified
Device Input/---: none
Device Output/---: none
Dependencies: none
*/
bool isInSet( const int *setArray, int size, int searchVal );

/*
Name: isSubsetOf
Process: compares two set arrays to find if one is a subset of the other,
         returns Boolean result of test,
         loop to find subset item must end when common value found
         and function must return false as soon as a subset value is not found
Function Input/Parameters: two set arrays (const int *),
                           sizes of each set array (int)
Function Output/Parameters: none
Function Output/Returned: Boolean result of test, as specified
Device Input/---: none
Device Output/---: none
Dependencies: none
*/
bool isSubSetOf( const int *oneSet, int oneSetArrSize, 
                          const int *psbleSubset, int psbleSubsetArrSize );

#endif     // SET_UTILITIES_H


