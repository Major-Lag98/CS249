#include "AVL_Tree_Utility.h"

/*
Name: clearTree
Process: recursively removes all nodes from tree and returns memory to OS,
         uses post order traversal strategy
Function input/parameters: pointer to root/ working pointer (AvlTreeNodType *)
Function output/parameters: none
Function output/returned: NULL
Device input/---: none
Device output/---: none
Dependencies: free
*/
AvlTreeNodeType *clearTree( AvlTreeNodeType *wkgPtr )
{
   // check if working pointer is NULL
   if(wkgPtr == NULL)
   {
      // reutrn empty tree
      return NULL;
   }

   // recurse left
   wkgPtr->leftChildPtr = clearTree(wkgPtr->leftChildPtr);

   // recure right
   wkgPtr->rightChildPtr = clearTree(wkgPtr->rightChildPtr);

   // free working pointer
   free(wkgPtr);

   // return NULL
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
   int index = 0;

   // while both numbers equal each other, find longer one
   while(roomNbrOne[index] == roomNbrTwo[index]
                                              && roomNbrOne[index] != NULL_CHAR
                                              && roomNbrTwo[index] != NULL_CHAR)
   {
      // increment index
      index++;
   }

   // else, check if room one is larger than room two
   if(roomNbrOne[index] > roomNbrTwo[index] || roomNbrTwo[index] == NULL_CHAR)
   {
      // return 1
      return 1;
   }

   // else, check if room number two is largest
   else if(roomNbrTwo[index] > roomNbrOne[index]
                                              || roomNbrOne[index] == NULL_CHAR)
   {
      // return -1
      return -1;
   }

   // else, return 0
   return 0;
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
   int index = 0;

   // while string is not at NULL_CHAR
   while(source[index] != NULL_CHAR)
   {
      // copy source string to destination string
      dest[index] = source[index];

      // end string with NULL_CHAR
      dest[index + 1] = NULL_CHAR;

      // incrment index
      index++;
   }
}

/*
Name: copyTree
Process: creates duplicate copy of given tree, allocates all new nodes,
         returns pointer to root of new tree or NULL if original tree was empty,
         uses pre order traversal strategy
Function input/parameters: tree root/working pointer (AvlTreeNodeType *)
Function output/parameters: none
Function output/returned: tree root of copied tree
                          or NULL as specified (AvlTreeNodeType *)
Device input/---: none
Device output/---: none
Dependencies: variable options
*/
AvlTreeNodeType *copyTree( AvlTreeNodeType *rootPtr )
{
   AvlTreeNodeType *headPtrCopy = NULL;

   // check for null
   if(rootPtr != NULL)
   {
      // create new node
      headPtrCopy = createTreeNodeFromNode(*rootPtr);

      // recurse left
      headPtrCopy->leftChildPtr = copyTree(rootPtr->leftChildPtr);

      // recurse right
      headPtrCopy->rightChildPtr = copyTree(rootPtr->rightChildPtr);
   }

   return headPtrCopy;
}

/*
Name: createTreeNodeFromData
Process: captures data from individual data items,
         dynamically creates new node,
         copies data, sets child pointers to NULL,
         and returns pointer to new node
Function input/parameters: room number, building room,
                           and class setup (const char *), capacity (int)
Function output/parameters: none
Function output/returned: pointer to new node as specified (AvlTreeNodeType *)
Device input/---: none
Device output/---: none
Dependencies: malloc, sizeof, copyString
*/
AvlTreeNodeType *createTreeNodeFromData( const char *rmNumber,
                   const char *buildingRm, const char *clsSetup, int capacity )
{
   AvlTreeNodeType *newNode;

   // create struct node
   newNode = (AvlTreeNodeType*)malloc(sizeof(AvlTreeNodeType));

   // copy data
   copyString(newNode->roomNumber, rmNumber);
   copyString(newNode->buildingRoom, buildingRm);
   copyString(newNode->classSetup, clsSetup);
   newNode->roomCapacity = capacity;

   // set children pointers to NULL
   newNode->leftChildPtr = NULL;
   newNode->rightChildPtr = NULL;

   // return the new node
   return newNode;
}

