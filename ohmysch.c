#include <stdio.h>
#include <sqlite3.h>
 
int main(void)
{ 
    int rc;
	rc = 0;
    sqlite3 *db;
	// char *path = "file://home/hycho/.local/bin/cmdo.db";
	// when using absoulute path, error occured >> not fixed yet
 
    rc = sqlite3_open("/home/hycho/.local/bin/cmdo.db", &db);
 
    if(!rc)
	{
		printf("  _     ___ _____ _____   ___ ____    _____ ___  ____ _______   __  _______        _____  \n"); 
		printf(" | |   |_ _|  ___| ____| |_ _/ ___|  |  ___/ _ \\|  _ |_   _\\ \\ / / |_   _\\ \\      / / _ \\ \n");
		printf(" | |    | || |_  |  _|    | |\\___ \\  | |_ | | | | |_) || |  \\ V _____| |  \\ \\ /\\ / | | | |\n");
		printf(" | |___ | ||  _| | |___   | | ___) | |  _|| |_| |  _ < | |   | |_____| |   \\ V  V /| |_| |\n");
		printf(" |_____|___|_|   |_____| |___|____/  |_|   \\___/|_| \\_\\|_|   |_|     |_|    \\_/\\_/  \\___/ \n");
		printf("\n");
	}
	else
		printf("NEED initializing by enter 'cmdo' command OR CHECK sqlite3_open PATH\n"); 
 
    sqlite3_close(db);

    return 0;
}

