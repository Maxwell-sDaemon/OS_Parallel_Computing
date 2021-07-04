int counter; /* Initialize to 0 */
int thread count;
pthread mutex t barrier mutex;

void∗ Thread work(void * rank) {
	//. . .
	/* Barrier */
	pthread mutex lock(&barrier mutex);
	counter++; // each barrier need one counter and this cpunter never touched after busy waiting(update issue)
	pthread mutex unlock(&barrier mutex);
	while (counter < thread count);
	//. . .
}
