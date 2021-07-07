/*
 * problem desrcription : as given code below convert mechanism that odd ranks  thread are sender , even are receiver.
 *  advanced version : take odd number of thread and sende odd ones send message even ones and of it because of thread number odd this mechanism make evens send odds and of course first is send message from last.
 * code:
 * 
 * while(1)
 * {
 * 	pthread_mutex_lock(&mutex);
 * 	if( my_rank == consumer ) {
 *		if( message_available ) {
 *			printf message;
 *			pthread_mutex_unlock(&mutex);
 *			break;
 *		}
 * 	} else {
 * 		create message
 * 		message_available = 1;
 * 		pthread_mutex_unlock(&mutex);
 * 		break;
 * 	}
 * 	pthread_mutex_unlock(&mutex);
 * }
 *
 * *
 */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define CONSUMER 1
#define PRODUCER 2
#define MSG_SZ 50

char * message;
int message_available = 0;
void * communicate_all_odds_send_even( void * rank );
pthread_mutex_t mutex;
int thread_count ;
int receiver;

int main(int argc , char* argv[])
{

	long thread;
	int i, ret; // hold whether initilalization true or not
	int max_threads;

	pthread_t* thread_handles;
	thread_count = strtol(argv[1], NULL , 10);
	thread_handles = malloc( sizeof(pthread_t) * thread_count );
	message = (char*) malloc ( MSG_SZ * sizeof(char));

	for ( thread = 0 ; thread < thread_count; thread++ )
		pthread_create(&thread_handles[thread], NULL, communicate_all_odds_send_even, (void*) thread);


	for( thread = 0 ; thread < thread_count ; thread++)
		pthread_join(thread_handles[thread], NULL);

	free(thread_handles);

	return 0;
}	

void * communicate_with_order( void * rank ) {
	
	long my_rank = (long) rank;

	while(1)
	{
		pthread_mutex_lock(&mutex);
	}

}

void * communicate_all_odds_send_even( void *rank ) {

	long my_rank = (long) rank;

	while(1) 	
 	{
		pthread_mutex_lock(&mutex);
	 	if( my_rank % 2 == CONSUMER ) {
			if( message_available ) {
				printf("%s to all.I am %ld btw\n", message, my_rank);
				pthread_mutex_unlock(&mutex);
				break;
			}
	 	} else {
	 		sprintf(message, "hello from %ld.", my_rank );
	 		message_available = 1;
 	 		pthread_mutex_unlock(&mutex);
 	 		break;
		}
 	 	pthread_mutex_unlock(&mutex);
     	}
 
	return 0;

}
