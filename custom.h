#include <stdio.h>
#include <stdlib.h>

struct result{
	int value;
	int itemcount[128];
	int made;
};

struct bag{
	int wt;
	int val;
	char name[64];
};

struct bag items[128];

struct result sack[1025];

struct result maxval(int);

int sackinfo();
