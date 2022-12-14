#include "HashUtilities.h"

// constants
const int MINIMUM_HASH_LETTER_COUNT = 7;
const int ITEM_NOT_FOUND = -1;
const bool USED_NODE = true;
const bool UNUSED_NODE = false;

/*
Name: addItemFromData
Process: adds item to hash table using data input,
         sets node to used state
Function input/parameters: hash data (ProbingHashType *), 
                           state name (const char *),
                           average, lowest, and highest temperatures (double),
Function output/parameters: updated hash table data (ProbingHashType *)
Function output/returned: result of operation (bool)
Device input/---: none
Device output/monitor: probing process displayed (in called function)
Dependencies: setHeapNodeFromData, addItemFromStruct
*/
bool addItemFromData( ProbingHashType *heap, const char *stateName, 
                              double avgTemp, double lowTemp, double highTemp )
{
    return true; // TODO
}

/*
Name: addItemFromStruct
Process: adds item to hash table using struct input,
         uses probing as specified in heap data,
         may probe as many as tableSize times
Function input/parameters: hash data (ProbingHashType *), 
                           new item (StateDataType)
Function output/parameters: updated hash table data (ProbingHashType *)
Function output/returned: result of operation (bool)
Device input/---: none
Device output/monitor: probing process displayed
Dependencies: getHashIndex, toPower, printf, dataToString,
              setHeapNodeFromStruct
*/
bool addItemFromStruct( ProbingHashType *heap, StateDataType newItem )
{
    return true; // TODO
}

/*
Name: clearHashTable
Process: clear hash table array, sets size to zero,
         sets probing to NO_PROBING
Function input/parameters: hash data (ProbingHashType *)
Function output/parameters: updated hash table data (ProbingHashType *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: free
*/
void clearHashTable( ProbingHashType *heap ) // to test
{
    // variables
    int index;

    // loop through the entire table
    for (index = 0; index < heap->tableSize; index++)
    {       
        // free the current array stored at the current index
        free(heap[index].array);
        heap[index].array = NULL;

        // set that index flag to NO_PROBING
        heap[index].probeStrategy = NO_PROBING;
    }

    // set table size to 0 now that its cleared
    heap->tableSize = 0;                    
}

/*
Name: compareStates
Process: compares states by name
Function input/parameters: one state and other state (const StateDataType)
Function output/parameters: none
Function output/returned: value representing comparison,
                  greater than zero if first state is greater than second state,
                  less than zero if first state is less than second state,
                  zero if state names and lengths are the same,
                  otherwise, larger state name length is greater
Device input/---: none
Device output/---: none
Dependencies: getStringLength
*/
int compareStates( const StateDataType oneState, 
                                               const StateDataType otherState )
{
    // variables 
    int len1, len2;
    int shortest;
    int index;

    // assign the lengths
    len1 = getStringLength(oneState.name);
    len2 = getStringLength(otherState.name);

    // assume the sortest is the first
    shortest = len1;

    // check if its the second
    if (len1 > len2)
    {
        shortest = len2;
    }


    // run the loop to the end of the shortest length
    for(index = 0; index < shortest; index++)
    {

        // if we find a difference, return appropriately above
        if (oneState.name[index] != otherState.name[index])
        {
            return oneState.name[index] - otherState.name[index];
        }

    }
    // if we run to the end of loop with all characters matching
    // return len1 - len2
    return len1 - len2;
}

/*
Name: copyString
Process: copies string from source to destination
Function input/parameters: source string (const char *)
Function output/parameters: destination string (char *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: none
*/
void copyString( char *dest, const char *source )
{
    // variables
    int index = 0;

    // while we have not reached the end of the source string
    while (source[index] != NULL_CHAR)
    {
        // copy that index over
        dest[index] = source[index];
        // move to next index
        index++;
    }

    // end string c-style
    dest[index] = NULL_CHAR;
}

/*
Name: dataToString
Process: creates string from StateDataType data
Function input/parameters: provided state data (const StateDataType)
Function output/parameters: output string (char *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: sprintf, or other options
*/
void dataToString( char *outStr, const StateDataType state )
{

}

