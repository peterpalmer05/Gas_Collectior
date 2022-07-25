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

gasStationType *storeList(gasStationType *headPtr, FILE *file);
gasStationType *initializeIterNode();
int main( int argc, char *argv[] )
   {

        gasStationType *headPtr = (gasStationType *)malloc(sizeof(gasStationType));
        FILE *file = fopen(filename, "r");

        //openInputFile(fileName);
        // first we need to store the data into the 2D char array
        printf("list of gas stations near NAU\n\n");

        storeList(headPtr, file);

        return 0;

   }

   gasStationType *storeList(gasStationType *headPtr, FILE *file)
   {

     //char line;
     gasStationType *wkgPtr = initializeIterNode();
     fgets(headPtr->stationName, 100, file);
     // debug printf
     printf("%s", headPtr->stationName);
     wkgPtr = headPtr;
     // debug
     //printf("%s", wkgPtr->stationName);
     readStringToLineEndFromFile(wkgPtr->stationName);
     while(fgets(wkgPtr->stationName, 100, file) != NULL)
     {
       wkgPtr = wkgPtr->nextPtr;
       readStringToLineEndFromFile(wkgPtr->stationName);
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
