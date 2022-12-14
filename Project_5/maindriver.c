// header files
#include "QueueUtility.h"
#include "StackUtility.h"
#include <math.h>   // rand, srand
#include <time.h>   // srand
#include <stdbool.h>

// constant definitions

// main function
int main( int argc, char *argv[] )
   {
    QueueType queue;
    StackType stack;
    int maxItems = 10;
    int index;
    bool testQueue = true;
    bool testStack = true;
    char tempStr[ STD_STR_LEN ];

    // seed random generator
    srand( time( NULL ) );

    // set title
    printf( "\nQueue/Stack Test Program\n" );
    printf( "========================\n" );

    if( testQueue )
       {
        printf( "\n==================== Queue Test ====================\n" );

        // initialize queue
        initializeQueue( &queue, maxItems );

        // create queue
        printf( "\nEnqueueing some names\n" );

        copyQueueString( tempStr, "Johnson, Robert" );
        printf( "\nEnqueueing %s\n", tempStr );
        enqueue( &queue, tempStr );
        displayQueue( &queue );

        copyQueueString( tempStr, "Elliott, Cayley" );
        printf( "\nEnqueueing %s\n", tempStr );
        enqueue( &queue, tempStr );
        displayQueue( &queue );

        copyQueueString( tempStr, "Reyes, Connor" );
        printf( "\nEnqueueing %s\n", tempStr );
        enqueue( &queue, tempStr );
        displayQueue( &queue );

        copyQueueString( tempStr, "Sanchez, Susan" );
        printf( "\nEnqueueing %s\n", tempStr );
        enqueue( &queue, tempStr );
        displayQueue( &queue );

        copyQueueString( tempStr, "Penn, Frederick" );
        printf( "\nEnqueueing %s\n", tempStr );
        enqueue( &queue, tempStr );
        displayQueue( &queue );

        copyQueueString( tempStr, "Deangelis, Shawna" );
        printf( "\nEnqueueing %s\n", tempStr );
        enqueue( &queue, tempStr );
        displayQueue( &queue );

        copyQueueString( tempStr, "Shafer, Tristan" );
        printf( "\nEnqueueing %s\n", tempStr );
        enqueue( &queue, tempStr );
        displayQueue( &queue );


        // dequeue some
        printf( "\nDequeueing some names\n" );
        for( index = 0; index < maxItems / 2; index++ )
           {
            dequeue( tempStr, &queue );

            printf( "\nDequeueing: %s\n", tempStr );

            displayQueue( &queue );
           }

        // enqueue some more
        printf( "\nEnqueueing more names, forces resize\n" );

        copyQueueString( tempStr, "Ruan, Francisco" );
        printf( "\nEnqueueing %s\n", tempStr );
        enqueue( &queue, tempStr );
        displayQueue( &queue );

        copyQueueString( tempStr, "Werner, Riley" );
        printf( "\nEnqueueing %s\n", tempStr );
        enqueue( &queue, tempStr );
        displayQueue( &queue );

        copyQueueString( tempStr, "Davis, Glen-Andrew" );
        printf( "\nEnqueueing %s\n", tempStr );
        enqueue( &queue, tempStr );
        displayQueue( &queue );

        copyQueueString( tempStr, "Thomas, Sena" );
        printf( "\nEnqueueing %s\n", tempStr );
        enqueue( &queue, tempStr );
        displayQueue( &queue );

        copyQueueString( tempStr, "Nash, Tim" );
        printf( "\nEnqueueing %s\n", tempStr );
        enqueue( &queue, tempStr );
        displayQueue( &queue );

        copyQueueString( tempStr, "Hack, Jacque" );
        printf( "\nEnqueueing %s\n", tempStr );
        enqueue( &queue, tempStr );
        displayQueue( &queue );

        copyQueueString( tempStr, "Ortega, Jane" );
        printf( "\nEnqueueing %s\n", tempStr );
        enqueue( &queue, tempStr );
        displayQueue( &queue );

        copyQueueString( tempStr, "Catania, DeMarco" );
        printf( "\nEnqueueing %s\n", tempStr );
        enqueue( &queue, tempStr );
        displayQueue( &queue );

        copyQueueString( tempStr, "Johnson, Trevor" );
        printf( "\nEnqueueing %s\n", tempStr );
        enqueue( &queue, tempStr );
        displayQueue( &queue );

        copyQueueString( tempStr, "Sanchez, Kieley" );
        printf( "\nEnqueueing %s\n", tempStr );
        enqueue( &queue, tempStr );
        displayQueue( &queue );

        printf( "\nPeek front: %s\n", peekQueueFront( &queue ) );

        clearQueue( &queue );
        }

    if( testStack )
       {
        printf( "\n==================== Stack Test ====================\n" );

        // initialize stack
        initializeStack( &stack, maxItems );

        // create queue
        printf( "\nPushing some names\n" );

        copyStackString( tempStr, "Johnson, Robert" );
        printf( "\nPushing %s\n", tempStr );
        push( &stack, tempStr );
        displayStack( &stack );

        copyStackString( tempStr, "Elliott, Cayley" );
        printf( "\nPushing %s\n", tempStr );
        push( &stack, tempStr );
        displayStack( &stack );

        copyStackString( tempStr, "Reyes, Connor" );
        printf( "\nPushing %s\n", tempStr );
        push( &stack, tempStr );
        displayStack( &stack );

        copyStackString( tempStr, "Sanchez, Susan" );
        printf( "\nPushing %s\n", tempStr );
        push( &stack, tempStr );
        displayStack( &stack );

        copyStackString( tempStr, "Penn, Frederick" );
        printf( "\nPushing %s\n", tempStr );
        push( &stack, tempStr );
        displayStack( &stack );

        copyStackString( tempStr, "Deangelis, Shawna" );
        printf( "\nPushing %s\n", tempStr );
        push( &stack, tempStr );
        displayStack( &stack );

        copyStackString( tempStr, "Shafer, Tristan" );
        printf( "\nPushing %s\n", tempStr );
        push( &stack, tempStr );
        displayStack( &stack );

        // dequeue some
        printf( "\nPopping some names\n" );
        for( index = 0; index < maxItems / 2; index++ )
           {
            pop( tempStr, &stack );

            printf( "\nPopping: %s\n", tempStr );

            displayStack( &stack );
           }

        // enqueue some more
        printf( "\nPushing more names, forces resize\n" );

        copyStackString( tempStr, "Ruan, Francisco" );
        printf( "\nPushing %s\n", tempStr );
        push( &stack, tempStr );
        displayStack( &stack );

        copyStackString( tempStr, "Werner, Riley" );
        printf( "\nPushing %s\n", tempStr );
        push( &stack, tempStr );
        displayStack( &stack );

        copyStackString( tempStr, "Davis, Glen-Andrew" );
        printf( "\nPushing %s\n", tempStr );
        push( &stack, tempStr );
        displayStack( &stack );

        copyStackString( tempStr, "Thomas, Sena" );
        printf( "\nPushing %s\n", tempStr );
        push( &stack, tempStr );
        displayStack( &stack );

        copyStackString( tempStr, "Nash, Tim" );
        printf( "\nPushing %s\n", tempStr );
        push( &stack, tempStr );
        displayStack( &stack );

        copyStackString( tempStr, "Hack, Jacque" );
        printf( "\nPushing %s\n", tempStr );
        push( &stack, tempStr );
        displayStack( &stack );

        copyStackString( tempStr, "Ortega, Jane" );
        printf( "\nPushing %s\n", tempStr );
        push( &stack, tempStr );
        displayStack( &stack );

        copyStackString( tempStr, "Catania, DeMarco" );
        printf( "\nPushing %s\n", tempStr );
        push( &stack, tempStr );
        displayStack( &stack );

        copyStackString( tempStr, "Johnson, Trevor" );
        printf( "\nPushing %s\n", tempStr );
        push( &stack, tempStr );
        displayStack( &stack );

        copyStackString( tempStr, "Sanchez, Kieley" );
        printf( "\nPushing %s\n", tempStr );
        push( &stack, tempStr );
        displayStack( &stack );

        printf( "\nPeek top: %s\n", peekStackTop( &stack ) );

        clearStack( &stack );
        }

    // end program

       // display program end
       printf( "\nProgram End\n" );

       return 0;
   }


