// W1-R_F2.cpp
// donatelo va chahe marg

//#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int h, a;
	cin >> h >> a;
	int cmax;
	int cmin;
	int t = h - a;
	if (a != h)
	{
		if (t != 1)
		{
			if (t == 2 || t == 3)
				cmin = cmax = 1;
			else
			{
				cmax = t / 2;
				if (t % 3 == 0)
					cmin = t / 3;
				else
					cmin = t / 3 + 1;
			}
		}
		else
		{
			cout << -1;
			return 0;
		}
	}
	cout << cmin << " " << cmax;
	return 0;
}