/*
Name: displayHashTable
Process: array data dump of numbered data to screen, 
         shows data where used, shows "Unused" where not
Function input/parameters: provided heap data (const ProbingHashType *)
Function output/parameters: none
Function output/returned: none
Device input/---: none
Device output/monitor: displayed as specified
Dependencies: printf, dataToString
*/
void displayHashTable( const ProbingHashType *heap )
{

}

/*
Name: findItem
Process: finds item in hash table, returns
Function input/parameters: provided search data (const StateDataType),
                           heap (const ProbingHashType *)
Function output/parameters: none
Function output/returned: state data set to struct (StateDataType),
                          or search parameter set to empty node if not found
Device input/---: none
Device output/---: none
Dependencies: findItemIndex, setEmptyHeapNode
*/
StateDataType findItem( const ProbingHashType *heap, StateDataType searchItem )
{
    // variables
    int foundIndex;
    StateDataType item;

    // find the item index if possible
    foundIndex = findItemIndex(heap, searchItem);

    // if we didnt find the item
    if (foundIndex == ITEM_NOT_FOUND)
    {   
        // set the item as empty and return it
        setEmptyHeapNode(&item);
        return item;
    }

    // else return the found item
    return heap->array[foundIndex];
}

/*
Name: findItemIndex
Process: finds item index, using probing strategy provided in heap data,
         otherwise, 
         returns ITEM_NOT_FOUND if search fails after tableSize attempts,
         displays index probing attempts
Function input/parameters: provided search data (const StateDataType),
                           heap (const ProbingHashType *)
Function output/parameters: none
Function output/returned: index or ITEM_NOT_FOUND (int) as specified
Device input/---: none
Device output/monitor: displays probing action, provided in sample run file
Dependencies: getHashIndex, printf, compareStates, toPower, 
              setHeapNodeFromStruct
*/
int findItemIndex( const ProbingHashType *heap, StateDataType searchItem )
{
    // getHashIndex

    // loop through the hash starting at the hashed index 
        // we will loop hasSize times
        // if linear ... its linear (1, 2, 3...)
        // if quadratic, use quadratic method (use toPower)

            // if its in use, 

                // compare states
            //compareStates();

                    // check if we found it

                    // if we found  it
                        // print the data (setheapNodefromStruct)
                        //setHeapNodeFromStruct();
                        // return the index

                // else continue

        // we have looped array size times and did not find it
        // return item not found

    return 0; // TODo
}
    
/*
Name: getHashIndex
Process: finds hashed index for given data item,
         sums integer values of state name characters,
         if state name length is less than MINIMUM_HASH_LETTER_COUNT,
         repeats going over the state letters as needed to meet this minimum
Function input/parameters: provided search data (const StateDataType),
                           heap (const ProbingHashType)
Function output/parameters: none
Function output/returned: array index generated from state name (int)
Device input/---: none
Device output/---: none
Dependencies: getStringLength
*/
int getHashIndex( const ProbingHashType heap, const StateDataType state )
{
    // variables
    int strLength, strOriginalLen;
    int index;
    int sum = 0;

    // get the length of the string and save an original copy
    strLength = getStringLength(state.name);
    strOriginalLen = strLength;

    // check if we need to increase the str len for our loop
    if (strLength < MINIMUM_HASH_LETTER_COUNT)
    {
        strLength = MINIMUM_HASH_LETTER_COUNT;
    }
    
    // loop through the string however many times
    for (index = 0; index < strLength; index++)
    {
        // increment the sum
        sum += (int)state.name[index];

        // loop back around the string when needed
        index %= strOriginalLen;
    }

    // return the hash index
    return sum % heap.tableSize;
}

/*
Name: getStringLength
Process: utility for finding string length
Function input/parameters: given string (const char *)
Function output/parameters: none
Function output/returned: length of string (int)
Device input/---: none
Device output/---: none
Dependencies: none
*/
int getStringLength( const char *str )
{
    // variables
    int index = 0;

    // chile we have yet to reach the end of the string
    while (str[index] != NULL_CHAR)
    {
        // increment the index as count
        index++;
    }

    // return that count
    return index;
}

