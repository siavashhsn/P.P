#include <iostream>
using namespace std;

int main()
{
long long int a, b;
cin >> a >> b;
if(a%2 == 0)
{
	long long int aa = a/2;
	if(aa >= b)
		cout << b*2-1;
	else
		cout << b-(a-b);
	return 0;
}
else
{
	long long int aa=a/2+1;
	if(aa >= b)
		cout << b*2-1;
	else
		cout << b - (a-b+1);
       	return 0;
}

return 0;
}
