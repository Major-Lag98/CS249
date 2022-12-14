#include "BST_Utility.h"

/*
Name: clearTree
Process: recursively returns dynamically allocated data to the OS,
         uses post order traversal strategy
Function input/parameters: head pointer (StudentDataType *)
Function output/parameters: none
Function output/returned: empty tree (NULL)
Device input/---: none
Device output/---: none
Dependencies: free, clearTree (recursively)
*/
TreeNodeType *clearTree( TreeNodeType *wkgPtr )
{
    // if wkgptr has data
    if (wkgPtr != NULL)
    {
        // recrse left
        wkgPtr->leftChildPtr = clearTree(wkgPtr->leftChildPtr);

        //recurse right
        wkgPtr->rightChildPtr = clearTree(wkgPtr->rightChildPtr);

        // free data
        free(wkgPtr);
    }

    return NULL;
}

/*
Name: compareRoomNumbers
Process: compares room numbers as follows:
         - if left room number is greater than the right room number, 
         returns value greater than zero (not necessarily 1)
         - if left room number is less than the right room number, 
         returns value less than zero (not necessarily -1)
         - if room numbers are equal but one is longer, longer one is greater
         - otherwise, returns zero
Function input/parameters: two room numbers (as strings)
                           to be compared (const char *)
Function output/parameters: none
Function output/returned: result as specified above (int)
Device input/---: none
Device output/---: none
Dependencies: isDigit
*/
int compareRoomNumbers( const char *roomNbrOne, const char *roomNbrTwo )
{
    int roomOneLen, roomTwoLen;
    int longest;
    int index;

    // check if we have data
    if (roomNbrOne != NULL && roomNbrTwo != NULL)
    {

        // get the length of both
        roomOneLen = getStringLength(roomNbrOne);
        roomTwoLen = getStringLength(roomNbrTwo);

        // assume roomOne is longest
        longest = roomOneLen;

        // check if room two is longer
        if (roomTwoLen > roomOneLen)
        {
            longest = roomTwoLen;
        }

        // loop through the strings compairing each digit
        for (index = 0; index < longest; index++)
        {
            // if the two numbers at the index are different and digits
            if (roomNbrOne[index] != roomNbrTwo[index] 
                    && isDigit(roomNbrOne[index]) && isDigit(roomNbrTwo[index]))
            {
                // return the difference
                return roomNbrOne[index] - roomNbrTwo[index];
            }
        }
    }
    // else return 0
    return 0;
}

/*
Name: copyTree
Process: recursively duplicates the provided tree
         using a pre order traversal strategy
Function input/parameters: working pointer for recursion (TreeNodeType *)
Function output/parameters: none
Function output/returned: pointer to duplicate tree (TreeNodeType *)
Device input/---: none
Device output/---: none
Dependencies: createTreeNodeFromNode
*/
TreeNodeType *copyTree( TreeNodeType *wkgPtr ) // WIP
{
    TreeNodeType *headPtrCpy = NULL;

    // first check for null
    if (wkgPtr != NULL)
    {
        // copy first
        headPtrCpy = createTreeNodeFromNode(*wkgPtr);

        // recurse left
        headPtrCpy->leftChildPtr = copyTree(wkgPtr->leftChildPtr);

        // recurse right
        headPtrCpy->rightChildPtr = copyTree(wkgPtr->rightChildPtr);
    }

    // return the head
    return headPtrCpy;
}

/*
Name: copyString
Process: copies source string to destination string
Function input/parameters: source string (const char *)
Function output/parameters: destination string (char *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: none
*/
void copyString( char *destStr, const char *srcStr )
{
    int index = 0;

    while (srcStr[index] != NULL_CHAR)
    {
        destStr[index] = srcStr[index];
        index++;
    }

    // end string c-style
    destStr[index] = NULL_CHAR;

}

