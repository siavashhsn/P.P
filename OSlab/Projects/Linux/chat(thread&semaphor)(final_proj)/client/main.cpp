#include <netinet/in.h>
#include <sys/socket.h>
#include <semaphore.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <resolv.h>
#include <unistd.h>
#include <iostream>
#include <errno.h>
#include <stdio.h>
#include <fstream>
#include <fcntl.h>

using namespace std;

sem_t sem;

#define DEFAULT_PORT	  	1101
#define DEFAULT_HOST      	"127.0.0.1"
#define DEFAULT_BUFSIZE		1024

char sendbuff[DEFAULT_BUFSIZE];
char recvbuff[DEFAULT_BUFSIZE];
char a[DEFAULT_BUFSIZE];

int csock;

int filesize(char*);
int recv_file();
int send_file(char [DEFAULT_BUFSIZE]);
void* send(void*);
void* recv(void*);


int main()
{
    sem_init(&sem, 0, 1);

    struct sockaddr_in my_addr;
    int err;

    csock = socket(AF_INET, SOCK_STREAM, 0);
    if(csock == -1){
        printf("Error initializing socket %d\n",errno);
        return 0;
    }

    my_addr.sin_family = AF_INET ;
    my_addr.sin_port = htons(DEFAULT_PORT);
    my_addr.sin_addr.s_addr = inet_addr(DEFAULT_HOST);

    if( connect( csock, (struct sockaddr*)&my_addr, sizeof(my_addr)) == -1 ){
        if((err = errno) != EINPROGRESS){
            fprintf(stderr, "Error connecting socket %d\n", errno);
            return 0;
        }
    }
    else
    {
        strcpy(sendbuff, "initial connection is set...");
        send(csock, sendbuff, DEFAULT_BUFSIZE,0);
    }

    memset(sendbuff, 0, DEFAULT_BUFSIZE);
    memset(recvbuff, 0, DEFAULT_BUFSIZE);

    pthread_t t1=0, t2=0;
    pthread_create(&t1, 0, &recv, NULL);
    pthread_create(&t2, 0, &send, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    close(csock);
    return 0;
}

void* recv(void*){
    while(1){
        memset(recvbuff, '\0', DEFAULT_BUFSIZE);
        recv(csock, recvbuff, DEFAULT_BUFSIZE, 0);
        if(recvbuff[0] != '\0'){
            if(recvbuff[0] == ':')
            {
                memset(recvbuff, '\0', DEFAULT_BUFSIZE);
                recv(csock, recvbuff, DEFAULT_BUFSIZE, 0);
                cout << "reciving " << recvbuff  << " ...... " << endl;
                int aa = recv_file();
                if(aa != -1)
                    continue;
            }
            printf("Received text : %s \n", recvbuff);
        }
    }
}


void* send(void*){
    while(1){
        memset(sendbuff, '\0',DEFAULT_BUFSIZE);
        if(cin.getline(sendbuff, DEFAULT_BUFSIZE)){
            if(sendbuff[0] == ':')
            {
                int a = send_file(sendbuff);
                if(a != -1)
                    continue;
            }
            if(send(csock, sendbuff, DEFAULT_BUFSIZE,0) == -1){
                fprintf(stderr, "Error sending data %d\n", errno);
            }
        }
    }
}

int recv_file(){
    sem_wait(&sem);

    char file_name[DEFAULT_BUFSIZE];
    memset(file_name, '\0', DEFAULT_BUFSIZE);
    strcpy(file_name, recvbuff);

    int f;

    ssize_t rcvd_bytes, rcvd_file_size;

    int recv_count;
    memset(recvbuff, 0, DEFAULT_BUFSIZE);

    recv_count = 0;
    rcvd_file_size = 0;

    if ( (f = open(file_name, O_WRONLY|O_CREAT, 0644)) < 0 ){
        perror("error creating file");
        return -1;
    }

    int received_int = 0;
    read(csock, &received_int, sizeof(received_int));

    while (1){
        if(rcvd_file_size == received_int)
            break;
        rcvd_bytes = recv(csock, recvbuff, DEFAULT_BUFSIZE, 0);
        if(rcvd_bytes > 0){
            recv_count++;
            rcvd_file_size += rcvd_bytes;
            if (write(f, recvbuff, rcvd_bytes) < 0 ){
                perror("error writing to file");
                return -1;
            }
            cout << "reciving : " << rcvd_file_size << endl;
            memset(recvbuff, 0, DEFAULT_BUFSIZE);
        }
    }
    close(f);
    cout << "Client Received: " << rcvd_file_size << " bytes " << endl;
    sem_post(&sem);
    return rcvd_file_size;
}

int send_file(char filename[DEFAULT_BUFSIZE]){
    sem_wait(&sem);

    string s = filename;
    s = s.substr(s.find(':') + 1);
    char* file_name;
    file_name = (char*)(s.c_str());
    cout << file_name << endl;

    int sent_count;
    ssize_t read_bytes, sent_bytes, sent_file_size;
    char *errmsg_notfound = (char*)("File not found\n");
    int f;

    sent_count = 0;
    sent_file_size = 0;

    if( (f = open(file_name, O_RDONLY)) < 0) {
        perror(file_name);
        if( (sent_bytes = send(csock, errmsg_notfound ,strlen(errmsg_notfound), 0)) < 0 ){
            perror("send error\n");
            return -1;
        }
    }
    else {
        char aa[1];
        aa[0] = ':';
        send(csock, aa, sizeof(':'), 0);

        sleep(1);

        char* bs = basename(file_name);
        cout << bs << endl;

        send(csock, bs, sizeof(basename(file_name)), 0);

        sleep(1);

        int a = filesize(file_name);
        cout << a << endl;
        uint32_t un = a;
        send(csock, &un, sizeof(a), 0);
        cout << "sending file : " << file_name << endl;

        memset(sendbuff, 0,DEFAULT_BUFSIZE);
        while( (read_bytes = read(f, sendbuff, DEFAULT_BUFSIZE)) > 0 ) {
            if( (sent_bytes = send(csock, sendbuff, read_bytes, 0)) < read_bytes ) {
                perror("send error");
                return -1;
            }
            sent_count++;
            sent_file_size += sent_bytes;
            memset(sendbuff, 0,DEFAULT_BUFSIZE);
        }
        close(f);
    }

    cout << "Done with this client. Sent " << sent_file_size << " bytes" << endl;
    sem_post(&sem);
    return sent_count;
}
int filesize(char *filename)
{
    ifstream file( filename, ios::binary | ios::ate);
    return file.tellg();
}