/*
Name: createTreeNodeFromNode
Process: captures data from source node pointer, dynamically creates new node,
         copies data, sets child pointers to NULL,
         and returns pointer to new node,
         one line of code
Function input/parameters: node to be copied (const AvlTreeNodeType)
Function output/parameters: none
Function output/returned: pointer to new node as specified (AvlTreeNodeType *)
Device input/---: none
Device output/---: none
Dependencies: variable options
*/
AvlTreeNodeType *createTreeNodeFromNode( const AvlTreeNodeType sourceNode )
{
   // create struct node
   return createTreeNodeFromData(sourceNode.roomNumber,
                                 sourceNode.buildingRoom,
                                 sourceNode.classSetup,
                                 sourceNode.roomCapacity);
}


/*
Name: displayChars
Process: recursively displays a specified number of characters
Function input/parameters: number of characters (int), output character (char)
Function output/parameters: none
Function output/returned: none
Device input/---: none
Device output/monitor: characters displayed as specified
Dependencies: displayChars (recursively)
*/
void displayChars( int numChars, char outChar )
{
   if(numChars > 0)
   {
      // display characters
      printf("%c", outChar);

      // recurse numchars - 1
      displayChars(numChars - 1, outChar);
   }
}

/*
Name: findBalanceFactor
Process: finds balance factor by subtracting
         height differences between left and right subtrees
Function input/parameters: pointer to current tree location (TreeNodeType *)
Function output/parameters: none
Function output/returned: difference between two subtree heights (int)
Device input/---: none
Device output/---: none
Dependencies: variable options
*/
int findBalanceFactor( AvlTreeNodeType *wkgPtr )
{
   return findTreeHeight(wkgPtr->leftChildPtr) -
                                          findTreeHeight(wkgPtr->rightChildPtr);
}


/*
Name: findMax
Process: finds maximum between two values, returns larger
Function input/parameters: two values (int)
Function output/parameters: none
Function output/returned: larger of two values (int)
Device input/---: none
Device output/---: none
Dependencies: none
*/
int findMax( int one, int other )
{
   // check if one is greater than other
   if(one > other)
   {
      // return one
      return one;
   }

   return other;
   
}


/*
Name: findTreeHeight
Process: recursively finds tree height from current node to bottom of tree
Function input/parameters: pointer to current tree location (AvlTreeNodeType *)
Function output/parameters: none
Function output/returned: -1 if empty tree, 0 if no subtrees,
                          max height of subtrees otherwise
Device input/---: none
Device output/---: none
Dependencies: variable options
*/
int findTreeHeight( AvlTreeNodeType *wkgPtr )
{
   // check if we have data
   if(wkgPtr == NULL)
   {
      return -1;
   }

   // else return 1 + max height of tree
   return 1 + findMax(findTreeHeight(wkgPtr->leftChildPtr),
                                         findTreeHeight(wkgPtr->rightChildPtr));
}


/*
Name: initializeTree
Process: returns NULL to set tree to empty
Function input/parameters: none
Function output/parameters: none
Function output/returned: NULL
Device input/---: none
Device output/---: none
Dependencies: none
*/
AvlTreeNodeType *initializeTree()
{
   return NULL;
}


/*
Name: inOrderDisplay
Process: recursively iterates across tree using in order strategy,
         displays node values
Function input/parameters: pointer to current tree location (AvlTreeNodeType *)
Function output/parameters: none
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: inOrderDisplay (recursively)
*/
void inOrderDisplay( AvlTreeNodeType *wkgPtr )
{
   // check if we have data
   if(wkgPtr != NULL)
   {
      // recurse left
      inOrderDisplay(wkgPtr->leftChildPtr);

      // print node values
      printf("%s, ", wkgPtr->roomNumber);

      // recurse right
      inOrderDisplay(wkgPtr->rightChildPtr);
   }
}


