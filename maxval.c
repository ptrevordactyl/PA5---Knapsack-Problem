#include "custom.h"

struct result maxval(int cap){
  //Base case
  sack[0].value=0;
  sack[0].made=1;

  //this if statement will check the array that contains already calculated capacities
  if(sack[cap].made == 1){
    return sack[cap];
  }
  struct result best;
  best.value = 0;
  int i;
  //this for loop should continue comparing items until it runs out of items in the array that stored the items originally given
  for(i = 0; items[i].wt != 0; i++){
    if(items[i].wt <= cap){
      struct result temp = maxval(cap - items[i].wt);
      if(items[i].val + temp.value > best.value){
        best = temp;
	best.value += items[i].val;
	best.itemcount[i]++;
      }
    }
  }
  
  //I'm using this to try and store what this weight capacity gives in the array of results for the dynamic programming part
  sack[cap].value = best.value;
  for(int j = 0; j < 128; j++){
    sack[cap].itemcount[j] = best.itemcount[j];
  }
  sack[cap].made = 1;
  return best;
}
