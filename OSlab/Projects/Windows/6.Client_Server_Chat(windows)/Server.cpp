#include "stdafx.h"
#include <iostream>
#include <Windows.h>
using namespace std;

#pragma comment(lib, "Ws2_32.lib")

#define REQ_WINSOCK_VER 2
#define MAX_BUFF		512
SOCKET ClientSocket;


char sendbuff[MAX_BUFF];
char recvbuff[MAX_BUFF];


//send function to send massage to the client
void _send(void*){
	while (1){
		memset(sendbuff, 0, MAX_BUFF);
		cin.ignore();
		if (cin.getline(sendbuff, MAX_BUFF)){
			cout << sendbuff << endl;
			if (send(ClientSocket, sendbuff, MAX_BUFF, 0) == SOCKET_ERROR)
				cout << "Server probably down. " << endl;
			else
				cout << "massage sended" << endl;
		}
	}
}

//recv function to recv massage from the client
void _recv(void*){
	while (1){
		memset(recvbuff, 0, MAX_BUFF);
		int BytesRec = recv(ClientSocket, recvbuff, MAX_BUFF, 0);
		if (BytesRec > 0)
		{
			cout << "Client : " << recvbuff << endl;
		}
	}
}


int main()
{
	WSADATA wsaData;
	SOCKET hSocket;
	sockaddr_in sockAddr;
	sockaddr_in ClientAddr;

	hSocket = INVALID_SOCKET;
	ClientSocket = INVALID_SOCKET;

	// Check required version
	WSAStartup(MAKEWORD(REQ_WINSOCK_VER, 0), &wsaData);


	//creating socket
	if ((hSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET)		// Create socket
	{
		cout << "Could not create socket." << endl;
		return 0;
	}

	//initializing the sockadd
	sockAddr.sin_family = AF_INET;
	sockAddr.sin_port = htons(4444);
	// Listen on all available ip's
	sockAddr.sin_addr.S_un.S_addr = INADDR_ANY;

	//binding to the socket with specified ip and port
	if (bind(hSocket, (sockaddr*)(&sockAddr), sizeof(sockAddr)) != 0)
		cout << "error in binding ....." << endl;
	else
		cout << ".............. binded .............." << endl;

	//listening to the porst and ip address
	if (listen(hSocket, 10) != 0)
		cout << "Could not put the socket in listening mode." << endl;
	else
		cout << ".............. listining .............." << endl;


	cout << "Server settings: " << endl
		<< "IP: 127.0.0.1" << endl;

	int SizeAddr = sizeof(ClientAddr);

	//wait for client to connect to the server then continue
	cout << "Waiting for clients... ";
	ClientSocket = accept(hSocket, (sockaddr*)(&ClientAddr), &SizeAddr);
	cout << "client found!" << endl;
	cout << "You are binded to the client. " << endl
		<< endl << "-----------------------------------------" << endl;

	//creating thread to send and recive massage to/from client
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)_send, 0, 0, 0);
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)_recv, 0, 0, 0);

	while (1);
	return 0;
}
