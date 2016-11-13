#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>

using namespace std;

#define BUFSIZE 512

int main()
{
	HANDLE hp;
	TCHAR chReadBuf[BUFSIZE];
	DWORD Dwrite;


	hp = CreateFile(TEXT("\\\\.\\pipe\\Pipe"),
		GENERIC_READ | GENERIC_WRITE,
		0,
		NULL,
		OPEN_EXISTING,
		0,
		NULL);
	if (hp != INVALID_HANDLE_VALUE)
	{
		while (hp != INVALID_HANDLE_VALUE){
			char a[10];
			cout << "enter number : " << endl;
			cin >> a;
			WriteFile(hp,
				a,
				strlen(a),   // = length of string + terminating '\0' !!!
				&
				
				
				,
				NULL);
		}

		CloseHandle(hp);
	}
	else
	{
		cout << "INVALID_HANDLE_VALUE";
	}


	_getch();
	return 0;
}

