#include <stdio.h>

void function1 (int n, double array[n]) {
	double localarray[n];
	printf("len: %lu\n", sizeof(localarray));
}
