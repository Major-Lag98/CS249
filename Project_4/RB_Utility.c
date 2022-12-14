// included headers
#include "RB_Utility.h"

/*
Name: displayStatus
Process: displays appropriately indented report of next attempt
         to place value, with ControlCodes as follows:
         VALID_ITEM, INVALID_ITEM, DUPLICATE_ITEM, OVER_SUM,
         OUT_OF_BOUNDS, TEST_LOCATION, and NO_SOLUTION
Function Input/Parameters: recursion level for indentation (int),
                           status string reporting action (const char *),
                           cell data being tested (CellDataType),
                           control code for reporting (ControlCode),
                           verbose flag turns reporting on or off (bool)
Function Output/Parameters: none
Function Output/Returned: none
Device Input/---: none
Device Output/monitor: status of cell attempt
Dependencies: printf, cellToString
*/
void displayStatus( int recLevel, const char *status, CellDataType current,
                                      ControlCodes opSuccess, bool verboseFlag )
   {
    int index, recLevelIndent = recLevel * REC_LEVEL_INDENT;
    char tempStr[ STD_STR_LEN ];

    if( verboseFlag )
       {
        for( index = 0; index < recLevelIndent; index++ )
           {
            printf( "%c", SPACE );
           }
     
        printf( "%s", status );
     
        if( opSuccess == TEST_LOCATION )
           {
            printf( "(%d, %d)\n", current.xLocation, current.yLocation );
           }
         
        else if( opSuccess == OUT_OF_BOUNDS )
           {
            printf( "Location Not Found\n" );
           }
     
        else if( opSuccess == VALID_ITEM )
           {
            cellToString( tempStr, current );
            printf( "%s\n", tempStr );
           }
         
        else if( opSuccess == NO_SOLUTION )
           {
            printf( "Doesn't Support Solution\n" );
           }

        else if( opSuccess == DUPLICATE_ITEM )
           {
            printf( "Already In Set\n" );
           }
         
        else if( opSuccess == OVER_SUM )
           {
            printf( "Over Requested Sum\n" );
           }
       }
   }

/*
Name: dumpArray
Process: simple 2D array dump of array data
Function Input/Parameters: array data (ArrayType), title (const char *)
Function Output/Parameters: none
Function Output/Returned: none
Device Input/---: none
Device Output/monitor: display of 2D array
Dependencies: printf
*/
void dumpArray( const char *title, const ArrayType dispArray )
   {
    int rowIndex, colIndex;

    printf( "\n%s\n", title );

    for( rowIndex = 0; rowIndex < dispArray.rowSize; rowIndex++ )
       {
        for( colIndex = 0; colIndex < dispArray.colSize; colIndex++ )
           {
            if( colIndex > 0 )
               {
                printf( ", " );

               }
          
            printf( "%5d", dispArray.array[ rowIndex ][ colIndex ] );
           }
      
        printf( "\n" );
       }

    printf( "\n" );
   }

/*
Name: findSum
Process: Calls helper to find contiguous values
         adding to a specified number in an array

         Note: Displays success or failed results

         Rules of the searching process:

         - The search starts in the upper left corner, 
           reporting each valid location found. 
           The solution must start from a location in the top row
           and end in a location in the bottom row
f
         - The method must search to a current location's right,
           then below it, and then to its left, exactly in that order

         - The method must report what it finds, 
           either as a successful candidate value
           or a failed candidate value, and why it failed

         - The method must use recursive backtracking,
           it must backtrack the recursion upon any failure,
           but it must continue forward recursion upon any success
           until the solution is found

         - The method must be able to handle the condition
           that the value in the upper left corner does not support the solution 

Function Input/Parameters: data array (ArrayType),
                           value to sum up to (int), 
                           verbose flag controls description(bool)
Function Output/Parameters: none
Function Output/Returned: none
Device Input/---: none
Device Output/monitor: display of process
Dependencies: initializeSet, printf, findSumHelper, displaySet

  */
void findSum( const ArrayType dataArray, int sumRequest, bool verbose )
    {
     int startingXIndex = 0, startingYIndex = 0;
     int startingTotal = 0, startingRecLevel = 0;
     int iterationCount = 0;
     int index, testSum = 0;
     SetType foundSet;

     initializeSet( &foundSet );
     
     printf( "Search for sum %d, start: \n\n", sumRequest );

     if( findSumHelper( sumRequest, startingTotal,
                        startingXIndex, startingYIndex, 
                        &foundSet, dataArray,
                        startingRecLevel, &iterationCount, verbose ) )
        {
         displaySet( "\nSearch End => Successful Set:", foundSet );

         for( index = 0; index < foundSet.size; index++ )
            {
             testSum += foundSet.setArray[ index ].dataValue;
            }

         printf( "\nSum Verified   : %d\n", testSum );

         printf( "\nIteration Count: %d\n", iterationCount );
        }
     
     else
       {
        printf( "\nSearch End => Solution Not Found\n" );

        printf( "\nIteration Count: %d\n", iterationCount );
       }  
    }
 
