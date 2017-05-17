#include "stdafx.h"
#include <iostream>
#include <Windows.h>

using namespace std;
double a, b=0, c=0;
bool flag = false , flag2 = false;

void f1(void*){
	while (1){
		cout << "T1 : ";
		cin >> a;
		flag = true;
		while (!flag2)
			Sleep(50);
		flag = false;
	}
}

void f2(void *){
	while (true){
		while (flag == false) Sleep(50);
		cout << "T2 : ";
		b++;
		c += a;
		cout << c / b << endl;
		flag = false;
	}
}

int main()
{
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)f1, 0, 0, 0);
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)f2, 0, 0, 0);

	while (1){}
	return 0;
}

