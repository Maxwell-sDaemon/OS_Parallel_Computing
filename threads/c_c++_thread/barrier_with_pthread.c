#include <stdio.h>
#include <stdlib.h>
#include <pthread>

int counter = 0;
pthread mutex t mutex;
pthread cond t cond var;

void* Thread work(void* rank) {
	/∗ Barrier ∗/
	pthread mutex lock(&mutex);
	counter++;
	if (counter == thread count) {
		counter = 0;
		pthread cond broadcast(&cond var); // this unlock all thread
	} else {
		while (pthread cond wait(&cond var, &mutex) != 0); // this wait signal from pthread_cond_broadcast .. while because somewhere of the of the code or some event in code maybe cause thread unlock != is check it.
	}
	pthread mutex unlock(&mutex);
	// all thread continue here

}

int main()
{

	//int pthread cond init(pthread cond t∗, const pthread condattr t∗
	
	
	//int pthread cond destroy(pthread cond t*);
		

	return ;
}

