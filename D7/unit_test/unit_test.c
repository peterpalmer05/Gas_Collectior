#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "Console_IO_Utility.h"
#include "File_Input_Utility.h"


typedef struct gasStationStruct
   {
    char stationName[ 100 ];
    char stationAddress[ 100 ];
    double price;
	double dist;
	int flag;
   } gasStationType;

void storeData(char *fileName);

int countLines(char *fileName);

int arraySize;

gasStationType **gasStations;

int main(int argc, char const *argv[])
{
    /* test storeData */
    //int stat;
  	int index = 0;
    char fileName[ 20 ] = "gasStation.txt";

  	arraySize = countLines("gasStation.txt");

  	gasStations = malloc(arraySize * sizeof(gasStationType));
  	//a constructor would be nice for this
  	for(index;index < arraySize; index++)
  	{
  		gasStations[index] = malloc(sizeof(gasStationType));
  	}
	printf("Unit testing for storeData(char *fileName):\n\n\n");
  	storeData(fileName);
  	printf("\n");
    return 0;
}


  void storeData(char *fileName)
  {
     int index = 0;
     printf("List of gas stations:\n\n");
      openInputFile(fileName);
      while ( index < arraySize )
  	  {
          readStringToLineEndFromFile(gasStations[index]->stationName);
          // debug
          printf("%s  ", gasStations[index]->stationName);
          readStringToLineEndFromFile(gasStations[index]->stationAddress);
          printf("%s  ", gasStations[index]->stationAddress);
          gasStations[index]->price = readDoubleFromFile();
          printf("%.2lf\n", gasStations[index]->price);
  		    gasStations[index]->dist = readDoubleFromFile();

  		    gasStations[index]->flag = 1;

  		    index++;
  	}
  }

    int countLines(char *fileName)
    {
    	FILE *input;
    	char current;
    	int index = 1;

    	input = fopen(fileName, "r");

    	while((current = fgetc(input)) != EOF)
    	{
    		if(current == '\n')
    		{
    			index++;
    		}
    	}
    	fclose(input);
    	return (index/4);
    }
