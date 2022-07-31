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

/*I am trying to combine code that wasnt made to work together
this hurts me on a new level, I am having to resort to using
global variables. Ttakes too long to make a proper class to store data
plus most of our code is formated as  their own main file,
we didnt make a single main to work with and its haunting me*/


int countLines(char *fileName);

void storeData(char *fileName);

void swapGasStation( int index1, int index2);

void bubbleSortDist();

void bubbleSortPrice();

gasStationType **gasStations;

int arraySize;






int main( int argc, char *argv[] )
{

	//int stat;
	int index = 0;
    char fileName[ 20 ] = "gasStation.txt";
	arraySize = countLines("gasStation.txt");

	gasStations = malloc(arraySize * sizeof(gasStationType));
	for(index;index < arraySize; index++)
	{
		gasStations[index] = malloc(sizeof(gasStationType));
	}


	storeData(fileName);
	/*for( int x = 0; x < arraySize; x++ )
	{
		//printf( "%.2f\n",gasStations[x].price );
		printf("%s\n",gasStations[x].stationName);
	}
	*/
  bubbleSortDist();
  bubbleSortPrice();
    return 0;
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

void storeData(char *fileName)
{
   int index = 0;

    openInputFile(fileName);
    while ( index < arraySize )
	{
        readStringToLineEndFromFile(gasStations[index]->stationName);

        readStringToLineEndFromFile(gasStations[index]->stationAddress);

        gasStations[index]->price = readDoubleFromFile();

		gasStations[index]->dist = readDoubleFromFile();

		gasStations[index]->flag = 1;

		index++;

	}

      closeInputFile();
}

void swapGasStation(int index1, int index2)
{
   gasStationType *temp = malloc(sizeof(gasStationType));

   temp = gasStations[index1];

   gasStations[index1] = gasStations[index2];

   gasStations[index2] = temp;
}

void bubbleSortPrice()
{
  printf("Testing bubbleSortPrice()\n\n");
   int i, j;
   for( i = 0; i < arraySize-1; i++ )
   {
      for( j = 0; j < arraySize - i - 1; j++ )
      {
         // debug code
         printf("gasStations[%d]->price : $%.2lf\n", j, gasStations[j]->price);
         printf("gasStations[%d]->price : $%.2lf\n", j+1, gasStations[j+1]->price);
         if(gasStations[j]->price > gasStations[j+1]->price)
         {
            swapGasStation(j, j+1);
            printf("gasStations[%d]->price now is: $%.2lf\n", j, gasStations[j]->price);
            printf("gasStations[%d]->price now is: $%.2lf\n\n", j+1, gasStations[j+1]->price);
         }
         // debug code
         else {
            printf("no swap this time\n\n");
         }
      }
   }
}

void bubbleSortDist()
{
   printf("Testing bubbleSortDist():\n\n");
   int i, j;
   for( i = 0; i < arraySize-1; i++ )
   {
      for( j = 0; j < arraySize - i - 1; j++ )
      {
         // debug code
         printf("gasStations[%d]->dist : %.2lf\n", j, gasStations[j]->dist);
         printf("gasStations[%d]->dist : %.2lf\n", j+1, gasStations[j+1]->dist);
         if(gasStations[j]->dist > gasStations[j+1]->dist)
         {
            swapGasStation(j, j+1);
            printf("gasStations[%d]->dist now is: %.2lf\n", j, gasStations[j]->dist);
            printf("gasStations[%d]->dist now is: %.2lf\n\n", j+1, gasStations[j+1]->dist);
         }
         // debug code
         else {
            printf("no swap this time\n\n");
         }
      }
   }
}
