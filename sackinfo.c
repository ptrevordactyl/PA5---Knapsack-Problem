/**=================================
Trevor Holland
Sack info:
reads from the file "knapsack.data"
and stores that information in
a global array.
=================================**/

#include "custom.h"

int sackinfo()
{
	FILE* fp;
	char buffer[120];
	int i=0;
	fp=fopen("knapsack.data","r"); //open file for reading
	while(fgets(buffer,120,fp) != NULL) //read until end of file
	{
		sscanf(buffer,"%d %d %s",&items[i].wt, &items[i].val, items[i].name); //read weight, value, and name of item from file. "sack" is a global variable
		i++; //count number of item types
	}
	fclose(fp);
	return i;
}
