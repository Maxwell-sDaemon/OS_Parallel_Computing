#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int n = 100000;
int thread_count;
double sum = 0.f;
void* Thread_sum(void* rank);
int flag=0; // start with priority 0 thread
pthread_mutex_t mutex;

int main(int argc, char* argv[]) {
	long thread;
	pthread_t* thread_handles;
        thread_count = strtol(argv[1], NULL, 10);
        thread_count = strtol(argv[1], NULL, 10);
        thread_handles = (pthread_t*) malloc ( thread_count * sizeof( pthread_t ));

	for ( thread = 0 ; thread < thread_count; thread++ ) {
		pthread_create(&thread_handles[thread], NULL, Thread_sum, (void*) thread);									        }
       	printf("in the main\n");

	for ( thread = 0 ; thread < thread_count ; thread++) {
	pthread_join(thread_handles[thread], NULL);											        }

	free(thread_handles);
	printf("%f\n", 4.f * sum);

        return 0;

}

void* Thread_sum(void* rank) {

	long my_rank = (long) rank;
        double factor;
        long long i;
        long long my_n = n/thread_count;
        long long my_first_i = my_n * my_rank;
        long long my_last_i = my_first_i + my_n;
        double m_sum = 0.f;

	if (my_first_i % 2 == 0) /* my_first_i_is_even */
        factor = 1.0;
        else /* my first i is odd */
        factor = -1.0;

        for (i = my_first_i; i < my_last_i; i++, factor = -factor) {
        	m_sum += factor / ( 2 * i + 1 );
	}
	
	pthread_mutex_lock(&mutex);
	sum+=m_sum;// critical sectition
	pthread_mutex_unlock(&mutex);

        return NULL;
}
