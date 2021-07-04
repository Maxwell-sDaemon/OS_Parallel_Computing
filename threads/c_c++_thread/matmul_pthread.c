/*matrix vector multiplication m x n matrix by a n size vector*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* Pth_mat_vect(void* rank);

int thread_count;
int m;
int n;
int **A;
int *x;
int *y;

int main(int argc, char* argv[]) {

	int i, j;
	printf("m:");
	scanf("%d", &m);
	printf("n:");
	scanf("%d", &n);
	
	
	A = (int**) malloc(sizeof(int*) * m);
	for( i = 0 ; i < m ; i++){	
		A[i] = (int*) malloc(sizeof(int) * n);
	}
	x = (int*) malloc(sizeof(int) * n);
	y = (int*) malloc(sizeof(int) * n);
	printf("enter matrix\n");
	for( i = 0 ; i < m ; i++) {
		for ( j = 0 ; j < n ; j++) {
			scanf("%d",&A[i][j]);
		}
		printf("end of row \n");
	}

	printf("enter vector\n");
	for( j = 0 ; j < n ; j++){
		scanf("%d",&x[j]);
	}

	long thread;
	pthread_t* thread_handles;

	thread_count = strtol(argv[1], NULL, 10);
	thread_handles = (pthread_t*) malloc( thread_count * sizeof(pthread_t));

	for( thread = 0 ; thread < thread_count ; thread++ ) {
		pthread_create(&thread_handles[thread], NULL, Pth_mat_vect, (void*) thread);
	}

	printf("in the main thread\n");

	for( thread = 0 ; thread < thread_count ; thread++) {
		pthread_join(thread_handles[thread], NULL);
	}

	free(thread_handles);

	printf("process is end.\n");

	return 0;
}

void* Pth_mat_vect(void* rank) {
	long my_rank = (long) rank;
	int i, j;
	int local_m = m/thread_count;
	int my_first_row = my_rank*local_m;
	int my_last_row = (my_rank+1)*local_m - 1;
	
	for (i = my_first_row; i <= my_last_row; i++) {
		y[i] = 0.0;
		for (j = 0; j < n; j++)
			y[i] += A[i][j]*x[j];
	}

	return NULL;
}/* Pth mat vect */

