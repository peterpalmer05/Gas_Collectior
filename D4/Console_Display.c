// header files
#include <stdlib.h> // for malloc, free
#include <stdio.h>  // for printf
#include <string.h> // for strlen
#include <math.h>   // for srand/rand
#include <time.h>   // for srand
#include "StandardConstants.h"




/*
might need to work on something for this in the future

int Longest_Length( gasStationType *Gas_Station_List)
	{
		int longest_length = 0, testlength = 0, index = 0;
		
		while(Gas_Station_List[index] != NULL)
		{
			while(Gas_Station_List[index] != NULL)
			{
				
			}
			
			
			index++
		}
		
		
		
	}
*/
int Array_Length(gasStationType *Station_List, int index, int wantedEntry)
	{
		int length = 0;
		
		
		if(wantedEntry = 1)
		{
			length = strlen(Station_List[index]->stationName);	
		}
		if(wantedEntry = 2)
		{
			length = strlen(Station_List[index]->stationAddress);		
		}
		
		return length;
	}



void Create_Lines ()
	{	
		int index = 0;
		
		while(index < 208)
		{
			printf("%c", DASH);
			index++;
		}
		printf("/n");
	}

void Table_Entries(gasStationType *Station_List)
{
	int index = 0, arrayIndex
	int length = 0;
	while(arrayIndex < Station_List->size)
	{
		printf("%c", PIPE);
		printf("%s", Station_List[arrayIndex]->stationName);
		length = 99 - Array_Length(Station_List, arrayIndex, 1);
		while(index < length)
		{
			printf("%c", SPACE);
			index++;
		}
		index = 0;
		printf("%c", PIPE);
		printf("%s", Station_List[arrayIndex]->stationAddress);
		length = 99 - Array_Length(Station_List, arrayIndex, 2);
		while(index < length)
		{
			printf("%c", SPACE);
			index++;
		}
		printf("%c", PIPE);
		printf('%d', Station_List[arrayIndex]->price);
		printf("%c\n", PIPE);
		Create_Lines();
		arrayIndex++;
	}
	
}


void Table_Headers()
{
	char* station_Name = "Gas Station", address = "Station Adress",
		price = "Price";
	int index = 0;
	
	printf("%c", PIPE);
	printf("%s", station_Name);
	while(index < 88)
	{
		printf("%c", SPACE);
		index++;
	}
	index = 0;
	printf("%c", PIPE);
	printf("%s", address);
	while(index < 85)
	{
		printf("%c", SPACE);
		index++;
	}
	printf("%c", PIPE);
	printf('%s', Price);
	printf("%c\n", PIPE);
	Create_Lines();
}