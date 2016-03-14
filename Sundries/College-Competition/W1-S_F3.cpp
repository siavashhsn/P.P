// W1-S_F3.cpp
// kargahe mehdi

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int a, b, c;
	int count = 0;
	cin >> a >> b >> c;
	if (a + b <= n)
		count++;
	if (a + c <= n && a + b <= n)
		count++;
	if (c + b <= n)
		count++;
	if (a + c <= n && c + b <= n)
		count++;
	if (a + c <= n && c + b <= n && a + b <= n)
		count++;
	cout << count;
	return 0;
}