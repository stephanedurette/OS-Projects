#include <gtk/gtk.h>
#include <string.h>
#include <stdio.h>

void ping(GtkWidget *pingButton, GtkWidget *ipNumbers[]){

	char buffer[255];
	char *ipPart1, *ipPart2, *ipPart3, *ipPart4, *pings;

	ipPart1 = (char*)gtk_entry_get_text(GTK_ENTRY(ipNumbers[0]));
	ipPart2 = (char*)gtk_entry_get_text(GTK_ENTRY(ipNumbers[1]));
	ipPart3 = (char*)gtk_entry_get_text(GTK_ENTRY(ipNumbers[2]));
	ipPart4 = (char*)gtk_entry_get_text(GTK_ENTRY(ipNumbers[3]));

	pings = (char*)gtk_entry_get_text(GTK_ENTRY(ipNumbers[4]));


	snprintf(buffer, 255, "ping %s.%s.%s.%s -c %s | tee ping_res.txt", ipPart1, ipPart2, ipPart3, ipPart4, pings);
	printf("%s",buffer);

	system(buffer);

	return;
}

static void activate(GtkApplication* app, gpointer user_data)
{

	GtkWidget *window;
	GtkWidget *grid;
	GtkWidget *number1, *number2, *number3, *number4, *pingCount;
	GtkWidget *ipNumbers[5];
	GtkWidget *ipLabel, *pingCountLabel;
	GtkWidget *pingButton;
	
	//Set up the window
	window = gtk_application_window_new(app);
	gtk_window_set_title(GTK_WINDOW(window), "Ping Tester V1.0");
	gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);

	//this function destroys the window and exits gtk_main when the close x is pressed
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit),NULL);

	grid = gtk_grid_new();
	gtk_container_add(GTK_CONTAINER(window),grid);


	ipLabel = gtk_label_new("Enter IPV4 Address");
	gtk_grid_attach(GTK_GRID(grid), ipLabel, 0, 0, 2, 1);

	//Create feilds for entering IP address and attach them to Grid
	number1 = gtk_entry_new();//last four arguments are column,row, Objsize colums, Objsize rows 
	gtk_grid_attach(GTK_GRID(grid), number1, 0,3,1,1);

	number2 = gtk_entry_new();
	gtk_grid_attach(GTK_GRID(grid), number2, 1,3,1,1);

	number3 = gtk_entry_new();
	gtk_grid_attach(GTK_GRID(grid), number3, 2,3,1,1);

	number4 = gtk_entry_new();
	gtk_grid_attach(GTK_GRID(grid), number4, 3,3,1,1);

	ipNumbers[0] = number1;
	ipNumbers[1] = number2;
	ipNumbers[2] = number3;
	ipNumbers[3] = number4;

	pingCountLabel = gtk_label_new("Ping Count");
	gtk_grid_attach(GTK_GRID(grid), pingCountLabel, 0, 4, 2, 1);

	pingCount = gtk_entry_new();
	gtk_grid_attach(GTK_GRID(grid), pingCount, 0,5,1,1);

	ipNumbers[4] = pingCount;

	//Create the pingButton
	pingButton = gtk_button_new_with_label("Ping!");

	//Use clciked signal from ping button to call ping function
	g_signal_connect(pingButton, "clicked", G_CALLBACK(ping), ipNumbers);
	gtk_grid_attach(GTK_GRID(grid), pingButton, 2,5,2,1); //attach ping button to grid


	gtk_widget_show_all(window);
	gtk_main();
}


int main(int argc, char **argv){

	GtkApplication *app;

	int status;
	
	app = gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);
	g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
	status = g_application_run(G_APPLICATION(app), argc, argv);
	g_object_unref(app);
	
	return status;
}

