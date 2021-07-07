#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
int thread_count;
long long int number_in_circle;
long long int number_of_tosses;
double pi_;

pthread_mutex_t mutex;

void* pi_estimate(void * rank);

// first person , second number of try for person 
int main(int argc, char* argv[])
{
	long thread;
	srand(time(NULL));

	int i , j;

	pthread_t* thread_handles; 
	number_in_circle = 0;
	number_of_tosses = 0;
	pi_ = 0;

	thread_count = strtol(argv[1], NULL, 20);
	number_of_tosses = strtol(argv[2], NULL, 20);

	if ( thread_count == -1 ) {
		
		int toss;
		for (toss = 0 ; toss  < number_of_tosses ; toss++) {
			double x = (double) rand()/RAND_MAX*2.0-1.0;
			double y = (double) rand() / RAND_MAX*2.0-1.0;
			double distance_squared = x*x + y*y;
			if(distance_squared <= 1){
				number_in_circle++;
			}

		}
				
		pi_ = 4 * number_in_circle / (((double) number_of_tosses)); 	
		printf("pi : %lf", pi_);

		return 0;	
	}

	thread_handles = (pthread_t*) malloc( thread_count  * sizeof(pthread_t) ); 
	
	for( i = 0 ; i < thread_count ; i++ ){
		pthread_create(&thread_handles[i], NULL, pi_estimate, (void*) thread);
	}


	for( i = 0 ; i < thread_count ; i++) {
		pthread_join(thread_handles[i], NULL);
	}

	free(thread_handles);
	
	pi_ = 4 * number_in_circle / (((double) number_of_tosses)*thread_count); 	
	
	printf("pi : %lf", pi_);
	return 0;

}

void * pi_estimate(void * rank)
{
	unsigned int mystate ;
	int toss;
	
	mystate = time(NULL) ^ getpid() ^ pthread_self();


	for (toss = 0 ; toss  < number_of_tosses ; toss++) {
		double x = (double) rand_r(&mystate)/RAND_MAX*2.0-1.0;
		double y = (double) rand_r(&mystate) / RAND_MAX*2.0-1.0;
		double distance_squared = x*x + y*y;

		if( distance_squared <= 1 ){
			pthread_mutex_lock( &mutex );
			number_in_circle++;
			pthread_mutex_unlock( &mutex );
		}

	}


	

}

