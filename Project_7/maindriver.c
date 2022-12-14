// header files
#include "IteratorUtilityLL.h"

// constant definitions
const int MAX_ARRAY_CAPACITY = 100;

// prototypes

// main function
int main( int argc, char *argv[] )
   {
    StudentType *iterator, *copiedIterator;
    int index, numMoves = 3;
    StudentType student;

    // seed random generator
    srand( time( NULL ) );

    // set title
    printf( "\nIterator Test Program\n" );
    printf(   "=====================\n" );

    // initialize iterator
    iterator = initializeIterator();

    // set values at front
    printf( "\nSetting values at front -----------------------------------\n" );

    setStudentData( &student, "Johnson, Robert", 603667, 'M', 2.844077875 );
    printf( "\nInserting %s\n", student.name );
    iterator = insertAtFront( iterator, student );
    displayIterator( iterator );

    setStudentData( &student, "Elliot, Cayley", 135658, 'M', 2.978848017 );
    printf( "\nInserting %s\n", student.name );
    iterator = insertAtFront( iterator, student );
    displayIterator( iterator );

    setStudentData( &student, "Sanchez, Susan", 154838, 'F', 2.063213296 );
    printf( "\nInserting %s\n", student.name );
    iterator = insertAtFront( iterator, student );
    displayIterator( iterator );

    setStudentData( &student, "Deangelis, Shawna", 764050, 'F', 2.203316877 );
    printf( "\nInserting %s\n", student.name );
    iterator = insertAtFront( iterator, student );
    displayIterator( iterator );

    setStudentData( &student, "Hack, Jacque", 641605, 'F', 3.634297476 );
    printf( "\nInserting %s\n", student.name );
    iterator = insertAtFront( iterator, student );
    displayIterator( iterator );

    // set values at end
    printf( "\nSetting values at end -------------------------------------\n" );

    setStudentData( &student, "Becker, Anna", 716502, 'F', 2.87310837 );
    printf( "\nInserting %s\n", student.name );
    iterator = insertAtEnd( iterator, student );
    displayIterator( iterator );

    setStudentData( &student, "Bolling, Mohammad", 419808, 'M', 2.135187788 );
    printf( "\nInserting %s\n", student.name );
    iterator = insertAtEnd( iterator, student );
    displayIterator( iterator );

    setStudentData( &student, "Nishimura, Erica", 729129, 'F', 2.20640475 );
    printf( "\nInserting %s\n", student.name );
    iterator = insertAtEnd( iterator, student );
    displayIterator( iterator );

    setStudentData( &student, "Nethercott, Michael", 812517, 'M', 3.430435346 );
    printf( "\nInserting %s\n", student.name );
    iterator = insertAtEnd( iterator, student );
    displayIterator( iterator );

    setStudentData( &student, "Medrano-Pacheco, Rachel", 
                                                     285416, 'F', 3.869157451 );
    printf( "\nInserting %s\n", student.name );
    iterator = insertAtEnd( iterator, student );
    displayIterator( iterator );

    // moving right/next
    printf( "\nMoving right/next -----------------------------------------\n" );
    for( index = 0; index < numMoves; index++ )
       {
        moveNext( iterator );

        displayIterator( iterator );
       }

    // move to end
    printf( "\nSetting to Last -------------------------------------------\n" );
    setToLast( iterator );
    displayIterator( iterator );

    // moving left/prev
    printf( "\nMoving left/prev ------------------------------------------\n" );
    for( index = 0; index < numMoves; index++ )
       {
        movePrev( iterator );

        displayIterator( iterator );
       }

    // removing some values
    printf( "\nRemoving some students ------------------------------------\n" );
    for( index = 0; index < numMoves + 1; index++ )
       {
        iterator = removeAtCurrent( &student, iterator );

        printf( "\nRemoving: %s\n", student.name );

        displayIterator( iterator );
       }

    // setting to first
    printf( "\nSetting to first ------------------------------------------\n" );

    setToFirst( iterator );

    displayIterator( iterator );

    // removing from first
    printf( "\nRemoving from first ---------------------------------------\n" );

    iterator = removeAtCurrent( &student, iterator );

    printf( "\nRemoving: %s\n", student.name );

    displayIterator( iterator );

    // copying iterator
    printf( "\nCopying Iterator/Linked List ------------------------------\n" );
    
    copiedIterator = copyIterator( iterator );

    displayIterator( copiedIterator );

    // copying iterator
    printf( "\nClearing Iterators ----------------------------------------\n" );

    iterator = clearIterator( iterator );

    copiedIterator = clearIterator( iterator );

    displayIterator( copiedIterator );
    // end program

       // report end program
       printf( "\nEnd Program\n" );

       // return success
       return 0;
   }
