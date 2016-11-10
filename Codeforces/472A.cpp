#include <iostream>
using namespace std;

int main()
{
	int a; cin >> a;
	int b = a/2;
	if(a%2!=0)cout << 9 << " " << a-9;
	else cout << 4 << " " << a-4;
	return 0;
}