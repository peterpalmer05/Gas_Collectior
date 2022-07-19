#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "Console_IO_Utility.h"
#include "File_Input_Utility.h"

typedef struct gasStation
   {
    char stationName[ 100 ];
    char stationAddress[ 100 ];
    double price;
   } gasStationType;


int main( int argc, char *argv[] )
   {

        int counter;
        char fileName[ 100 ];
        

        openInputFile(fileName);

        while( !checkForInputFileOpen() )
        {
            readIntegerFromFile();

            counter++;
        }

        gasStationType gasStations[ counter ];




   }
