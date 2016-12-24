#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>


using namespace std;
double a, b=0, c=0;
bool flag = false , flag2 = false;


//get function to get number from thread one
void *get_num(void *) {
    while (true){
        if(!flag){
            cout << "T1 : ";
            cin >> a;
            flag = true;
        }
    }
}

//print function to print AVG 
void *printAVG(void *){
    while (true){
        if(flag){
            cout << "T2 : ";
            b++;
            c += a;
            cout << c / b << endl;
            flag = false;
        }
    }
}

int main () {

   //create thread
   pthread_t t1, t2;
   pthread_create(&t1, NULL, get_num, NULL);
   pthread_create(&t2, NULL, printAVG, NULL);

   while(1);
   return 0;
}
