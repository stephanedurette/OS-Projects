#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

pthread_t subjectThread;

static int subjectData = -1;
static int numberConsumed = 0xF;	//each new subjectData can only be consumed once per thread, represented by a 4 bit number, 1 bit per observer thread

sem_t mutex;

pthread_t observerThreads[4];
int observerDivisors[4] = {3, 5, 7, 25};

//Run forever, update the global "subjectData" number when the random number is divisible by 5
void *subjectFunction(void *arg){
	srand(time(NULL));
	
	while(1){
		int randNum = rand() % 1000 + 1; // 1 <= randNum <= 1000
		if (randNum % 5 != 0) continue;
		
		sem_wait(&mutex);
		
		subjectData = randNum;
		numberConsumed = 0;		//this new number has not been consumed
		
		sem_post(&mutex);
		
	}
	return NULL;
}

//Read the subjectData, if its divisible by the assigned divisor output the result. Do this 3 times then terminate 
void *observerFunction(void *arg){
	int divisor = *(int*)arg;
	int observerID = divisor == 3 ? 1 : divisor == 5 ? 2 : divisor == 7 ? 3 : divisor == 25 ? 4 : -1; //observer number for clean output string
	int observerBit = 1 << (observerID - 1);	//observer bit of this thread, 1-2-4-8 depending on divisor 3-5-7-25
	
	int count = 0;
	while(count < 3){
		if (subjectData % divisor == 0 && !(numberConsumed & observerBit)){	//if the number has not been consumed by this thread and it's a valid output
			
			sem_wait(&mutex);
			
			printf("Observer: %d\tNumber: %d\tDivisor: %d\tProduct: %d\n", observerID, subjectData, divisor, subjectData / divisor);
			numberConsumed |= observerBit;		//the new number has been consumed by this thread
			
			sem_post(&mutex);
			
			count++;
		}
	}
	return NULL;
}

int main(int argc, char **argv){
	//init semaphore
	sem_init(&mutex, 0, 1);
	
	//Create subject thread -> subjectFunction
	if(pthread_create(&subjectThread, NULL, &subjectFunction, NULL) != 0){
		printf("subject thread creation failed\n");
		return 2;
	}
	
	//Create observer threads -> observerFunction using the divisors as arguments
	for(int i = 0; i < 4; i++){
		if(pthread_create(&(observerThreads[i]), NULL, &observerFunction, &observerDivisors[i]) != 0){
			printf("observer thread creation failed\n");
			return 2;
		}
	}
	
	//Wait until all observer threads have terminated
	for (int i = 0; i < 4; i++) pthread_join(observerThreads[i], NULL);
	
	//Terminate subject thread
	if (pthread_cancel(subjectThread) != 0){
		printf("failed to cancel the subject thread\n");
		return 3;
	}
	
	return 0;
}



