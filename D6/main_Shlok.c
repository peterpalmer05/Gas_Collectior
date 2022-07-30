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
   } gasStationType;


bool storeData( gasStationType gasStations[], char fileName[] );

void swapGasStation( gasStationType gasStationOne, gasStationType gasStationTwo );

void runBubbleSort( gasStationType gasStations[], int size );

int main( int argc, char *argv[] )
   {

      
      char fileName[ 100 ] = "gasStation.txt";
      gasStationType gasStations[ 5 ];

      if( storeData( gasStations, fileName ) )
      {
         
         for( int x = 0; x < 5; x++ )
         {
            printf( "%s\n",gasStations[x].stationName );
         }
         
         
      }

      runBubbleSort(gasStations, 5) ;

      for( int x = 0; x < 5; x++ )
         {
            printf( "%s\n",gasStations[x].stationName );

         }

      

      
      return 0;
        
   }

void runBubbleSort( gasStationType gasStations[], int size )
{
    bool swapped = true;
    int index;

    while (swapped)
    {
        swapped = false;
        for( index = 0; index < size - 1; index++ )
        {

            if( gasStations[index].price - gasStations[index + 1].price > 0 )
            {
                swapGasStation( gasStations[index], gasStations[index+1]);
                swapped = true;
            }
        }
    }
}


bool storeData( gasStationType gasStations[], char fileName[] )
{
   int counter = 0;
   
   openInputFile(fileName);

      while( !checkForEndOfInputFile() )
      {

         readStringToLineEndFromFile(gasStations[counter].stationName);

         readStringToLineEndFromFile(gasStations[counter].stationAddress);

         gasStations[counter].price = readDoubleFromFile();

         counter++;
      }
      closeInputFile();

      return true;
}

void swapGasStation( gasStationType gasStationOne, gasStationType gasStationTwo )
{
   gasStationType temp;

   printf("help");

   strcat( temp.stationName, gasStationTwo.stationName );

   strcat( temp.stationAddress, gasStationTwo.stationAddress );

   temp.price = gasStationTwo.price;

   strcat( gasStationTwo.stationName, gasStationOne.stationName );

   strcat( gasStationTwo.stationAddress, gasStationOne.stationAddress );

   gasStationTwo.price = gasStationOne.price;

   strcat( gasStationOne.stationAddress, temp.stationAddress );

   strcat( gasStationOne.stationName, temp.stationName );

   gasStationOne.price = temp.price;
   

}