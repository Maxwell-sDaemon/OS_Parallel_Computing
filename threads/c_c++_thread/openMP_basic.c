#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define N 10

int main(int argc, char *argv[])
{
	int i, j;

	int *a = (int*) malloc(sizeof(int)* N);
	int *b = (int*) malloc(sizeof(int)* N);
	int *c = (int*) malloc(sizeof(int)* N);
	
	for (i = 0 ; i < N ; i++) {
		a[i] = i;
		b[i] = i;
		c[i] = i;
	}
	/* sequential code */
		
	#pragma omp parallel
	{
		printf("I am a parallel region.");
	}

		

	return 0;
}