/*
Name: createTreeNodeFromData
Process: captures data from individual data items, 
         dynamically creates new node,
         copies data, sets child pointers to NULL,
         and returns pointer to new node         
Function input/parameters: room number, building room, 
                           class setup (const char *), and capacity (int)
Function output/parameters: none
Function output/returned: pointer to new node as specified (TreeNodeType *)
Device input/---: none
Device output/---: none
Dependencies: malloc, sizeof, copyString
*/
TreeNodeType *createTreeNodeFromData( const char *rmNumber, 
                   const char *buildingRm, const char *clsSetup, int capacity )
{
    // init variables
    TreeNodeType *newNode;

    // malloc memory size of treeNodeType
    newNode = (TreeNodeType * )malloc(sizeof(TreeNodeType));

    // copy the room number to node
    copyString(newNode->roomNumber, rmNumber);

    // copy the building number to node
    copyString(newNode->buildingRoom, buildingRm);

    // copy the class setup to node
    copyString(newNode->classSetup, clsSetup);

    // copy the capacity to node
    newNode->roomCapacity = capacity;

    // set left & right to null
    newNode->leftChildPtr = NULL;
    newNode->rightChildPtr = NULL;

    return newNode;
}

/*
Name: createTreeNodeFromNode
Process: captures data from source node pointer, dynamically creates new node,
         copies data, sets child pointers to NULL, 
         and returns pointer to new node         
Function input/parameters: node to be copied (const TreeNodeType)
Function output/parameters: none
Function output/returned: pointer to new node as specified (TreeNodeType *)
Device input/---: none
Device output/---: none
Dependencies: variable options
*/
TreeNodeType *createTreeNodeFromNode( const TreeNodeType sourceNode )
{
    return createTreeNodeFromData(  sourceNode.roomNumber,
                                    sourceNode.buildingRoom,
                                    sourceNode.classSetup,
                                    sourceNode.roomCapacity );
}

/*
Name: displayInOrder
Process: recursively displays tree using in order traversal
Function input/parameters: working pointer for recursion (TreeNodeType *)
Function output/parameters: none
Function output/returned: none
Device input/---: none
Device output/monitor: displayed as specified
Dependencies: //printf, displayInOrder (recursively)
*/
void displayInOrder( TreeNodeType *wkgPtr )
{
    // check if null
    if (wkgPtr != NULL)
    {
        // recurse left
        displayInOrder(wkgPtr->leftChildPtr);
        // print current
        printf("%s: %s\n", wkgPtr->roomNumber, wkgPtr->buildingRoom);
        // recurse right
        displayInOrder(wkgPtr->rightChildPtr);
    }
}

/*
Name: displayPostOrder
Process: recursively displays tree using post order traversal
Function input/parameters: working pointer for recursion (TreeNodeType *)
Function output/parameters: none
Function output/returned: none
Device input/---: none
Device output/monitor: displayed as specified
Dependencies: //printf, displayPostOrder (recursively)
*/
void displayPostOrder( TreeNodeType *wkgPtr )
{
    // check if null
    if (wkgPtr != NULL)
    {
        // recurse left
        displayPostOrder(wkgPtr->leftChildPtr);
        // recurse right
        displayPostOrder(wkgPtr->rightChildPtr);
        // print current
        printf("%s: %s\n", wkgPtr->roomNumber, wkgPtr->buildingRoom);
    }
}

/*
Name: displayPreOrder
Process: recursively displays tree using pre order traversal
Function input/parameters: working pointer for recursion (TreeNodeType *)
Function output/parameters: none
Function output/returned: none
Device input/---: none
Device output/monitor: displayed as specified
Dependencies: //printf, displayPreOrder (recursively)
*/
void displayPreOrder( TreeNodeType *wkgPtr )
{
    // check if null
    if (wkgPtr != NULL)
    {
        // print current
        printf("%s: %s\n", wkgPtr->roomNumber, wkgPtr->buildingRoom);
        // recurse left
        displayPreOrder(wkgPtr->leftChildPtr);
        // recurse right
        displayPreOrder(wkgPtr->rightChildPtr);
        
        
    }
}

/*
Name: getStringLength
Process: returns length of c-style string using helper function
Function input/parameters: string (const char *)
Function output/parameters: none
Function output/returned: string length (int)
Device input/---: none
Device output/---: none
Dependencies: getStringLengthHelper
*/
int getStringLength( const char *str )
{
    int index = 0;
    return getStringLengthHelper(str, index);
}

/*
Name: getStringLengthHelper
Process: recursively iterates across string to find length
Function input/parameters: string to be tested (const char *),
                           index for recursion
Function output/parameters: none
Function output/returned: length of string (int)
Device input/---: none
Device output/---: none
Dependencies: getStringLengthHelper (recursively)
*/
int getStringLengthHelper( const char *str, int index )
{
    if (str[index] != NULL_CHAR)
    {
        index = getStringLengthHelper(str, index + 1);
    }
    return index;
}

