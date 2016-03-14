// W1-Q_F1.cpp
// fafal va hamed badaz emtehane riyazi

//#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int f, h, t;
	cin >> f >> h >> t;
	int a, b, c;
	cin >> a >> b >> c;
	int ans;
	if (c == 1)
		ans = a + b;
	else if (c== 2)
		ans = a - b;
	else if (c==3)
		ans = a * b;
	else if (c==4)
		ans = a / b;
	int fans, hans;
	cin >> fans >> hans;
	if (ans == fans)
	{
		f += t;
		h -= t;
	}
	else if (ans == hans)
	{
		f -= t;
		h += t;
	}
	cout << f << " " << h;

	return 0;
}