/*
Name: insert
Process: recursively finds location to insert node, inserts node,
         then follows recursion back up tree to implement balancing,
         does not allow duplicate entries
Function input/parameters: pointer to current tree location (AvlTreeNodeType *),
                           room number, building room data, class setup (char *)
Function output/parameters: none
Function output/returned: pointer to calling function/tree node above
                          where function is called
Device input/---: none
Device output/monitor: actions displayed as function progresses
Dependencies: createDataNode, compareRoomNumbers, findBalanceFactor,
              insert (recursively), printf
*/
AvlTreeNodeType *insert( AvlTreeNodeType *wkgPtr,
                     char *rmNmbr, char *bldgRm, char *clsSetup, int capacity )
{
   int comparison, balance;

   // check if working pointer is NULL
   if(wkgPtr == NULL)
   {
      // place data in new node
      wkgPtr = createTreeNodeFromData(rmNmbr, bldgRm, clsSetup, capacity);

      // return working pointer
      return wkgPtr;
   }

   // find room value
   comparison = compareRoomNumbers(rmNmbr, wkgPtr->roomNumber);

   // check if node is to the right
   if(comparison > 0)
   {
      // check if rightChildPtr is empty
      if(wkgPtr->rightChildPtr == NULL)
      {
         // create new tree node for rightChildPtr
         wkgPtr->rightChildPtr =
                     createTreeNodeFromData(rmNmbr, bldgRm, clsSetup, capacity);

         // return working pointer
         return wkgPtr;
      }

      // else, next rightChildPtr has data
      else
      {
         // move to the right
         wkgPtr->rightChildPtr = insert(wkgPtr->rightChildPtr, rmNmbr,
                                                    bldgRm, clsSetup, capacity);
      }
   }

   // else, check if node is to the left
   else if(comparison < 0)
   {
      // check if leftChildPtr is empty
      if(wkgPtr->leftChildPtr == NULL)
      {
         // create new tree node for leftChildPtr
            wkgPtr->leftChildPtr =
                     createTreeNodeFromData(rmNmbr, bldgRm, clsSetup, capacity);

            // return working pointer
            return wkgPtr;
      }

      // else, next leftChildPtr has data
      else
      {
         // move to the left
         wkgPtr->leftChildPtr = insert(wkgPtr->leftChildPtr, rmNmbr,
                                                    bldgRm, clsSetup, capacity);
      }
   }
   else
   {
      return wkgPtr;
   }

   // get balance
   balance = findBalanceFactor(wkgPtr);

   // check if left left case
   if(balance > 1 &&
               compareRoomNumbers(wkgPtr->leftChildPtr->roomNumber, rmNmbr) > 0)
   {
      // display rotation
      printf("  Identitfied: Left Left Case\n");

      // return working pointer
      return rotateRight(wkgPtr);
   }

   // check if left right case
   if(balance > 1 &&
               compareRoomNumbers(wkgPtr->leftChildPtr->roomNumber, rmNmbr) < 0)
   {
      // dipslay rotation
      printf("  Identified: Left Right Case\n");

      // change leftChildPtr to rotate left
      wkgPtr->leftChildPtr = rotateLeft(wkgPtr->leftChildPtr);

      // return wkgPtr
      return rotateRight(wkgPtr);
   }

   // check if right left case
   if(balance < -1 &&
              compareRoomNumbers(wkgPtr->rightChildPtr->roomNumber, rmNmbr) > 0)
   {
      // display rotation
      printf("  Identified: Right Left Case\n");

      // change rightChildPtr
      wkgPtr->rightChildPtr = rotateRight(wkgPtr->rightChildPtr);

      // return wkgPtr
      return rotateLeft(wkgPtr);
   }

   // check if right right case
   if(balance < -1 &&
              compareRoomNumbers(wkgPtr->rightChildPtr->roomNumber, rmNmbr) < 0)
   {
      printf("  Identified: Right Right Case\n");

      // return wkgPtr
      return rotateLeft(wkgPtr);
   }

   return wkgPtr;
}


