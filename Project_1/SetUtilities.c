#include "SetUtilities.h"

const char ENDLINE[] = "\n";
const char TWO_ENDLINES[] = "\n\n";
const char COMMASPACE[] = ", ";

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
void copyArray( int *dest, const int *source, int sourceSize )
{
    int index;

    // loop through the source and set it in the destination same place
    for(index = 0; index < sourceSize; index++)
    {
        dest[index] = source[index];
    }
}

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
void displaySet( const char *setName, const int *setArr, int setArrSize )
{
    // init variables
    int index;

    // display set name
    printf(ENDLINE);
    printf("%s Set Data Display", setName);
    printf(ENDLINE);

    //Check if the set size is 0: Display "Empty Set" if true
    if (setArrSize == 0)
    {
        printf("Empty Set");
        printf(ENDLINE);
    }
    else
    {
        //display the first value
        printf("%i", setArr[0]);

        //Loop through the set displaying each value until we reached end of set
        for (index = 1; index < setArrSize; index++)
        {
            //display each value starting with inedx 1 with a comma-space before
            printf(COMMASPACE);
            printf("%i", setArr[index]);
        }
    }
    printf(ENDLINE);
}

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
                                      const int *otherArray, int otherArrSize )
{
    // init variables
    int intersectSize = 0;
    int intersectArrIndex = 0;
    int oneIndex;
    int otherIndex;

    // check if both arrays are not size 0
    if (oneArrSize == 0 || otherArrSize == 0)   
    {
        return 0;
    }

    // loop through the first array
    for (oneIndex = 0; oneIndex < oneArrSize; oneIndex++)
    {
        // loop through the second array
        for (otherIndex = 0; otherIndex < otherArrSize; otherIndex++)
        {
            // if the value of the first array matches the second
            if (oneArray[oneIndex] == otherArray[otherIndex])
            {
                // append it to the intersection
                intersectArray[intersectArrIndex] = oneArray[oneIndex];
                // increment the size of intersection
                intersectSize++;
                // increment the index
                intersectArrIndex++;
            }   
        }
    }
    // return size of new intersection array
    return intersectSize;
}

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
                                      const int *otherArray, int otherArrSize )
{
    // init variables
    bool duplicate;
    int unionIndex = 0;
    int unionSize = 0;
    int tempIndex;
    int oneIndex;
    int otherIndex = 0;


    // add oneArr to the union
    for (oneIndex = 0; oneIndex < oneArrSize; oneIndex++)
    {
        unionArray[unionIndex] = oneArray[oneIndex];
        unionIndex++;
        unionSize++;
    }

    // add otherArr to the union while excluding duplicates
    for (otherIndex = 0; otherIndex < otherArrSize; otherIndex++)
    {
        // each otherArr value is innocent until proven guilty
        duplicate = false;

        // check every value in the current union
        for (tempIndex = 0; tempIndex < unionSize; tempIndex++)
        {
            // test if current value is a duplicate
            if (unionArray[tempIndex] == otherArray[otherIndex])
            {
                // GUILTY
                duplicate = true;
            }
        }

        // if its not a duplicate
        if(!duplicate)
        {
            // add it to the union
            unionArray[unionIndex] = otherArray[otherIndex];
            // increment all that has changed
            //otherIndex++;
            unionIndex++;
            unionSize++;
        }
    }


    return unionSize;
}

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
                     int startVal, int numItems, DataSelections dataContained )
{
    int incrementor;
    int index;
    int currVal = startVal;

    // decides what the incrementor is.
    // ODD and EVEN being 2
    // INCREMENTED being 1
    switch (dataContained)
    {
    case INCREMENTED:
        incrementor = 1;
        break;
    
    case ODD:
        // if the staring value is even make it odd
        if (currVal % 2 == 0)
        {
            currVal++;
        }
        incrementor = 2;
        break;

    case EVEN:
        // if the starting value is odd, make it even
        if (currVal % 2 != 0)
        {
            currVal++;
        }
        incrementor = 2;
        break;
    }

    // loop through the index of intArray incrementing the index and currVal
    for (index = 0; index < numItems; index++, currVal += incrementor)
    {
        // set the data to the current value
        intArray[index] = currVal;
    } 
}

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
bool isInSet( const int *setArray, int size, int searchVal )
{
    // init variables
    int index;

    // loop through the given set
    for (index = 0; index < size; index++)
    {
        // check if the current index is the value
        if(setArray[index] == searchVal)
        {
            // return true if so
            return true;
        }
    }
    // we have exausted all values, searchVal Does not exist
    return false;
}

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
                          const int *psbleSubset, int psbleSubsetArrSize )
{

    bool isSubset;

    int oneSetIndex;
    int oneSetTestIndex;
    int psbleSubsetIndex = 0;

    // loop through the length of oneSet - (length of possible subset)
    for (oneSetIndex = 0; oneSetIndex < oneSetArrSize - psbleSubsetArrSize;
                                                                  oneSetIndex++)
    {
        // if the beginning of the psblesubset matches a value at current index
        if (psbleSubset[0] == oneSet[oneSetIndex])
        {

            // the elements have matched, assume innocent until proven guilty
            isSubset = true;

            // we already confirmed the first match so start at the next
            oneSetTestIndex = oneSetIndex + 1;
            psbleSubsetIndex = 1;

            // loop until we disprove subset or have finished the array
            while ( isSubset && psbleSubsetIndex < psbleSubsetArrSize)
            {
                // if we dont have a match exit loop
                if (psbleSubset[psbleSubsetIndex] != oneSet[oneSetTestIndex])
                {
                    isSubset = false;
                }
                else 
                {
                    // else increment the index to test in the next loop
                    psbleSubsetIndex++;
                    oneSetTestIndex++;
                }
            }

            // if we exit the loop with it being a subset return true
            if (isSubset)
            {
                return true;
            }           
        }
    }
    // we have gone through both arrays return false
    return false; 
}