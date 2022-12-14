#include "SetUtilitiesTwo.h"

const char ENDLINE[] = "\n";
const char COMMASPACE[] = ", ";

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
SetType addItem( SetType setData, int newValue )
{
    // if the new value is not already in the set and set is not at capacity
    if (!isInSet(setData, newValue) && setData.size < setData.capacity)
    {
        // add the new value at the end
        setData.setArray[setData.size] = newValue;
        // increment its size
        setData.size++;
    }

    return setData;
}

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
SetType copySet( SetType dest, const SetType source )
{
    // init variables
    int index;

    dest.size = source.size;
    dest.capacity = source.capacity;

    // loop through both sets
    for (index = 0; index < source.size; index++)
    {
        // set each index to the value of the source index and increase size
        dest.setArray[index] = source.setArray[index];
    }

    return dest;
}

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
SetType deleteItem( SetType setData, int itemToDelete )
{

    // init variables
    bool searching = true;
    bool found = false;
    int index;

    // loop through the set
    for (index = 0; index < setData.size; index++)
    {
        // if we find the item to delete, stop searching
        if (searching && setData.setArray[index] == itemToDelete )
        {
            found = true;
            searching = false;
        }
        // if we are not seaching move the rest of the items down
        if (!searching)
        {
            // loop through the rest of the set moving the items down by one
            setData.setArray[index] = setData.setArray[index + 1];
        }
        
    }

    // if we did find it reduce the size before returning
    if (found)
    {
        setData.size--;
    }
    
    return setData;
}

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
void displaySet( const char *setName, const SetType setData )
{
    // init variables
    int index;

    // display set name
    printf(ENDLINE);
    printf("%s Set Data Display", setName);
    printf(ENDLINE);

    //Check if the set size is 0: Display "Empty Set" if true
    if (setData.size == 0)
    {
        printf("Empty Set");
        printf(ENDLINE);
    }
    else
    {
        //display the first value
        printf("%i", setData.setArray[0]);

        //Loop through the set displaying each value until we reached end of set
        for (index = 1; index < setData.size; index++)
        {
            //display each value starting with inedx 1 with a comma-space before
            printf(COMMASPACE);
            printf("%i", setData.setArray[index]);
        }
    }
    printf(ENDLINE);
}

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
                                 const SetType oneSet, const SetType otherSet )
{
    // init variables
    int oneIndex;

    // first set the new set size;
    intersectSet.size = 0;

    // check if sets are not size 0
    if (oneSet.size == 0 || otherSet.size == 0)   
    {
        return intersectSet;
    }

    // loop through the first array
    for (oneIndex = 0; oneIndex < oneSet.size; oneIndex++)
    {
        // if a value is in both sets
        if (isInSet(otherSet, oneSet.setArray[oneIndex]))
        {
            // append it to the intersetion and increment its size
            intersectSet.setArray[intersectSet.size] = 
                                                      oneSet.setArray[oneIndex];
            intersectSet.size++;

        }
    }
    return intersectSet;
}

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
                                 const SetType oneSet, const SetType otherSet )
{
    // init variables
    int otherIndex;

    // first copy one set to the union
    unionSet = copySet(unionSet, oneSet);

    //loop through the other set
    for (otherIndex = 0; otherIndex < otherSet.size; otherIndex++)
    {
        // if a value is not in the union set
        if (!isInSet(unionSet, otherSet.setArray[otherIndex]))
        {
            // add it and increase union size
            unionSet.setArray[unionSet.size] = otherSet.setArray[otherIndex];
            unionSet.size++;
        }

    }

    return unionSet;
}

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
int getRandBetween( int lowVal, int highVal )
{
    int range = highVal - lowVal + 1;

    return rand() % range + lowVal;
}

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
                     int startVal, int numItems, DataSelections dataContained )
{
    int incrementor;
    int index;
    int randomNumber;
    int currVal = startVal;

    setData.size = 0;

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
    
    case RANDOM:

        index = 0;
        while(setData.size < numItems)
        {
            randomNumber = getRandBetween(THREE_DIGIT_LOW, THREE_DIGIT_HIGH);
            
            if (!isInSet(setData, randomNumber))
            {
                // set the data to the current value
                setData.setArray[index] = randomNumber;

                setData.size++;
                index++;
            }
        }
        break;
    }

    // if the selection is not random, treat the values differently
    if(dataContained != RANDOM)
    {

        // loop through the index of intArray incrementing the index and currVal
        for (index = 0; index < numItems; index++, currVal += incrementor)
        {
            // set the data to the current value
            setData.setArray[index] = currVal;

            setData.size++;
        }
    }

    return setData;
}

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
bool isInSet( const SetType testSet, int searchVal )
{
    // init variables
    int index;

    // loop through the set
    for (index = 0; index < testSet.size; index++)
    {
        // if we find the value return true
        if (testSet.setArray[index] == searchVal)
        {
            return true;
        }
    }
    // if we exit the loop return false
    return false;
}

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
bool isSubSetOf( const SetType oneSet, const SetType psbleSubset )
{
    bool isSubset;

    int oneSetIndex;
    int oneSetTestIndex;
    int psbleSubsetIndex = 0;

    // loop through the length of oneSet - (length of possible subset)
    for (oneSetIndex = 0; oneSetIndex < oneSet.size - psbleSubset.size;
                                                                  oneSetIndex++)
    {
        // if the beginning of the psblesubset matches a value at current index
        if (psbleSubset.setArray[0] == oneSet.setArray[oneSetIndex])
        {

            // the elements have matched, assume innocent until proven guilty
            isSubset = true;

            // we already confirmed the first match so start at the next
            oneSetTestIndex = oneSetIndex + 1;
            psbleSubsetIndex = 1;

            // loop until we disprove subset or have finished the array
            while ( isSubset && psbleSubsetIndex < psbleSubset.size)
            {
                // if we dont have a match exit loop
                if (psbleSubset.setArray[psbleSubsetIndex] != 
                                               oneSet.setArray[oneSetTestIndex])
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
SetType runBubbleSort( SetType setData )
{

    // init variables
    bool sorted;
    int index;
    
    // loop while we are not sorted
    while(!sorted)
    {

        // for each loop assume we are sorted untill proven otherwise
        sorted = true;

        // loop through the array until we hit size - 1
        for (index = 0; index < setData.size - 1; index++)
        {

            // if the current index is greater than the next
            if (setData.setArray[index] > setData.setArray[index + 1])
            {
                // since we need to swap, we are not sorted
                sorted = false;

                // swap them
                swapValues(&setData.setArray[index], 
                                                  &setData.setArray[index + 1]);
            }
        }
        
    }

    return setData;
}

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
SetType runInsertionSort( SetType setData )
{
    // init variables
    int index, current;
    int temp;

    // loop thorugh the set starting at 1 so we can check behind
    for (index = 1; index < setData.size; index++)
    {
        // set current to the current index
        current = index;

        // while our previous is greater than our current 
        // and our current is not at the beginning of the array
        while (current > 0 && 
                      setData.setArray[current - 1] > setData.setArray[current])
        {
            // move current down the array
            temp = setData.setArray[current - 1];
            setData.setArray[current - 1] = setData.setArray[current];
            setData.setArray[current] = temp;
            current--;
        } 
    }

    // return the set
    return setData;
}

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
SetType runSelectionSort( SetType setData )
{
    int index;
    int currentMinIndex;
    int searchItemIndex;

    // loop through the array
    for (index = 0; index < setData.size - 1; index++)
    {
        // set current min
        currentMinIndex = index;

        // loop through the rest looking for min
        for (searchItemIndex = index + 1; 
                              searchItemIndex < setData.size; searchItemIndex++)
        {
            // if we find a tiem less than current min
            if(setData.setArray[searchItemIndex] < 
                                              setData.setArray[currentMinIndex])
            {
                // set current min
                currentMinIndex = searchItemIndex;
            }
        }
        // swap current min for the current index
        swapValues(&setData.setArray[index],&setData.setArray[currentMinIndex]);
    }

    // reutrn the sorted data
    return setData;
}

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
void swapValues( int *one, int *other )
{
    int temp = *one;

    *one = *other;

    *other = temp;
}


