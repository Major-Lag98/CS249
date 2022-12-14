#include "HeapUtility.h"

/*
Name: addHeapItem
Process: adds item to heap, reports action, updates size,
         calls bubble up to reset heap
Function input/parameters: heap data (HeapType *), patient name (char *),
                           patient priority (int), time in (time_t)
Function output/parameters: updated heap data (HeapType *)
Function output/returned: none
Device input/---: none
Device output/monitor: patient addition action displayed as specified
Dependencies: checkForResize, setPatientFromData, printf,
              bubbleUpArrayHeap (recursively)
*/
void addHeapItem(HeapType *heap, char *nameSet, 
                                              int prioritySet, time_t timeSet)
{
    // variables
    // PatientType newPatient;

    // print adding new patient
    printf("\nAdding new patient: %s\n", nameSet);

    // first check for resize
    checkForResize(heap);

    // create new patient node
    setPatientFromData(&heap->array[heap->size], nameSet, prioritySet, timeSet);

    // increse size
    heap->size++;

    // bubble up at the current index
    bubbleUpArrayHeap(heap, heap->size - 1);
}

/*
Name: bubbleUpArrayHeap
Process: recursively rebalances heap after new data is added,
         displays bubble up actions
Function input/parameters: heap data (HeapType *), current index (int)
Function output/parameters: updated heap data (HeapType *)
Function output/returned: none
Device input/---: none
Device output/monitor: bubble up operations displayed as specified
Dependencies: setPatientFromStruct, comparePriority, getPatientInfo,
              bubbleUpArrayHeap (recursively), others acceptable
*/
void bubbleUpArrayHeap(HeapType *heap, int currentIndex)
{
    int parentIndex;
    int parent;
    int child;
    char parentStr[STD_STR_LEN];
    char childStr[STD_STR_LEN];


    // check for current index greater than 0
    if (currentIndex > 0)
    {
        // calculate parents index
        parentIndex = (currentIndex - 1) / 2;
        parent = heap->array[parentIndex].priority;
        child = heap->array[currentIndex].priority;

        // check if current childs value is less than parents value
        if (parent < child)
        {
            getPatientInfo(parentStr, heap->array[parentIndex]);
            getPatientInfo(childStr, heap->array[currentIndex]);
            // display bubble
            printf("   - Bubble up:\n");
            printf("     - Swapping parent: %s\n        with child: %s\n\n", 
                                                           parentStr, childStr);

            //swap
            heap->array[heap->size] = heap->array[parentIndex];
            heap->array[parentIndex] = heap->array[currentIndex];
            heap->array[currentIndex] = heap->array[heap->size];

            // call bubble

            bubbleUpArrayHeap(heap, parentIndex);

        }
        
    }
}

/*
Name: checkForResize
Process: checks for need to resize (increase capacity of) array,
         if necessary, creates new array with double the previous capacity,
         updates array, then returns previous data memory to OS
Function input/parameters: heap data (HeapType *)
Function output/parameters: updated heap data (HeapType *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: malloc, sizeof, setPatientFromStruct, free
*/
void checkForResize(HeapType *heap)
{
    PatientType *newArray;
    int index;

    // if the size reaches capacity
    if (heap->size == heap->capacity)
    {
        // double the capacity
        // creating new array with size * 2 capacity (malloc)
        newArray = (PatientType*)malloc(heap->capacity * 2 * 
                                                           sizeof(PatientType));

        // copy the elements over from old heap to new heap
        for (index = 0; index < heap->size; index++)
        {
             setPatientFromStruct(&newArray[index], *heap->array);
        }

        // set new capacity
        heap->capacity *= 2;

        // free old heap array
        free(heap->array);

        // assign new array to heap
        heap->array = newArray;
    }
    // else do nothing
}

/*
Name: clearHeap
Process: frees heap array, sets all other data members appropriately
Function input/parameters: heap data (HeapType *)
Function output/parameters: updated heap data (HeapType *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: free
*/
void clearHeap(HeapType *heap)
{
    // free the array
    free(heap->array);

    // set size to 0
    heap->size = 0;

    // set capacity to 0
    heap->capacity = 0;

    // display flag default - false
    heap->displayFlag = false;

    heap->array = NULL;

}

/*
Name: initializeHeap
Process: initializes heap, creates heap array from given capacity,
         sets other heap members appropriately,
         display flag is set to false
Function input/parameters: heap data (HeapType *), initial capacity (int)
Function output/parameters: updated heap data (HeapType *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: malloc, sizeof
*/
void initializeHeap(HeapType *heapPtr, int initialCapacity)
{
    // set size to 0
    heapPtr->size = 0;

    // set capacity to initial capacity
    heapPtr->capacity = initialCapacity;

    // malloc array of size capacity
    heapPtr->array = (PatientType*)malloc(initialCapacity * 
                                                           sizeof(PatientType));

    // set display flag to false
    heapPtr->displayFlag = false;
}

