/*
 *	producer-consumer synhronization 
 *	thread can t do anything when other thread fiisihed its job.
 *	how to make thread orderize??
 * */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MSG_MAX 100

int thread_count;
pthread_mutex_t * mutex;
void* Send_msg(void* rank);
char** messages;

int main(int argc, char* argv[]) {
	long thread;
	pthread_t* thread_handles;
        thread_count = strtol(argv[1], NULL, 10);
    	
        thread_handles = (pthread_t*) malloc ( thread_count * sizeof( pthread_t ));
	messages = (char**) malloc ( thread_count * sizeof(char*));
	mutex = (pthread_mutex_t*) malloc( thread_count * sizeof(pthread_mutex_t));
	
	for (int i = 0; i < thread_count; i++)
	        pthread_mutex_init(&mutex[i], NULL);

	for ( thread = 0 ; thread < thread_count; thread++ ) {
		pthread_create(&thread_handles[thread], NULL, Send_msg, (void*) thread);	 }
       	printf("in the main\n");

	for ( thread = 0 ; thread < thread_count ; thread++) {
	pthread_join(thread_handles[thread], NULL);											        }

	free(thread_handles);


        return 0;

}

/* messages has type char∗∗. It’s allocated in main.*/
/* Each entry is set to NULL in main.
 * first thread is not locked  
*/
void* Send_msg(void* rank) {

	long my_rank = (long) rank;
	long dest = (my_rank + 1) % thread_count;
	long source = (my_rank + thread_count - 1) % thread_count;
	char* my_msg = malloc(MSG_MAX*sizeof(char));
	sprintf(my_msg, "Hello to %ld from %ld", dest, my_rank);
	
	pthread_mutex_lock(&mutex[dest]);

	messages[dest] = my_msg;

	pthread_mutex_unlock(&mutex[dest]);

	pthread_mutex_lock(&mutex[my_rank]);
	printf("Thread %ld > %s\n", my_rank, messages[my_rank]);
	
	// we need unlock but other can be first unlock :: coding issue 
	return NULL;
}
