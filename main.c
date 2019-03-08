#include<stdio.h>

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

*/

void main(int argc, char** argv){ //Main function that accepts a command line argument
	
	int sackCapacity, ret;
	char buffer[120];

        if (argc == 1){ //No command line argument detected
                printf("Input knapsack capacity: ");
                fgets(buffer, 120, stdin);
                ret=sscanf(buffer, "%d", &sackCapacity);
	}
        else if(argc != 2){ //Invalid # of command line arguments
                printf("Invalid input.\n");
		return;
        }
        else{ //Correct number of arguments
                ret = sscanf(argv[1], "%d", &sackCapacity);
        }
	if (ret != 1 || sackCapacity < 1 || sackCapacity > 1024){ //Invalid user input
		printf("Invalid input.\n");
		return;
	}
	printf("Knapsack capacity is %d\n", sackCapacity); //Valid user input
	
	return;
}