/*
Name: findSumHelper
Process: specifications in calling function
Function Input/Parameters: sum value result requested (int),
                           starting and then working total (int),
                           starting x and y indices (int),
                           pointer toresulting set (SetType *), 
                           data array (const ArrayType)
                           starting and then working recursion level (int),
                           pointer to iteration count (int *)
                           verbose flag (bool)
Function Output/Parameters: pointer to iteration count to be returned (int *)
Function Output/Returned: result of given attempt (bool)
Device Input/---: none
Device Output/monitor: operation of recursive backtracking
Dependencies: setCellData, displayStatus, isInBounds, isInSet, 
              addItem, findSumHelper (recursive),
              other functions in this file are allowed,
              Note: displayStatus is used exclusively, 
              no other printing functions are allowed
*/
bool findSumHelper( int sumRequest, int runningTotal,
                    int xIndex, int yIndex, 
                    SetType *foundSet, const ArrayType dataArray,
                    int recLevel, int *iterationCount, 
                    bool verbose )
{
   
   bool success = false;

   // increase the iteration
   *iterationCount += 1;

   // create new cell 
   CellDataType current;
   current.dataValue = dataArray.array[yIndex][xIndex]; // remember [row][col]
   current.xLocation = xIndex;
   current.yLocation = yIndex;

   // make correct op code
   ControlCodes opCode = TEST_LOCATION;

   // display the current status
   displayStatus(recLevel, "Trying Location", current, opCode, verbose);

   // check if (y, x) is in bounds
   if (isInBounds(dataArray, xIndex, yIndex))
   {
      // check if is in set
      if(!isInSet(*foundSet, current))
      {
         // check if over sum
         if (runningTotal + current.dataValue <= sumRequest)
         {

            // flag valid item
            opCode = VALID_ITEM;

            // display status
            displayStatus(recLevel, "Valid Location Found: ", current, opCode, 
                                                                       verbose);

            // increment the current to the running total
            runningTotal += current.dataValue;

            // add item to the found set
            addItem(foundSet, current);

            // if the sum of the set is good after our checks
            if (runningTotal == sumRequest && yIndex == dataArray.colSize - 1)
            {
               // return true
               return true;
            }
            
            // recurse right
            if(findSumHelper(sumRequest, runningTotal,
                        xIndex + 1, yIndex, 
                        foundSet, dataArray,
                        recLevel + 1, iterationCount,
                        verbose ))
            {
               success = true;
            }
            // recurse down if we cant go right
            else if (findSumHelper(sumRequest, runningTotal,
                        xIndex, yIndex + 1, 
                        foundSet, dataArray,
                        recLevel + 1, iterationCount,
                        verbose ))
            {
               success = true;
            }
            // recurse left if we cant go down
            else if (findSumHelper(sumRequest, runningTotal,
                        xIndex - 1, yIndex, 
                        foundSet, dataArray,
                        recLevel + 1, iterationCount,
                        verbose ))
            {
               success = true;
            }

            // if one of the directions succeed
            if (success)
            {
               // display and return success
               displayStatus(recLevel, "Found at: ", current, opCode, verbose);
               return true;
            }

            // if all directions are exausted 
            // report no solution and remove from set
            opCode = NO_SOLUTION;
            deleteItem(foundSet, current);
         }
         else
         {
            // flag over sum
            opCode = OVER_SUM;
         }
      }
      else
      {
         // flag duplicate
         opCode = DUPLICATE_ITEM;
      }
   }
   else
   {
      // flag out of array
      opCode = OUT_OF_BOUNDS;
   }

   // display the failure
   displayStatus(recLevel, "Location Failed: ", current, opCode, verbose);

   // quit out of current recursion level.
   return false;
}
 
/*
Name: isInBounds
Process: tests x and y locations for in array bounds
Function Input/Parameters: x & y locations (int),
                           data array (ArrayType)
Function Output/Parameters: none
Function Output/Returned: result of test (bool)
Device Input/---: none
Device Output/---: none
Dependencies: none
*/
bool isInBounds( ArrayType dataArray, int xLocTest, int yLocTest )
   {
    bool rowTest = xLocTest >= 0 && xLocTest < dataArray.colSize;
    bool colTest = yLocTest >= 0 && yLocTest < dataArray.rowSize;
     
    return rowTest && colTest;
   }
 