/*
Name: initializeBST
Process: sets BST root pointer to NULL, root pointer is returned by address
Function input/parameters: address of working pointer (TreeNodeType **)
Function output/parameters: address of updated working pointer 
                            (TreeNodeType **)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: none
*/
void initializeBST( TreeNodeType **bstPtr )
{
    *bstPtr = NULL;
}

/*
Name: insert
Process: recursively searches for available node in BST,
         creates new node and returns it to the calling function,
         if node is already in tree, data is overwritten,
         uses "look down" strategy for adding nodes to tree
Function input/parameters: working pointer for recursion (TreeNodeType *),
                           node to be inserted (const TreeNodeType)
Function output/parameters: none
Function output/returned: pointer to root node (TreeNodeType *)
Device input/---: none
Device output/---: none
Dependencies: compareRoomNumbers, setTreeNodeData, createTreeNodeFromNode,
              insert (recursively)
*/
TreeNodeType *insert( TreeNodeType *wkgPtr, const TreeNodeType inData )
{


    // init variables
    int comparison;

    // If room_1 > room_2, result > 0; < 0 otherwise.
    // If null or same, result = 0
    comparison = compareRoomNumbers(inData.roomNumber, wkgPtr->roomNumber);

    // if data is null or the same, insert here
    if (comparison == 0)
    {
        // create new node
        wkgPtr = createTreeNodeFromNode(inData);
        
    }
    // else if in data is greater than current
    else if (comparison > 0)
    {
        // if the next is null set it to new node
        if (wkgPtr->rightChildPtr == NULL)
        {
            wkgPtr->rightChildPtr = createTreeNodeFromNode(inData);
        }
        else
        {
            // recurse right
            wkgPtr->rightChildPtr = insert(wkgPtr->rightChildPtr, inData);
        }
    }
    // else data is less than current
    else
    {
        // if the next is null set it to new node
        if (wkgPtr->leftChildPtr == NULL)
        {
            wkgPtr->leftChildPtr = createTreeNodeFromNode(inData);
        }
        else
        {
            // recurse right
            wkgPtr->leftChildPtr = insert(wkgPtr->leftChildPtr, inData);
        }
    }

    // return the root of the tree
    return wkgPtr;
}

/*
Name: isDigit
Process: checks for if digit character,
         one line of code
Function input/parameters: test character (char)
Function output/parameters: none
Function output/returned: result of test as specified (bool)
Device input/---: none
Device output/---: none
Dependencies: none
*/
bool isDigit( char testVal )
{
    // return if the character is the number 9 or less
    return testVal <= '9' && testVal >= '0'; 
}

/*
Name: isEmpty
Process: tests root node for NULL, returns result,
         one line of code
Function input/parameters: pointer to root node (TreeNodeType *)
Function output/parameters: none
Function output/returned: result of test as specified (bool)
Device input/---: none
Device output/---: none
Dependencies: none
*/
bool isEmpty( TreeNodeType *rootPtr)
{
    return rootPtr == NULL;
}

/*
Name: removeFromMin
Process: recursively searches for min node,
         when found, node is unlinked from tree and returned,
         other linkage is managed
Function input/parameters: pointer to parent and child nodes (TreeNodeType *)
Function output/parameters: none
Function output/returned: pointer to removed node (TreeNodeType *)
Device input/---: none
Device output/---: none
Dependencies: removeFromMin (recursively)
*/
TreeNodeType *removeFromMin( TreeNodeType *parentPtr, TreeNodeType *childPtr )
{
    // check if left is null    
    if (childPtr->leftChildPtr != NULL)
    {
        removeFromMin(childPtr, childPtr->leftChildPtr);
    }

    // connect the left of the parent to the right child of the min
    parentPtr->leftChildPtr = childPtr->rightChildPtr;

    // return the min
    return childPtr;
}

