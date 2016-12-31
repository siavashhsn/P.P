#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <semaphore.h>
#include <pthread.h>
#include <termios.h>
#include <string.h>
#include <stdlib.h>
#include <resolv.h>
#include <unistd.h>
#include <iostream>
#include <libgen.h>
#include <stdlib.h>
#include <cstring>
#include <fstream>
#include <errno.h>
#include <stdio.h>
#include <fcntl.h>
#include <string>

using namespace std;

sem_t sem;

#define DEFAULT_PORT	  	1101
#define DEFAULT_BUFSIZE		1024

char sendbuff[DEFAULT_BUFSIZE];
char recvbuff[DEFAULT_BUFSIZE];

int ssock;
int filesize(char*);
int recv_file();
int send_file(char [DEFAULT_BUFSIZE]);
void* send(void*);
void* recv(void*);



int main()
{
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag &= ~ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &t);

    sem_init(&sem, 0, 1);
    int hsock;

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
    ssock = accept( hsock, (sockaddr*)&sadr, &addr_size);

    memset(recvbuff, 0, DEFAULT_BUFSIZE);
    strcpy(sendbuff, "initial connection is set...");
    send(ssock, sendbuff, DEFAULT_BUFSIZE,0);

    memset(sendbuff, 0, DEFAULT_BUFSIZE);
    memset(recvbuff, 0, DEFAULT_BUFSIZE);

    pthread_t t1=0, t2=0;
    pthread_create(&t1, 0, &recv, NULL);
    pthread_create(&t2, 0, &send, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    close(hsock);
    close(ssock);
    return 0;
}

bool f = false;

void* recv(void*){
    while(1){
        memset(recvbuff, '\0', DEFAULT_BUFSIZE);
        recv(ssock, recvbuff, DEFAULT_BUFSIZE, 0);
        if(recvbuff[0] != '\0'){
            if(sendbuff[0] != '\0')
                sem_wait(&sem);
            f = true;
            if(recvbuff[0] == ':')
            {
                cout << "\r";
                memset(recvbuff, '\0', DEFAULT_BUFSIZE);
                recv(ssock, recvbuff, DEFAULT_BUFSIZE, 0);
                cout << "reciving " << recvbuff  << " ...... " << endl;
                int aa = recv_file();
                if(sendbuff[0] != '\0')
                    cout << sendbuff;
                if(aa != -1)
                    continue;
            }
            cout << "\rReceived text : " << recvbuff;
            if(sendbuff[0] != '\0'){
                cout << sendbuff;
                sem_post(&sem);
            }
            f = false;
        }
    }
}


void* send(void*){
    char input[1];
    memset(sendbuff, '\0',DEFAULT_BUFSIZE);
    memset(input, '\0', 1);
    while(1){
        do{
            if(f == false){
                input[0] = getchar();
                strcat(sendbuff, input);
            }
        }while(input[0] != '\n');

        if(sendbuff[0] == ':')
        {
            int a = send_file(sendbuff);
            if(a != -1)
                continue;
        }
        if(send(ssock, sendbuff, DEFAULT_BUFSIZE,0) == -1){
            fprintf(stderr, "Error sending data %d\n", errno);
        }
        memset(sendbuff, '\0',DEFAULT_BUFSIZE);
        memset(input, '\0', 1);
    }
}

int recv_file() {
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
    read(ssock, &received_int, sizeof(received_int));

    while (1){
        if(rcvd_file_size == received_int)
            break;
        rcvd_bytes = recv(ssock, recvbuff, DEFAULT_BUFSIZE, 0);
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
        if( (sent_bytes = send(ssock, errmsg_notfound ,strlen(errmsg_notfound), 0)) < 0 ){
            perror("send error\n");
            return -1;
        }
    }
    else {
        char aa[1];
        aa[0] = ':';
        send(ssock, aa, sizeof(':'), 0);

        sleep(1);

        char* bs = basename(file_name);
        cout << bs << endl;

        send(ssock, bs, sizeof(basename(file_name)), 0);

        sleep(1);

        int a = filesize(file_name);
        cout << a << endl;
        uint32_t un = a;
        send(ssock, &un, sizeof(a), 0);
        cout << "sending file : " << file_name << endl;

        memset(sendbuff, 0,DEFAULT_BUFSIZE);
        while( (read_bytes = read(f, sendbuff, DEFAULT_BUFSIZE)) > 0 ) {
            if( (sent_bytes = send(ssock, sendbuff, read_bytes, 0)) < read_bytes ) {
                perror("send error");
                return -1;
            }
            sent_count++;
            sent_file_size += sent_bytes;
            memset(sendbuff, 0,DEFAULT_BUFSIZE);
        }
        close(f);
    }

    cout << "Done with this client. Sent " << sent_file_size << " bytes in "<< sent_count << " send(s)" << endl << endl;
    sem_post(&sem);
    return sent_count;
}

int filesize(char* filename){
    ifstream file(filename, ios::binary | ios::ate);
    return file.tellg();
}
