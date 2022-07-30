#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>
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



static void activate (GtkApplication *app, gpointer user_data);

void bubbleSortDist();

void bubbleSortPrice();

void clearMem();

void clearMemHelper(int index);

int countLines(char *fileName);

static void print_example (GtkWidget *widget, gpointer   data);

static void print_example2 (GtkWidget *widget, gpointer   data);

void storeData(char *fileName);

void swapGasStation( int index1, int index2);


//hate doing this but I dont have time to figure out a better way
gasStationType **gasStations;

int arraySize;



int main( int argc, char *argv[] )
   {
	

	GtkApplication *gas_collector;
	
	int stat;
	int index = 0;
    char fileName[ 20 ] = "gasStation.txt";
	arraySize = countLines("gasStation.txt");
	
	gasStations = malloc(arraySize * sizeof(gasStationType));
	//a constructor would be nice for this
	for(index;index < arraySize; index++)
	{
		gasStations[index] = malloc(sizeof(gasStationType));
	}
	
	storeData(fileName);

	gas_collector = gtk_application_new ("com.github.LukeDomby", G_APPLICATION_FLAGS_NONE);
	//should allow me to create a proof of concept
	g_signal_connect (gas_collector, "activate", G_CALLBACK (activate), NULL);
	
	stat = g_application_run (G_APPLICATION (gas_collector), argc, argv);
	
	g_object_unref (gas_collector);
	
	clearMem();
	
    return 0;    
   }
   


static void activate (GtkApplication *app, gpointer user_data)
{
	GtkWidget *display;
	GtkWidget *displayGrid;
	GtkWidget *button;

	//attempt to create a window and name it
	display = gtk_application_window_new (app);
	
	gtk_window_set_title (GTK_WINDOW (display), "Gas Collector");
	gtk_window_set_default_size (GTK_WINDOW (display), 200, 400);

	//make a grid to display butons on
	displayGrid = gtk_grid_new ();

	//make grid in the window
	gtk_window_set_child (GTK_WINDOW (display), displayGrid);
	//put button 1 into grid
	button = gtk_button_new_with_label ("Display by Distance");
	
	g_signal_connect (button, "clicked", G_CALLBACK (print_example), NULL);

	//fill 2 grid cells with first button
	gtk_grid_attach (GTK_GRID (displayGrid), button, 0, 0, 2, 1);

	//same as before
	button = gtk_button_new_with_label ("Display by Price");	
	
	g_signal_connect (button, "clicked", G_CALLBACK (print_example2), NULL);

	//place bellow the first one
	gtk_grid_attach (GTK_GRID (displayGrid), button, 0, 1, 2, 1);

	button = gtk_button_new_with_label ("Close Gas collector");
	
	g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_window_destroy), display);

	/* Place the Quit button in the grid cell (0, 1), and make it
	* span 2 columns.
	*/
	gtk_grid_attach (GTK_GRID (displayGrid), button, 2, 1, 1, 1);

	gtk_widget_show (display);

}

void bubbleSortPrice()
{
   int i, j;
   for( i = 0; i < arraySize-1; i++ )
   {
      for( j = 0; j < arraySize - i - 1; j++ )
      {
         if(gasStations[j]->price > gasStations[j+1]->price)
         {
            swapGasStation(j, j+1);
         }
      }
   }
}

void bubbleSortDist()
{
   int i, j;
   for( i = 0; i < arraySize-1; i++ )
   {
      for( j = 0; j < arraySize - i - 1; j++ )
      {
         if(gasStations[j]->dist > gasStations[j+1]->dist)
         {
            swapGasStation(j, j+1);
         }
      }
   }
}
int countLines(char *fileName)
{
	FILE *input;
	char current;
	int index = 1,fuck;
	
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

void clearMem()
{
	int index = 0;
	for(index; index<arraySize;index++)
	{
		clearMemHelper(index);
	}
	free(gasStations);	
}

void clearMemHelper(int index)
{
	free(gasStations[index]);
}


static void print_example (GtkWidget *widget, gpointer   data)
{
	int index = 0;
	bubbleSortDist(arraySize);
	g_print ("\nClosest to Furthest\n");
	while(index < arraySize)
	{
		g_print (" %s %s %.2f miles \n", gasStations[index]->stationName, 
		gasStations[index]->stationAddress, gasStations[index]->dist);
		index++;
	}
}

static void print_example2 (GtkWidget *widget, gpointer   data)
{
	int index = 0;
	bubbleSortPrice(arraySize);
	g_print ("\nLowest Cost to Highest\n");
	while(index < arraySize)
	{

		g_print (" %s %s %.2f \n", gasStations[index]->stationName, 
		gasStations[index]->stationAddress, gasStations[index]->price);
		index++;
	}
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

