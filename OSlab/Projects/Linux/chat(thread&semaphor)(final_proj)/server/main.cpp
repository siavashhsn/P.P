//#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <netinet/in.h>
#include <resolv.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include <iostream>
#include <semaphore.h>

using namespace std;

//sem_t sem;

#define DEFAULT_PORT	  	1101
#define DEFAULT_BUFSIZE		1024

char sendbuff[DEFAULT_BUFSIZE];
char recvbuff[DEFAULT_BUFSIZE];
char a[DEFAULT_BUFSIZE];

int hsock;
int csock;


void* send(void*);
void* recv(void*);


int main()
{
//    sem_init(&sem, 0, 1);

    struct sockaddr_in my_addr;
    socklen_t addr_size = 0;
    sockaddr_in sadr;

    hsock = socket(AF_INET, SOCK_STREAM, 0);
    if(hsock == -1){
        printf("Error initializing socket %d\n", errno);
        return 0;
    }

    my_addr.sin_family = AF_INET ;
    my_addr.sin_port = htons(DEFAULT_PORT);
    my_addr.sin_addr.s_addr = INADDR_ANY ;

    if( bind( hsock, (sockaddr*)&my_addr, sizeof(my_addr)) == -1 ){
        fprintf(stderr,"Error binding to socket, make sure nothing else is listening on this port %d\n",errno);
        return 0;
    }
    if(listen( hsock, 10) == -1 ){
        fprintf(stderr, "Error listening %d\n",errno);
        return 0;
    }

    addr_size = sizeof(sockaddr_in);
    csock = accept( hsock, (sockaddr*)&sadr, &addr_size);

    memset(recvbuff, 0, DEFAULT_BUFSIZE);
    strcpy(sendbuff, "initial connection is set...");
    send(csock, sendbuff, DEFAULT_BUFSIZE,0);

    memset(sendbuff, 0, DEFAULT_BUFSIZE);
    memset(recvbuff, 0, DEFAULT_BUFSIZE);

    pthread_t t1=0, t2=0;
    pthread_create(&t1, 0, &recv, NULL);
    pthread_create(&t2, 0, &send, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    close(hsock);
    return 0;
}

void* recv(void*){
    while(1){
        memset(recvbuff, 0,DEFAULT_BUFSIZE);
        recv(csock, recvbuff, DEFAULT_BUFSIZE, 0);
        if(recvbuff[0] != 0){
            printf("Received text : %s \n", recvbuff);
        }
    }
}

void* send(void*){
    while(1){
        memset(sendbuff, 0,DEFAULT_BUFSIZE);
        cin.ignore();
        memset(a, 0, DEFAULT_BUFSIZE);
        if(cin.getline(sendbuff, DEFAULT_BUFSIZE)){
            a[0] = 'a';
            strcat(a, sendbuff);
            strcpy(sendbuff, a);
            if(send(csock, sendbuff, DEFAULT_BUFSIZE,0) == -1){
                fprintf(stderr, "Error sending data %d\n", errno);
            }
        }
    }
}