/*
Name: isDigit
Process: reports if character provided is a character digit
Function input/parameters: test character (char)
Function output/parameters: none
Function output/returned: Boolean result of test (bool)
Device input/---: none
Device output/---: none
Dependencies: none
*/
bool isDigit( char testChar )
{
   return testChar <= '9' && testChar >= '0';
}


/*
Name: isEmpty
Process: reports if tree is empty, using one line of code
Function input/parameters: pointer to current root node (AvlTreeNodeType *)
Function output/parameters: none
Function output/returned: Boolean result of test (bool)
Device input/---: none
Device output/---: none
Dependencies: none
*/
bool isEmpty( AvlTreeNodeType *rootPtr )
{
   return rootPtr == NULL;
}


/*
Name: rotateLeft
Process: conducts left rotation by manipulation of given pointer
Function input/parameters: pointer to given subtree to rotate
Function output/parameters: none
Function output/returned: pointer to calling function/tree node above
                          where function is called
Device input/---: none
Device output/monitor: rotation action displayed  ("- Rotating Left")
Dependencies: printf
*/
AvlTreeNodeType *rotateLeft( AvlTreeNodeType *oldParentPtr )
{
   AvlTreeNodeType *tempPtr = NULL;

   // display rotation action
   printf("    - Rotating Left\n");

   // assign temp pointer to oldParentPtr
   tempPtr = oldParentPtr;

   // assign oldParentPtr to temp pointer to rightChildPtr
   oldParentPtr = tempPtr->rightChildPtr;

   // swap pointers
   tempPtr->rightChildPtr = oldParentPtr->leftChildPtr;

   // assign oldParentPtr leftChildPtr to temp pointer
   oldParentPtr->leftChildPtr = tempPtr;

   // return oldParentPtr
   return oldParentPtr;
}


/*
Name: rotateRight
Process: conducts right rotation by manipulation of given pointer
Function input/parameters: pointer to given subtree to rotate
Function output/parameters: none
Function output/returned: pointer to calling function/tree node above
                          where function is called
Device input/---: none
Device output/monitor: rotation action displayed  ("- Rotating Right")
Dependencies: printf
*/
AvlTreeNodeType *rotateRight( AvlTreeNodeType *oldParentPtr )
{
   AvlTreeNodeType *tempPtr = NULL;

   // display rotation
   printf("    - Rotating Right\n");

   // assign temp pointer to oldParentPtr
   tempPtr = oldParentPtr;

   // assign oldParentPtr to temp leftChildPtr
   oldParentPtr = tempPtr->leftChildPtr;

   // swap pointers
   tempPtr->leftChildPtr = oldParentPtr->rightChildPtr;

   // assign oldParent rightChildPtr to temp pointer
   oldParentPtr->rightChildPtr = tempPtr;

   // return oldParentPtr
   return oldParentPtr;
}


/*
Name: search
Process: recursively searches tree for specified data using room number key
Function input/parameters: pointer to working subtree (AvlTreeNodeType *),
                           room number (const char *)
Function output/parameters: none
Function output/returned: pointer to found node (AvlTreeNodeType *)
Device input/---: none
Device output/---: none
Dependencies: search (recursively)
*/
AvlTreeNodeType *search( AvlTreeNodeType *wkgPtr, const char *roomNumber )
{
   int comparison;

   // check for null
   if(wkgPtr != NULL)
   {
      // compare rooms
      comparison = compareRoomNumbers(wkgPtr->roomNumber, roomNumber);

      // check if node is to the left
      if(comparison < 0)
      {
         wkgPtr->leftChildPtr = search(wkgPtr->leftChildPtr, roomNumber);
      }

      // check if node is to the right
      else if(comparison > 0)
      {
         wkgPtr->rightChildPtr = search(wkgPtr->rightChildPtr, roomNumber);
      }

      // found it, return it
      return wkgPtr;
   }

   return NULL;
}
