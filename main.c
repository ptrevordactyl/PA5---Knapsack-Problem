/*
Ethan Pongon
Ryan Whittingham
Trevor Holland
PA5 - Knapsack Problem
*/

#include "custom.h"

// I wrote this without implementing the argc and argv stuff so we just need to switch out the capacity variable with that.
void main(){
  int capacity = 12;
  FILE* fp;
  char buffer[120];
  int i = 0;
  fp = fopen("knapsack.data", "r");
  while(fgets(buffer,120,fp) != NULL){
    sscanf(buffer, "%d %d %s", &items[i].wt, &items[i].val, items[i].name);
    i = i + 1;
  }  
  fclose(fp);

  struct result final = maxval(capacity);

  int j = 0;
  printf("There are ");
  while(j <  128){
    if(final.itemcount[j] != 0){
      printf("%d %s, ", final.itemcount[j], items[j].name);
    }
    j = j + 1;
  }
  printf("in the sack \n");
}
