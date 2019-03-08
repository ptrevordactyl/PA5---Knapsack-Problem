#include <stdio.h>
#include <stdlib.h>

struct result{
	int value;
	int itemcount[128];
};

struct bag{
	int wt;
	int val;
	char name[64];
};

struct bag sack[1024];

struct result maxval(int);

int sackinfo();