/*
Name: removeItem
Process: searches for item, 
         captures removed item, if available, from search pointer, 
         then removes item from tree using helper function and returns true,
         otherwise sets removed node pointer to NULL and returns false
Function input/parameters: address of pointer to root node (TreeNodeType *),
                           node to be removed with at least room number key
Function output/parameters: address of updated root node pointer 
                            (TreeNodeType **), 
                            pointer to removed item node (TreeNodeType *)
Function output/returned: Boolean result of operation (bool)
Device input/---: none
Device output/---: none
Dependencies: search, setTreeNodeData, removeItemHelper
*/
bool removeItem( TreeNodeType *removedNodePtr, 
                           TreeNodeType **rootPtr, const TreeNodeType outData )
{
    TreeNodeType *foundNode = NULL;
    TreeNodeType *removedNode = NULL;

    // find the item, return the item or null if not found
    foundNode = search(*rootPtr, outData);

    // if found node is different from null
    if (foundNode != NULL)
    {   
        // search for the item and remove it
        removedNode = removeItemHelper(*rootPtr, *foundNode);

        // set the removed node
        setTreeNodeData(removedNodePtr, *removedNode);

        return true;
    }   
    return false;
}

/*
Name: removeItemHelper
Process: recursively searches for item, removes node,
         returns dynamic memory of removed node to OS,
         returns updated link to parent (at each recursive level),
         only one return at end of function
Function input/parameters: pointer to working node (TreeNodeType *),
                           node to be removed with at least state name key
                           (const TreeNodeType)
Function output/parameters: none
Function output/returned: link to recursive parent (TreeNodeType *)
Device input/---: none
Device output/---: none
Dependencies: compareRoomNumbers, setTreeNodeData, removeFromMin, free,
              removeItemHelper (recursively)
*/
TreeNodeType *removeItemHelper( TreeNodeType *wkgPtr, 
                                                   const TreeNodeType outData )
{
    TreeNodeType *removedNode = NULL;
    int comparison;

    // check for null
    if (wkgPtr != NULL)
    {
        comparison = compareRoomNumbers(outData.roomNumber, wkgPtr->roomNumber);


        // check if its to the left
        if (comparison < 0)
        {
            // go left
            removeItemHelper(wkgPtr->leftChildPtr, outData);

        }
        // check if its to the right
        if (comparison > 0)
        {
            // go right
            removeItemHelper(wkgPtr->rightChildPtr, outData);
        }

        // else we have it, set, free, and return it
        removedNode = wkgPtr;

        free(wkgPtr);

        return removedNode;

    }

    return NULL;
}

/*
Name: search
Process: recursively searches for item, if found, returns pointer to node,
         otherwise, returns NULL
Function input/parameters: pointer to working node (TreeNodeType *),
                           node to be found with at least state name key
                           (const TreeNodeType)
Function output/parameters: none
Function output/returned: link to found node, or NULL, as specified
Device input/---: none
Device output/---: none
Dependencies: compareRoomNumbers, search (recursively)
*/
TreeNodeType *search( TreeNodeType *wkgPtr, const TreeNodeType searchData )
{
    int comparison;

    // check for null
    if (wkgPtr != NULL)
    {
        comparison = compareRoomNumbers(searchData.roomNumber, 
                                                            wkgPtr->roomNumber);
        // see if the node is to the left
        if (comparison < 0)
        {
            // go there
            wkgPtr->leftChildPtr = search(wkgPtr->leftChildPtr, searchData);
        }
        // see if the node is to te right
        else if (comparison > 0)
        {
            // go there
            wkgPtr->rightChildPtr = search(wkgPtr->rightChildPtr, searchData);
        }
        // i found it - return it
        return wkgPtr;
        
    }
    // return null
    return NULL;
}

/*
Name: setTreeNodeData
Process: copies room data from source node to destination pointer
Function input/parameters: node to be copied (TreeNodeType)
Function output/parameters: destination pointer (TreeNodeType *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: copyString
*/
void setTreeNodeData( TreeNodeType *destPtr, const TreeNodeType source )
{
    // copy all data from source to dest
    
        // building room
    copyString(destPtr->buildingRoom, source.buildingRoom);
    
        // class setup
    copyString(destPtr->classSetup, source.classSetup);
    
        // room number
    copyString(destPtr->roomNumber, source.roomNumber);
    
        // capacity
    destPtr->roomCapacity = source.roomCapacity;

        // left pointer
    destPtr->leftChildPtr = source.leftChildPtr;

        // right pointer
    destPtr->rightChildPtr = source.rightChildPtr;

}