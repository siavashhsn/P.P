#include <iostream>
using namespace std;

int main()
{
	int a;
	cin >> a;
	int b = 0;
	if(a<=5)
		cout << 1;
	else
		cout << (a%5!=0 ? a/5 + 1 : a/5);
	return 0;
}