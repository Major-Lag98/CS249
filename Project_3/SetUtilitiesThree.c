#include "SetUtilitiesThree.h"

const char ENDLINE[] = "\n";
const char COMMASPACE[] = ", ";

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
bool addItem( SetType *setData, int newValue )
{
    // if the new value is not already in the set and set is not at capacity
    if (!isInSet(setData, newValue) && setData->size < setData->capacity)
    {
        // add the new value at the end
        setData->setArray[setData->size] = newValue;
        // increment its size
        setData->size++;

        // return ture because we added
        return true;
    }

    // return false becasue we didnt add
    return false;
}

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
void copySet( SetType *dest, const SetType source )
{
    // init variables
    int index;

    dest->size = source.size;
    dest->capacity = source.capacity;

    // loop through both sets
    for (index = 0; index < source.size; index++)
    {
        // set each index to the value of the source index and increase size
        dest->setArray[index] = source.setArray[index];
    }
}

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
bool deleteItem( SetType *setData, int itemToDelete )
{
    // init variables
    bool searching = true;
    bool found = false;
    int index;

    // loop through the set
    for (index = 0; index < setData->size; index++)
    {
        // if we find the item to delete, stop searching
        if (searching && setData->setArray[index] == itemToDelete )
        {
            found = true;
            searching = false;
        }
        // if we are not seaching move the rest of the items down
        if (!searching)
        {
            // loop through the rest of the set moving the items down by one
            setData->setArray[index] = setData->setArray[index + 1];
        }
        
    }

    // if we did find it reduce the size before returning
    if (found)
    {
        setData->size--;
    }
    
    return found;
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
Function Input/Parameters: sets one and two(const SetType)
Function Output/Parameters: pointer to result set (SetType *)
Function Output/Returned: none
Device Input/---: none
Device Output/---: none
Dependencies: isInSet
*/
void findIntersection( SetType *intersectSet, 
                                 const SetType oneSet, const SetType otherSet )
{
    // init variables
    int oneIndex;

    // first set the new set size;
    intersectSet->size = 0;

    // check if sets are not size 0
    if (oneSet.size != 0 || otherSet.size != 0)   
    {
        // loop through the first array
        for (oneIndex = 0; oneIndex < oneSet.size; oneIndex++)
        {
            // if a value is in both sets
            if (isInSet(&otherSet, oneSet.setArray[oneIndex]))
            {
                // append it to the intersetion and increment its size
                intersectSet->setArray[intersectSet->size] = 
                                                      oneSet.setArray[oneIndex];
                intersectSet->size++;

            }
        }
    }
}

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
                                 const SetType oneSet, const SetType otherSet )
{
    // init variables
    int otherIndex;

    // first copy one set to the union
    copySet(unionSet, oneSet);

    //loop through the other set
    for (otherIndex = 0; otherIndex < otherSet.size; otherIndex++)
    {
        // if a value is not in the union set
        if (!isInSet(unionSet, otherSet.setArray[otherIndex]))
        {
            // add it and increase union size
            unionSet->setArray[unionSet->size] = otherSet.setArray[otherIndex];
            unionSet->size++;
        }

    }
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
                     int startVal, int numItems, DataSelections dataContained )
{
    int incrementor;
    int index;
    int randomNumber;
    int currVal = startVal;

    setData->size = 0;

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
        while(setData->size < numItems)
        {
            randomNumber = getRandBetween(THREE_DIGIT_LOW, THREE_DIGIT_HIGH);
            
            if (!isInSet(setData, randomNumber))
            {
                // set the data to the current value
                setData->setArray[index] = randomNumber;

                setData->size++;
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
            setData->setArray[index] = currVal;

            setData->size++;
        }
    }
}

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
bool isInSet( const SetType *testSet, int searchVal )
{
    // init variables
    int index;

    // loop through the set
    for (index = 0; index < testSet->size; index++)
    {
        // if we find the value return true
        if (testSet->setArray[index] == searchVal)
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
void runMerge( SetType *setData, int lowIndex, int middleIndex, int highIndex )
{
    // first find the capacity needed for the local array
    int localArrcapacity = highIndex - lowIndex + 1;

    // create the array
    int *lclArray = (int *)malloc(localArrcapacity * sizeof(int));

    // load the data from the source array into the two indices
    int wkgLowIndex, lclLowIndex;
    for (wkgLowIndex = lowIndex, lclLowIndex = 0; wkgLowIndex <= highIndex;
                                                   wkgLowIndex++, lclLowIndex++)
    {
        lclArray[lclLowIndex] = setData->setArray[wkgLowIndex];
    }

    // next calculate the indicies necessary to start and end
    // at the left side group and to start and end as the right side group

    //left
    int leftIndexLow = 0;
    int leftIndexEnd = (highIndex - lowIndex) / 2;
    // right
    int rightIndexLow = leftIndexEnd + 1;
    int rightIndexEnd = highIndex - lowIndex;

    // Loop until either the left or right side group is out of values
    // (first of three loops)
    while (leftIndexLow <= leftIndexEnd && rightIndexLow <= rightIndexEnd)
    {



        // check if the first available value in the left group
        // is less than the first avaliable value in the right group
        if (lclArray[leftIndexLow] < lclArray[rightIndexLow])
        {
            // assign the first available left value
            // to the source array's first available element
            setData->setArray[lowIndex] = lclArray[leftIndexLow];

            // increment the left group index
            leftIndexLow++;
        }
        // otherwise, assume the right group's first available value
        // is less
        else
        {
            // assign the first available right value
            // to the source array's first available element
            setData->setArray[lowIndex] = lclArray[rightIndexLow];

            // increment the right group index
            rightIndexLow++;
        }
        // increment the index for the source array
        lowIndex++;
    }
    // end comparison loop


    // Loop until the left side group is out of values
    // (second of three loops)
    while (leftIndexLow <= leftIndexEnd)
    {
        // assign the first available left value
        // to the source array's first available element
        setData->setArray[lowIndex] = lclArray[leftIndexLow];

        // increment the left group index
        leftIndexLow++;

        // increment the source array's index
        lowIndex++;

    }
    // end left side clean out loop


    // Loop until the right side group is out of values
    // (third of three loops)
    while (rightIndexLow <= rightIndexEnd)
    {
        // assign the first right value to the source array's
        // first available element
        setData->setArray[lowIndex] = lclArray[rightIndexLow];

        // increment the right group index //BOOK TYPO
        rightIndexLow++;

        // increment the source array's index
        lowIndex++;
    }
    // end right side clean out loop

    // free up the memory used for the local array
    free(lclArray);
}

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
void runMergeSort( SetType *setData )
{
    // do nothing if the data is of size 0 or 1 because its already sorted
    if (setData->size > 1)
    {
        // start the breakdown and merge
        runMergeSortHelper(setData, 0, setData->size - 1);
    }
}

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
void runMergeSortHelper( SetType *setData, int lowIndex, int highIndex )
{

    
    // first check if the lower index is less than higher index
    if (lowIndex < highIndex)
    {
        // find the mid point of the local list
        int mid = (lowIndex + highIndex) / 2;

        // call merge sort process for the left side of the list
        runMergeSortHelper(setData, lowIndex, mid);

        // call the merge sort process for the right side of the list
        runMergeSortHelper(setData, mid + 1, highIndex);

        // merge the two lists back together as sorted data
        runMerge(setData, lowIndex, mid, highIndex);
    }   
}

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
int runPartition( SetType *setData, int lowIndex, int highIndex )
{
    // Identify the partition value at the beginning
    // of the array segment (at lowIndex)
    int pivotValue = setData->setArray[lowIndex];

    // set the working index and the pivot index
    // to the low index parameter
    int wkgIndex, pivotIndex = lowIndex;

    // Start a loop across the the array segment
    // from the low index to the high index, inclusive
    // This will use the working index
    for (wkgIndex = lowIndex; wkgIndex <= highIndex; wkgIndex++)
    {
        // check if the value at the current working index
        // is less than the original pivot value
        if (setData->setArray[wkgIndex] < pivotValue)
        {
            // increment the pivot index
            pivotIndex++;

            // swap the value at the working index
            // with the value at the pivot index
            swapValues(&setData->setArray[wkgIndex], 
                                                &setData->setArray[pivotIndex]);
        }
    }
    // end working loop 

    // Swap the original pivot value (at the low index)
    // with the value at the current pivot index
    swapValues(&setData->setArray[lowIndex], &setData->setArray[pivotIndex]);

    // return the pivot index
    return pivotIndex;
}

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
void runQuickSort( SetType *setData )
{
    // if the array is not already obviously sorted
    if (setData->size > 1) 
    {
        // run the first iteration of quicksort
        runQuickSortHelper(setData, 0, setData->size - 1);
    }
}
      
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
Dependencies: runPartition, runQuickSortHelper (Recursive)
*/
void runQuickSortHelper( SetType *setData, int lowIndex, int highIndex )
{
    // first, make sure the lower index of the list
    // is less than the upper index of the list
    if (lowIndex < highIndex)
    {

       // call the partition process to set the pivot value
       // and get its index
       int pivot = runPartition(setData, lowIndex, highIndex);

       // call the quick sort process for the left side of the list
       // to the left of the pivot index
       runQuickSortHelper(setData, lowIndex, pivot - 1);

       // call the quick sort process for the right side of the list
       // to the right of the pivot index
       runQuickSortHelper(setData, pivot + 1, highIndex);
    }
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