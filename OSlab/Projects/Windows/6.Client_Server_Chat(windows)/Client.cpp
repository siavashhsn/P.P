#include "stdafx.h"
#include <iostream>
#include <windows.h>

using namespace std;

#pragma comment(lib, "Ws2_32.lib")

#define REQ_WINSOCK_VER	2
#define PORT			4444
#define MAX_BUFF		512

char sendbuff[MAX_BUFF];
char recvbuff[MAX_BUFF];


SOCKET hSocket;

//send function to send massage to the server
void _send(void*){
	while (1){
		memset(sendbuff, 0, MAX_BUFF);
		if (cin.getline(sendbuff, MAX_BUFF)){
			if (send(hSocket, sendbuff, MAX_BUFF, 0) == SOCKET_ERROR)
				cout << "Server probably down. " << endl;
		}
	}
}

//recv function to recive massage from the server
void _recv(void*){
	while (1){
		memset(recvbuff, 0, MAX_BUFF);
		int bc = recv(hSocket, recvbuff, MAX_BUFF, 0);
		if (bc > 0){
			cout << "server : " << recvbuff << endl;
		}
	}
}

int main()
{
	WSADATA wsaData;
	sockaddr_in sockAddr;
	hSocket = INVALID_SOCKET;

	// Check required version
	WSAStartup(MAKEWORD(REQ_WINSOCK_VER, 0), &wsaData);

	//initializing the sockadd
	sockAddr.sin_family = AF_INET;
	sockAddr.sin_port = htons(4444);
	sockAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");  // Use TCP/IP protocol

	cout << "Search server... " << endl
		<< "IP ADRESS: 127.0.0.1" << endl;

	//creating socket
	if ((hSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET)
		cout << "unable to create the socket!!! " << endl;

	cout << "Attempting to connect to " << inet_ntoa(sockAddr.sin_addr) << endl;

	//connect to the socket
	if (connect(hSocket, (sockaddr*)(&sockAddr), sizeof(sockAddr)) != 0)		// Connect to the server
		cout << "unable to connect to the server!!! " << endl;
	else
		cout << "You are connected to the server. " << endl
		<< endl << "-----------------------------------------" << endl;

	//creating thread to send and recive massage to/from server
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)_send, 0, 0, 0);
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)_recv, 0, 0, 0);

	while (1);
	return 0;
}