// header files
#include "File_Input_Utility.h"
#include "BST_Utility.h"

// constant definitions

const char DOUBLE_QUOTE = '"';

// prototypes
void displayNode( TreeNodeType dispPtr );
int getDataFromFile( const char *fileName, TreeNodeType **rootPtr );

// main function
int main( int argc, char *argv[] )
   {
    TreeNodeType *rootPtr, *cpdRootPtr;
    TreeNodeType toRemove, removedVal;
    char fileName[ STD_STR_LEN ] = "RoomData_11.csv";

    // set title
    printf( "\nBinary Search Tree Test Program\n" );
    printf(   "===============================\n" );

    // initialize iterator
    initializeBST( &rootPtr );

    // initialize dummy removal struct
    toRemove = *createTreeNodeFromData( "", "", "", 0 ); 

    // upload data
       // function: getDataFromFile
    getDataFromFile( fileName, &rootPtr );

    // show in order traversal
       // function: displayInOrder
    printf( "\nIn order traversal: \n" );
    displayInOrder( rootPtr );

    // show post order traversal
       // function: displayInOrder
    printf( "\nPost order traversal: \n" );
    displayPostOrder( rootPtr );

    // show pre order traversal
       // function: displayInOrder
    printf( "\nPre order traversal: \n" );
    displayPreOrder( rootPtr );

    printf( "\nCreating duplicate tree\n" );
    cpdRootPtr = copyTree( rootPtr );


    //printf("Looking at copy: %s %s\n", rootPtr->leftChildPtr->leftChildPtr->leftChildPtr->roomNumber, rootPtr->leftChildPtr->leftChildPtr->leftChildPtr->buildingRoom);

    printf( "\nInorder Display of copied tree:\n" );      
    displayInOrder( cpdRootPtr );

    copyString( toRemove.roomNumber, "025-4106" );  
    printf( "\nRemoving %s\n", toRemove.roomNumber );  
    removeItem( &removedVal, &rootPtr, toRemove ); 
    printf( "Removed from Tree - " );
    displayNode( removedVal );
    printf( "\nInorder Display:\n" );      
    displayInOrder( rootPtr );

    copyString( toRemove.roomNumber, "066-316" );  
    printf( "\nRemoving %s\n", toRemove.roomNumber );  
    removeItem( &removedVal, &rootPtr, toRemove ); 
    printf( "Removed from Tree - " );
    displayNode( removedVal );
    printf( "\nInorder Display:\n" );      
    displayInOrder( rootPtr );

    copyString( toRemove.roomNumber, "047-135" );  
    printf( "\nRemoving %s\n", toRemove.roomNumber );  
    removeItem( &removedVal, &rootPtr, toRemove ); 
    printf( "Removed from Tree - " );
    displayNode( removedVal );
    printf( "\nInorder Display:\n" );      
    displayInOrder( rootPtr );

    copyString( toRemove.roomNumber, "081-110" );  
    printf( "\nRemoving %s\n", toRemove.roomNumber );  
    removeItem( &removedVal, &rootPtr, toRemove ); 
    printf( "Removed from Tree - " );
    displayNode( removedVal );
    printf( "\nInorder Display:\n" );      
    displayInOrder( rootPtr );

    copyString( toRemove.roomNumber, "027-208" );  
    printf( "\nRemoving %s\n", toRemove.roomNumber );  
    removeItem( &removedVal, &rootPtr, toRemove ); 
    printf( "Removed from Tree - " );
    displayNode( removedVal );
    printf( "\nInorder Display:\n" );      
    displayInOrder( rootPtr );

    copyString( toRemove.roomNumber, "082-135" );  
    printf( "\nRemoving %s\n", toRemove.roomNumber );  
    removeItem( &removedVal, &rootPtr, toRemove ); 
    printf( "Removed from Tree - " );
    displayNode( removedVal );
    printf( "\nInorder Display:\n" );      
    displayInOrder( rootPtr );

    copyString( toRemove.roomNumber, "018-321" );  
    printf( "\nRemoving %s\n", toRemove.roomNumber );  
    removeItem( &removedVal, &rootPtr, toRemove ); 
    printf( "Removed from Tree - " );
    displayNode( removedVal );
    printf( "\nInorder Display:\n" );      
    displayInOrder( rootPtr );

    // end program

       // clear BST
          // function: clearTree
       rootPtr = clearTree( rootPtr );
       cpdRootPtr = clearTree( cpdRootPtr );

       // show program end
          // function: printf
       printf( "\nEnd Program\n" );

       // return success
       return 0;
   }

/*
Name: displayNode
Process: displays node data
Function input/parameters: node pointer (TreeNodeType *)
Function output/parameters: none
Function output/returned: none
Device input/---: none
Device output/monitor: node data displayed
Dependencies: 
*/
void displayNode( TreeNodeType dispPtr )
   {
    printf( "Room Number: %s, Building/Room: %s, Class Setup: %s, Room Capacity: %d\n",
                       dispPtr.roomNumber, dispPtr.buildingRoom, 
                                      dispPtr.classSetup, dispPtr.roomCapacity );
   }

/*
Name: getDataFromFile
Process: uploads data from file with unknown number of data sets,
         has internal Verbose Boolean to display input operation
Function input/parameters: file name (char *)
Function output/parameters: root pointer (TreeNodeType **)
Function output/returned: number of values found (int)
Device input/file: data from HD
Device output/monitor: none
Dependencies: malloc, sizeof, openInputFile, readStringToLineEndFromFile,
              readStringToDelimiterFromFile, checkForEndOfInputFile, 
              readCharacterFromFile, readIntegerFromFile,
              insert, printf, closeInputFile, free
*/
int getDataFromFile( const char *fileName, TreeNodeType **rootPtr )
   {
    TreeNodeType *inputPtr = (TreeNodeType *)malloc( sizeof( TreeNodeType ) );
    int index = 0;
    bool verbose = false;  // Set to true to verify data upload, false otherwise

    if( openInputFile( fileName ) )
       {
        if( verbose )
           {
            printf( "\n     ----- Verbose: Begin Loading Data From File\n" );
           }

        // to be ignored - buildingRoom string used as dummy
        readStringToLineEndFromFile( inputPtr->buildingRoom ); 

        readStringToDelimiterFromFile( COMMA, inputPtr->roomNumber );

        while( !checkForEndOfInputFile() )
           {
            // gets rid of first double quote
            readCharacterFromFile();

            readStringToDelimiterFromFile( DOUBLE_QUOTE, inputPtr->buildingRoom );

            // gets rid of comma
            readCharacterFromFile();

            readStringToDelimiterFromFile( COMMA, inputPtr->classSetup );

            inputPtr->roomCapacity = readIntegerFromFile();

            *rootPtr = insert( *rootPtr, *inputPtr );

            if( verbose )
               {
                printf( "\n%3d) Room number: %s | ", 
                                              index + 1, inputPtr->roomNumber );

                printf( "Building/Classroom: %s | ", inputPtr->buildingRoom );

                printf( "Classroom setup: %s | ", inputPtr->classSetup );

                printf( "Room capacity: %d\n", inputPtr->roomCapacity );
               }

            // reprime - read next state name
            readStringToDelimiterFromFile( COMMA, inputPtr->roomNumber );
       
            index++;
           }

        if( verbose )
           {
            printf( "\n     ----- Verbose: End Loading Data From File\n\n" );
           }

        closeInputFile();

        free( inputPtr );
       }

    return index;
   }

