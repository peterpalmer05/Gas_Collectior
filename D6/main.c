#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "Console_IO_Utility.h"
#include "File_Input_Utility.h"

static const char filename[] = "gasstations.txt";

typedef struct gasStationStruct
   {
    char stationName[ 100 ];
    char stationAddress[ 100 ];
    char line;
    double price;
    struct gasStationStruct *nextPtr;
   } gasStationType;
// these functions are Paul's code
gasStationType *storeList(gasStationType *headPtr, FILE *file);
gasStationType *initializeIterNode();


int main( int argc, char *argv[] )
   {
        FILE *file = fopen(filename, "r");
        gasStationType *headPtr = (gasStationType *)malloc(sizeof(gasStationType));

        printf("list of gas stations near NAU\n\n");
        // first we need to store the data into the linked list
        storeList(headPtr, file);

        return 0;
   }

   gasStationType *storeList(gasStationType *headPtr, FILE *file)
   {

     // initialize wkgPtr
     gasStationType *wkgPtr = initializeIterNode();
     fgets(headPtr->stationName, 100, file);
     // debug printf
     printf("%s", headPtr->stationName);
     wkgPtr = headPtr;
     // debug printf
     // printf("%s", wkgPtr->stationName);
     // read each line in file until NULL
     while(fgets(wkgPtr->stationName, 100, file) != NULL)
     {
       wkgPtr = wkgPtr->nextPtr;
       readStringToLineEndFromFile(wkgPtr->stationName);
       // debug printf
       printf("%s", wkgPtr->stationName);
     }

     return NULL;
   }

   gasStationType *initializeIterNode()
   {
     gasStationType *wkgPtr = (gasStationType *)malloc(sizeof(gasStationType));
     wkgPtr->nextPtr = NULL;
     return wkgPtr;
   }
