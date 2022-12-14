#ifndef BST_UTILITY_H
#define BST_UTILITY_H

// header files
#include <stdlib.h>
#include <stdio.h>
#include "StandardConstants.h"

// Constants

typedef enum { ROOM_NUM_CAPACITY = 10, SETUP_CAPACITY = 42, 
                                       BUILDING_ROOM_CAPACITY = 72 } Capacities;

// Data Structures

typedef struct TreeNodeStruct
   {
    char roomNumber[ ROOM_NUM_CAPACITY ];

    char buildingRoom[ BUILDING_ROOM_CAPACITY ];

    char classSetup[ SETUP_CAPACITY ];

    int roomCapacity;

    struct TreeNodeStruct *leftChildPtr, *rightChildPtr;
   } TreeNodeType;

// prototypes

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
TreeNodeType *clearTree( TreeNodeType *wkgPtr );

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
int compareRoomNumbers( const char *roomNbrOne, const char *roomNbrTwo );

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
TreeNodeType *copyTree( TreeNodeType *wkgPtr );

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
void copyString( char *destStr, const char *srcStr );

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
                   const char *buildingRm, const char *clsSetup, int capacity );

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
TreeNodeType *createTreeNodeFromNode( const TreeNodeType sourceNode );

/*
Name: displayInOrder
Process: recursively displays tree using in order traversal
Function input/parameters: working pointer for recursion (TreeNodeType *)
Function output/parameters: none
Function output/returned: none
Device input/---: none
Device output/monitor: displayed as specified
Dependencies: printf, displayInOrder (recursively)
*/
void displayInOrder( TreeNodeType *wkgPtr );

/*
Name: displayPostOrder
Process: recursively displays tree using post order traversal
Function input/parameters: working pointer for recursion (TreeNodeType *)
Function output/parameters: none
Function output/returned: none
Device input/---: none
Device output/monitor: displayed as specified
Dependencies: printf, displayPostOrder (recursively)
*/
void displayPostOrder( TreeNodeType *wkgPtr );

/*
Name: displayPreOrder
Process: recursively displays tree using pre order traversal
Function input/parameters: working pointer for recursion (TreeNodeType *)
Function output/parameters: none
Function output/returned: none
Device input/---: none
Device output/monitor: displayed as specified
Dependencies: printf, displayPreOrder (recursively)
*/
void displayPreOrder( TreeNodeType *wkgPtr );

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
int getStringLength( const char *str );

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
int getStringLengthHelper( const char *str, int index );

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
void initializeBST( TreeNodeType **bstPtr );

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
TreeNodeType *insert( TreeNodeType *wkgPtr, const TreeNodeType inData );

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
bool isDigit( char testVal );

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
bool isEmpty( TreeNodeType *rootPtr);

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
TreeNodeType *removeFromMin( TreeNodeType *parentPtr, TreeNodeType *childPtr );

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
                           TreeNodeType **rootPtr, const TreeNodeType outData );

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
                                                   const TreeNodeType outData );

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
TreeNodeType *search( TreeNodeType *wkgPtr, const TreeNodeType searchData );

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
void setTreeNodeData( TreeNodeType *destPtr, const TreeNodeType source );

#endif   // BST_UTILITY_H