/*
Name: isEmpty
Process: reports if heap is empty
Function input/parameters: heap data (const HeapType)
Function output/parameters: none
Function output/returned: Boolean result of test (bool)
Device input/---: none
Device output/---: none
Dependencies: none
*/
bool isEmpty(const HeapType heap)
{
    return heap.size == 0; // return if size is 0
}

/*
Name: removeItem
Process: removes item from heap, reports removal action, adjusts data, 
         displays removal action, updates size, calls trickle down to reset heap
Function input/parameters: heap data (HeapType *)
Function output/parameters: updated heap data (HeapType *),
                            patient data removed (PatientType *)
Function output/returned: none
Device input/---: none
Device output/monitor: removal action displayed as specified
Dependencies: setPatientFromStruct, getPatientInfo, printf,
              trickleDownArrayHeap, others acceptable
*/
void removeItem(PatientType *removed, HeapType *heap)
{
   // variables
   char patient[STD_STR_LEN];

   // get data for removed patient
   getPatientInfo(patient, heap->array[0]);

   // display removing data
   printf("\nRemoving patient: %s\n", patient);

   // get removed to output
   setPatientFromStruct(removed, heap->array[0]);

   // decrement size
   heap->size--;

   // swap first index with last item
   setPatientFromStruct(&heap->array[0], heap->array[heap->size]);

   // trickle down to reset heap
   trickleDownArrayHeap(heap, 0);
}

/*
Name: setDisplayFlag
Process: sets Boolean flag to drive bubble up, trickle down displays
Function input/parameters: heap data (HeapType *), flag (bool)
Function output/parameters: updated heap data (HeapType *)
Function output/returned: none
Device input/---: none
Device output/---: none
Dependencies: none
*/
void setDisplayFlag(HeapType *heap, bool flagSet)
{
    heap->displayFlag = flagSet;
}

/*
Name: showArray
Process: displays array as is, from lowest index to highest
Function input/parameters: heap data (HeapType)
Function output/parameters: none
Function output/returned: none
Device input/---: none
Device output/monitor: array displayed as specified
Dependencies: getPatientInfo, printf
*/
void showArray(HeapType heap)
{
    // variables
    int index;
    char patientInfoStr[STD_STR_LEN];

    // loop through the heap
    for (index = 0; index < heap.size; index++)
    {
        // get the info and print it
        getPatientInfo(patientInfoStr, heap.array[index]);
        printf("%s\n", patientInfoStr);                           
    }
}

/*
Name: trickleDownArrayHeap
Process: recursively rebalances heap after data removal,
         every child has a lower priority or later arrival time than its parent,
         displays trickle down actions to screen
Function input/parameters: heap data (HeapType *), current index (int)
Function output/parameters: updated heap data (HeapType *)
Function output/returned: none
Device input/---: none
Device output/monitor: trickle down operations displayed as specified
Dependencies: setPatientFromStruct, comparePriority, getPatientInfo,
              printf, trickleDownArrayHeap (recursively), others acceptable
*/
void trickleDownArrayHeap(HeapType *heap, int currentIndex)
{
    // initialize variables
   int leftChild, rightChild, largerChild;
   char patientStr[STD_STR_LEN];

   // find the children's indices from the current one
   leftChild = currentIndex * 2 + 1;
   rightChild = leftChild + 1;

   // check for both child indices less than the array size
   if(leftChild < heap->size)
   {
      if(rightChild < heap->size)
      {
         // compare both children
         largerChild = comparePriority(heap->array[leftChild],
                                        heap->array[rightChild]);

         // check if leftChild is largerChild
         if(largerChild > 0)
         {
            // check if we can swap
            if(heap->displayFlag)
            {
               // display trickle down data
               printf("   - Trickle down swap:\n");

               // display moving down and up
               getPatientInfo(patientStr, heap->array[currentIndex]);
               printf("     - moving down parent: %s\n", patientStr);
               getPatientInfo(patientStr, heap->array[leftChild]);
               printf("     - moving up left child: %s\n", patientStr);
            }

            // swap left child with parent
            heap->array[currentIndex] = heap->array[leftChild];
            heap->array[leftChild] = heap->array[heap->size];

            // call the function recursively with that child's index
            trickleDownArrayHeap(heap, leftChild);
         }

         // else, rightChild is largerChild
         else
         {
            // check if we can swap
            if(heap->displayFlag)
            {
               // display trickle down data
               printf("   - Trickle down swap:\n");
               getPatientInfo(patientStr, heap->array[currentIndex]);

               // display moving down and up
               printf("     - moving down parent: %s\n", patientStr);
               getPatientInfo(patientStr, heap->array[rightChild]);
               printf("     - moving up right child: %s\n", patientStr);
            }

            // swap right child with parent
            heap->array[currentIndex] = heap->array[rightChild];
            heap->array[rightChild] = heap->array[heap->size];

            // call the function recursively with that child's index
            trickleDownArrayHeap(heap, rightChild);
         }
      }

      // else
      else
      {
         // swap leftChild
         heap->array[currentIndex] = heap->array[leftChild];
         heap->array[leftChild] = heap->array[heap->size];
      }
   }
}