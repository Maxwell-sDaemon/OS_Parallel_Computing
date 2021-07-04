#include <stdio.h>
#include <stdlib.h>
#include <semaphores.h>

int counter; /* initialize to zero */
sem_t count_sem; /* initialize to one */
sem_t barrier_sem; /* initialize to zero */

void * Thread_work(void* rank) {

	int j;
	/* Barrier */
	sem_wait(&count_sem); // initially count_sem unlock thread pass. if count sem locked all thread wait, after reach sem_wait .

	if(counter == thread_count-){
		counter = 0;
		sem_post(&count_sem);
		for ( j = 0 ; j < thread_count - 1 ; j++ )
			sem_post(&barrier_sem);
	} else {
		counter++;
		sem_post(&count_sem);
		sem_wait(&barrier_sem);// thread stop until barrier_sem unlock
	}

}