/*
Name: initializeHeap
Process: creates dynamically allocated heap, 
         creates dynamically allocated array of empty StateDataType items,
         initializes tableSize to given capacity,
         initializes probe strategy to given strategy
Function input/parameters: provided capacity (int),
                           provided probe strategy (ProbeType)
Function output/parameters: none
Function output/returned: pointer to created heap (ProbingHashType *)
Device input/---: none
Device output/---: none
Dependencies: malloc, sizeof, setEmptyHeapNode, 
*/
ProbingHashType *initializeHeap( int capacity, ProbeType probe )
{
    // // variables
    // ProbingHashType newTable;

    // // set the probing type
    // newTable.probeStrategy = probe;

    // // set the current size of the table
    // newTable.tableSize = 0;

    

    return NULL; // TODO
}

/*
Name: removeState
Process: finds item in hash table, removes, 
         sets array location to unused (but does not set any other data),
         returns removed state
Function input/parameters: provided search data (const StateDataType),
                           heap (const ProbingHashType)
Function output/parameters: returned state (StateDataType *)
Function output/returned: Boolean result of action (bool)
Device input/---: none
Device output/---: none
Dependencies: findItemIndex, setHeapNodeFromStruct
*/
bool removeState( StateDataType *removedState, 
                  const StateDataType toBeRemoved, const ProbingHashType heap )
{
    // variables
    int foundIndex;

    // find the item index if possible
    foundIndex = findItemIndex(&heap, toBeRemoved);

    // if we found the item
    if (foundIndex != ITEM_NOT_FOUND)
    {
        // set the removed state for return and return true
        setHeapNodeFromStruct(removedState, heap.array[foundIndex]);
        return true;
    }

    // else return failure
    return false;
}

/*
Name: setEmptyHeapNode
Process: sets given node values to empty string, zero values,
         and Boolean in use variable to false
Function input/parameters: none
Function output/parameters: updated state data struct (StateDataType *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: copyString
*/
void setEmptyHeapNode( StateDataType *node )
{
    // zero the nodes values
    node->averageTemp = 0;
    node->highestTemp = 0;
    node->lowestTemp = 0;

    // set node bool to false
    node->inUse = false;

    // set name to empty string
    copyString(node->name, "");
}

/*
Name: setHeapNodeFromData
Process: sets given values into a given heap struct, 
         using individual struct data
Function input/parameters: provided name (const char *),
                           average, lowest, and highest temperatures (double),
                           and node in use state
Function output/parameters: updated state data pointer (StateDataType *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: copyString
*/
void setHeapNodeFromData( StateDataType *nodePtr, const char *name, double avgTemp, 
                          double lowTemp, double highTemp, bool nodeState )
{
    // set temperatures
    nodePtr->averageTemp = avgTemp;
    nodePtr->highestTemp = highTemp;
    nodePtr->lowestTemp = lowTemp;

    // set the node bool
    nodePtr->inUse = nodeState;

    // set the node name
    copyString(nodePtr->name, name);

}

/*
Name: setHeapNodeFromStruct
Process: sets given values into a given heap struct, 
         using another data struct
Function input/parameters: provided state data source struct 
                           (const StateDataType)
Function output/parameters: updated state data pointer (StateDataType *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: setHeapNodeFromData
*/
void setHeapNodeFromStruct( StateDataType *nodePtr, 
                                                   const StateDataType source )
{
    setHeapNodeFromData(nodePtr, source.name,
                                 source.averageTemp,
                                 source.lowestTemp,
                                 source.highestTemp,
                                 source.inUse);
}

/*
Name: showHashTableStatus
Process: displays array <D>ata values and <U>unused values 
         as a string of letters,
         displays number of items in heap, 
         displays minimum number of contiguous data items,
         displays maximum number of contiguous data items,
         displays number of empty/unused array elements
Function input/parameters: heap (const ProbingHashType)
Function output/parameters: none
Function output/returned: none
Device input/---: none
Device output/monitor: hash data status displayed as specified
Dependencies: sprintf, printf
*/
void showHashTableStatus( const ProbingHashType heap)
{

}

/*
Name: toPower
Process: recursively calculates result of given base to given exponent,
         for exponents >= 0
Function input/parameters: base and exponent (int)
Function output/parameters: none
Function output/returned: result of specified calculations
Device input/---: none
Device output/---: none
Dependencies: toPower (recursively)
*/
int toPower( int base, int exponent )
{

    // if we still have multiples of the base
    if (exponent > 0)
    {
        // return that base multiple times the rest
        return base * toPower(base, exponent - 1);
    }
    // else return 1
    return 1;
}














