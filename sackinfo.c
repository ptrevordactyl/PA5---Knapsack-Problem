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
	if(access("knapsack.data", R_OK) != -1)
	{
		fp=fopen("knapsack.data","r"); //open file for reading
		while(fgets(buffer,120,fp) != NULL) //read until end of file
		{
			if(3 == sscanf(buffer,"%d %d %s",&items[i].wt, &items[i].val, items[i].name)) i++; //read weight, value, and name of item from file. "sack" is a global variable. i counts number of item types
			else //knapsack.data is structured incorrectly
			{
				printf("ERROR: INVALID DATA IN knapsack.data\n");
				exit(0);
			}
		}
		fclose(fp);
		return i;
	}
	else
	{
		printf("ERROR, THE FILE knapsack.data DOES NOT EXIST\n");
		exit(0);
	}
}
