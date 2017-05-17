#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
using namespace std;

//To define a semaphore object, use : sem_t sem_name;
sem_t sem;      

double a, b=0, c=0;
// bool flag = false , flag2 = false;

//get function to get number from thread one
void *get_num(void *) {
    while (true){
		//sem_wait to pause the threads
        sem_wait(&sem);
		cout << "T1 : ";
		cin >> a;
		//sem_post to continue the threads
        sem_post(&sem);
    }
}

//print function to print AVG 
void *printAVG(void *){
    while (true){
		//sem_wait to pause the threads
		sem_wait(&sem);
		cout << "T2 : ";
		b++;
		c += a;
		cout << c / b << endl;
		//sem_post to continue the threads
		sem_post(&sem);
    }
}

int main ()
{
	//initial the semaphore
    sem_init(&sem, 0, 1);

	//create threads
    pthread_t t1, t2;
    pthread_create(&t1, NULL, get_num, NULL);
    pthread_create(&t2, NULL, printAVG, NULL);


 	pthread_join(t1, NULL);
    pthread_join(t2, NULL);

	//destroy the semaphore
    sem_destroy(&sem);
    
    return 0;
}
