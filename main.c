/* 
Ryan Whittingham
Trevor Holland
Ethan Pongon
CSE222-PA5: The Knapsack Problem
-----------------------------------------------
PA5 is a C program that calculates the maximum 
value a knapsack of a given size can hold of 
specific items.
-----------------------------------------------
Word division:
Trevor	- Knapsack.data reading and displaying, header file, tidying up
Ethan	- MaxVal, main program results display
Ryan	- Main program argument handling, Makefile
*/

#include "custom.h"

void main(int argc, char** argv){
	char buffer[120];
	int ret, capacity;
	//------ARGUMENT HANDLING------
	if (argc == 1){ //No command line argument detected
		printf("Input knapsack capacity: ");
		fgets(buffer, 120, stdin);
		ret=sscanf(buffer, "%d", &capacity);
	}
	else if(argc != 2){ //Invalid # of command line arguments
		printf("Invalid input.\n");
		return;
	}
	else{ //Correct number of arguments
		ret = sscanf(argv[1], "%d", &capacity);
	}
	if (ret != 1 || capacity < 1 || capacity > 1024){ //Invalid user input
		printf("Invalid input.\n");
		return;
	}
	printf("Knapsack capacity is %d\n", capacity); //Valid user input
	//------FILE READING------
	int i=sackinfo();
	//------PRINT SACK CONTENTS------
	int itemcount;
	printf("Sack contents:\n");
	for(itemcount=0; itemcount < i; itemcount++){
		printf("%d %d %s\n", items[itemcount].wt, items[itemcount].val, items[itemcount].name);
	}
	//------RESULTS------
	struct result final = maxval(capacity);
	int j = 0;
	printf("There are ");
	while(j < 128){
		if(final.itemcount[j] != 0){
			printf("%d %s, ", final.itemcount[j], items[j].name);
		}
		j++;
	}
	printf("in the ideal sack\n");
}
