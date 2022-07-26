#include <gtk/gtk.h>


//used info learned from examples from gtk to create basic proof of concept
//in future use creating own gui will be needed, for now need to test tech
static void print_example (GtkWidget *widget, gpointer   data)
{
	g_print ("\nclose\n closer\n closest\n");
}

static void print_example2 (GtkWidget *widget, gpointer   data)
{
	g_print ("\na\n b\n c\n");
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
	button = gtk_button_new_with_label ("Display by Name");	
	
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

int main (int argc, char **argv)
{
	
	GtkApplication *gas_collector;
	int stat;
	
	gas_collector = gtk_application_new ("com.github.LukeDomby", G_APPLICATION_FLAGS_NONE);
	//should allow me to create a proof of concept
	g_signal_connect (gas_collector, "activate", G_CALLBACK (activate), NULL);
	
	stat = g_application_run (G_APPLICATION (gas_collector), argc, argv);
	
	g_object_unref (gas_collector);

  return stat;
}