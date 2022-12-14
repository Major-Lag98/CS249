#include "SetUtilities.h"

int main( int argc, char **argv )
   {
    // initialize function/variables
    int allOddSet[ MAX_SET_CAPACITY ];
    int allEvenSet[ MAX_SET_CAPACITY ];
    int allIncrementSet[ MAX_SET_CAPACITY ];
    int allIncrementSubset[ MAX_SET_CAPACITY ];
    int resultSet[ MAX_SET_CAPACITY ];
    int startVal = 10, numVals = 25, resultSize;
    int subSetStartVal = 19, numSubsetVals = 10, searchVal = 27;

    // show title
    printf( "\nSet Management Program\n" );
    printf( "======================\n" );

    // create even array
    initializeSetArray( allOddSet, startVal, numVals, ODD );
    displaySet( "Odd", allOddSet, numVals );

    // create odd array
    initializeSetArray( allEvenSet, startVal, numVals, EVEN );
    displaySet( "Even", allEvenSet, numVals );

    // create large incremental array
    initializeSetArray( allIncrementSet, startVal, numVals, INCREMENTED );
    displaySet( "Incremented", allIncrementSet, numVals );

    // create small incremental array, subset of large
    initializeSetArray( allIncrementSubset, 
                                         subSetStartVal, numVals, INCREMENTED );
    displaySet( "Incremented Sub", allIncrementSubset, numSubsetVals );

    // find intersections
    printf( "\n----- Find Intersections -----\n" );

    // find intersection - odd/increment

    resultSize = findIntersection( resultSet, 
                                 allOddSet, numVals, allIncrementSet, numVals );
    displaySet( "Intersection Odd/Increment", resultSet, resultSize );

    // find intersection - even/increment
    resultSize = findIntersection( resultSet, 
                                allEvenSet, numVals, allIncrementSet, numVals );
    displaySet( "Intersection Even/Increment", resultSet, resultSize );

    // find intersection - increment/increment subset
    resultSize = findIntersection( resultSet, 
                  allIncrementSubset, numSubsetVals, allIncrementSet, numVals );
    displaySet( "Intersection Increment/Increment Sub", resultSet, resultSize );

    // find intersection - even/odd subset
    resultSize = findIntersection( resultSet, 
                                      allEvenSet, numVals, allOddSet, numVals );
    displaySet( "Intersection Even/Odd", resultSet, resultSize );

    // find unions
    printf( "----- Find Unions -----\n" );

    // find union - odd/increment
    resultSize = findUnion( resultSet, 
                                 allOddSet, numVals, allIncrementSet, numVals );
 
    displaySet( "Union Odd/Increment", resultSet, resultSize );

    // find union - even/increment
    resultSize = findUnion( resultSet, 
                                allEvenSet, numVals, allIncrementSet, numVals );
    displaySet( "Union Even/Increment", resultSet, resultSize );

    // find union - increment/increment subset
    resultSize = findUnion( resultSet, 
                  allIncrementSubset, numSubsetVals, allIncrementSet, numVals );
    displaySet( "Union Increment/Increment Sub", resultSet, resultSize );

    // find union - even/odd subset
    resultSize = findUnion( resultSet, 
                                      allEvenSet, numVals, allOddSet, numVals );
    displaySet( "Union Even/Odd Sub", resultSet, resultSize );

    // test subset
    printf( "----- Test Subset -----\n" );

    printf( "\nFor Increment Set with Increment Sub Set, " );
    printf( "the Increment Sub Set IS " );

    if( !isSubSetOf( allIncrementSet, 
                                 numVals, allIncrementSubset, numSubsetVals ) )
       {
        printf( "NOT " );
       }

    printf( "a subset of the Increment Set\n" );

    printf( "\nFor Increment Set with All Evens Set, " );
    printf( "the Evens Set IS " );

    if( !isSubSetOf( allIncrementSet, numVals, allEvenSet, numVals ) )
       {
        printf( "NOT " );
       }

    printf( "a subset of the Increment Set\n" );

    // test subset
    printf( "----- Test In Set -----\n" );

    printf( "\nThe value %d IS ", searchVal );

    if( !isInSet( allIncrementSet, numVals, searchVal ) )
       {
        printf( "NOT " );
       }

    searchVal = 97;

    printf( "in the Increment Set\n" );

    printf( "\nThe value %d IS ", searchVal );

    if( !isInSet( allIncrementSet, numVals, searchVal ) )
       {
        printf( "NOT " );
       }

    printf( "in the Increment Set\n" );

    printf( "\nEnd Program\n" );

    return 0;
   }


