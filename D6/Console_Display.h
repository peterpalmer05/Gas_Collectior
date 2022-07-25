#ifndef CONSOLE_DISPLAY_H
#define CONSOLE_DISPLAY_H

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
int Array_Length(gasStationType *Station_List, int index, int wantedEntry);



void Create_Lines ();


void Table_Entries(gasStationType *Station_List);


void Table_Headers();
