#include "SetUtilitiesTwo.h"

int main( int argc, char **argv )
   {
    // initialize function/variables

    SetType allOddSet, allEvenSet, allIncrementSet, allIncrementSubset;
    SetType randomSet, bubbleSortSet, insertionSortSet, selectionSortSet;
    SetType resultSet;
    int index, tempVal, startVal = 10, numVals = 25;
    int subSetStartVal = 19, numSubsetVals = 10;
    int numRandVals = 75, numAddVals = 5, numDeleteVals = 5;
    int searchVal = 27;
    bool wasInSet;

    // seed random generator
    srand( time( NULL ) );

    // show title
    printf( "\nSet Management Program\n" );
    printf( "======================\n" );

    // create even array
    allOddSet = initializeSet( allOddSet, 
                                     MAX_SET_CAPACITY, startVal, numVals, ODD );
    displaySet( "Odd", allOddSet );

    // create odd array
    allEvenSet = initializeSet( allEvenSet, 
                                    MAX_SET_CAPACITY, startVal, numVals, EVEN );
    displaySet( "Even", allEvenSet );

    // create large incremental array
    allIncrementSet = initializeSet( allIncrementSet, MAX_SET_CAPACITY, 
                                               startVal, numVals, INCREMENTED );
    displaySet( "Incremented", allIncrementSet );

    // create small incremental array, subset of large
    allIncrementSubset = initializeSet( allIncrementSubset, MAX_SET_CAPACITY, 
                                   subSetStartVal, numSubsetVals, INCREMENTED );
    displaySet( "Incremented Sub", allIncrementSubset );

    // generate random values (startVal ignored)
    randomSet = initializeSet( resultSet, MAX_SET_CAPACITY,
                                                startVal, numRandVals, RANDOM );
    displaySet( "Random Initial", randomSet );

    printf( "\nAdding Selected Values\n\n" );

    for( index = 0; index < numAddVals; index++ )
       {
        tempVal = getRandBetween( THREE_DIGIT_LOW, THREE_DIGIT_HIGH );

        printf( "Adding: %3d - ", tempVal );

        if( isInSet( randomSet, tempVal ) )
           {
            printf( "Failed\n" );
           }

        else
           {
            printf( "Succeeded\n" );
           }

        randomSet = addItem( randomSet, tempVal );
       }

    displaySet( "Random With Added Values", randomSet );

    printf( "\nDeleting Selected Values\n\n" );

    for( index = 3; index <= numDeleteVals * 3; index += 3 )
       {
        if( index < numDeleteVals * 3 )
           {
            tempVal = randomSet.setArray[ index ];

            wasInSet = true;
           }

        else
           {
            tempVal = 99;

            wasInSet = false;
           }

        printf( "Deleting: %3d - ", tempVal );

        randomSet = deleteItem( randomSet, tempVal );

        if( wasInSet && !isInSet( randomSet, tempVal ) )
           {
            printf( "Succeeded\n" );
           }

        else
           {
            printf( "Failed\n" );
           }
       }

    displaySet( "Random With Deleted Values", randomSet );

    // show sorts
    printf( "\n----- Sorted Displays -----\n" );

    // sort randoms
    bubbleSortSet = runBubbleSort( randomSet );
    displaySet( "Bubble Sort", bubbleSortSet );

    insertionSortSet = runInsertionSort( randomSet ); // insertion
    displaySet( "Insertion Sort", insertionSortSet );

    selectionSortSet = runSelectionSort( randomSet ); // selection
    displaySet( "Selection Sort", selectionSortSet );

    // find intersections
    printf( "\n----- Find Intersections -----\n" );

    // find intersection - odd/increment

    resultSet = findIntersection( resultSet, allOddSet, allIncrementSet );
    displaySet( "Intersection Odd/Increment", resultSet );

    // find intersection - even/increment
    resultSet = findIntersection( resultSet, allEvenSet, allIncrementSet );
    displaySet( "Intersection Even/Increment", resultSet );

    // find intersection - increment/increment subset
    resultSet = findIntersection( resultSet, 
                                          allIncrementSubset, allIncrementSet );
    displaySet( "Intersection Increment/Increment Sub", resultSet );

    // find intersection - even/odd subset
    resultSet = findIntersection( resultSet, allEvenSet, allOddSet );
    displaySet( "Intersection Even/Odd", resultSet );

    // find unions
    printf( "----- Find Unions -----\n" );

    // find union - odd/increment
    resultSet = findUnion( resultSet, allOddSet, allIncrementSet );
    //displaySet( "Union Odd/Increment before sort", resultSet );
    resultSet = runBubbleSort( resultSet );
    displaySet( "Union Odd/Increment", resultSet );

    // find union - even/increment
    resultSet = findUnion( resultSet, allEvenSet, allIncrementSet );
    resultSet = runInsertionSort( resultSet );
    displaySet( "Union Even/Increment", resultSet );

    // find union - increment/increment subset
    resultSet = findUnion( resultSet, allIncrementSet, allIncrementSubset );
    displaySet( "Union Increment/Increment Sub", resultSet );

    // find union - even/odd subset
    resultSet = findUnion( resultSet, allEvenSet, allOddSet );
    resultSet = runSelectionSort( resultSet );
    displaySet( "Union Even/Odd Sub", resultSet );

    // test subset
    printf( "\n----- Test Subset -----\n" );

    printf( "\nFor Increment Set with Increment Sub Set, " );
    printf( "the Increment Sub Set IS " );

    if( !isSubSetOf( allIncrementSet, allIncrementSubset ) )
       {
        printf( "NOT " );
       }

    printf( "a subset of the Increment Set\n" );

    printf( "\nFor Increment Set with All Evens Set, " );
    printf( "the Evens Set IS " );

    if( !isSubSetOf( allIncrementSet, allEvenSet ) )
       {
        printf( "NOT " );
       }

    printf( "a subset of the Increment Set\n" );

    // test subset
    printf( "\n----- Test In Set -----\n" );

    printf( "\nThe value %d IS ", searchVal );

    if( !isInSet( allIncrementSet, searchVal ) )
       {
        printf( "NOT " );
       }

    searchVal = 97;

    printf( "in the Increment Set\n" );

    printf( "\nThe value %d IS ", searchVal );

    if( !isInSet( allIncrementSet, searchVal ) )
       {
        printf( "NOT " );
       }

    printf( "in the Increment Set\n" );

    printf( "\nEnd Program\n" );

    return 0;
   }


