#include "stdafx.h"
#include <windows.h> 
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>


using namespace std;
#define BUFSIZE 512

int main()
{
	HANDLE hp;
	CHAR ReadBuf[BUFSIZE];
	DWORD Read;

	
	hp = CreateNamedPipe(TEXT("\\\\.\\pipe\\Pipe"),
		PIPE_ACCESS_DUPLEX | PIPE_TYPE_BYTE | PIPE_READMODE_BYTE,   // FILE_FLAG_FIRST_PIPE_INSTANCE is not needed but forces CreateNamedPipe(..) to fail if the pipe already exists...
		PIPE_WAIT,
		1,
		1024 * 16,
		1024 * 16,
		NMPWAIT_USE_DEFAULT_WAIT,
		NULL);

	int avg = 0, n = 0;

	while (hp != INVALID_HANDLE_VALUE)
	{
		if (ConnectNamedPipe(hp, NULL) != FALSE)   // wait for someone to connect to the pipe
		{
			while (ReadFile(hp, ReadBuf, sizeof(ReadBuf) - 1, &Read, NULL) != FALSE)
			{
				int i = 0, j=0;
				/* add terminating zero */
				ReadBuf[Read] = '\0';
				while (ReadBuf[i]){
					j = j * 10 + (ReadBuf[i] - 48);
					i++;
				}

				avg += j;
				n++;
				cout << (double)avg / n << endl;
			}
		}

		DisconnectNamedPipe(hp);
	}
	

	_getch();

	return 0;
}

