#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "Console_IO_Utility.h"
#include "File_Input_Utility.h"

static const char filename[] = "gasstations.txt";

typedef struct gasStation
   {
    char stationName[ 100 ];
    char stationAddress[ 100 ];
    double price;
   } gasStationType;


int main( int argc, char *argv[] )
   {

        //int counter = 0;
        char fileName[ 100 ];
        FILE *file = fopen(filename, "r");
        char line;
        openInputFile(fileName);
        line = fgetc(file);

        printf("list of gas stations near NAU\n\n");
        while(line != EOF)
        {
          printf("%c", line);
          line = fgetc(file);
        }
        /*while( !checkForInputFileOpen() )
        {
            //readIntegerFromFile();

            counter++;
        }*/

        //gasStationType gasStation[ counter ];




   }
