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
Work division:
Trevor	- Knapsack.data reading and displaying, header file, tidying up
Ethan	- MaxVal, main program results display
Ryan	- Main program argument handling, Makefile, printf formatting
*/

#include "custom.h"

void main(int argc, char** argv){
	char buffer[120];
	int ret, capacity;
	//------ARGUMENT HANDLING------
	if (argc == 1){ //No command line argument detected
		printf("\nInput knapsack capacity: ");
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
	//------FILE READING------
	int i=sackinfo();
	//------PRINT SACK CONTENTS------
	int itemcount;
	printf("\nAvailable Items\n");
	printf("------------------------------\n");
	printf("Weight	Value	Name\n");
	printf("------	-----	----\n");
	for(itemcount=0; itemcount < i; itemcount++){
		printf(" %d	%d	%s\n", items[itemcount].wt, items[itemcount].val, items[itemcount].name);
	}
	printf("------------------------------\n");
	//------RESULTS------
	int j;
	for(j=0; j<1025; j++){//Init global array that stores  maxval() calculations
		sack[j].value=0;
		for(int k=0; k<128; k++){
			sack[j].itemcount[k]=0;
		}
		sack[j].made=0;
	}	
	struct result final = maxval(capacity);
	j = 0;
	printf("\nKnapsack capacity=%d\n", capacity);
	printf("Max value=%d\n", final.value);
	printf("Contents:\n");
	while(j < 128){
		if(final.itemcount[j] != 0){
			printf("%d %s\n", final.itemcount[j], items[j].name);
		}
		j++;
	}
}
