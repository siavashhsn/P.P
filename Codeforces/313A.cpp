#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
	ll a;
	cin >> a;
	if(a <= -10){
		int b = -(a%10);
		int c = -(a%100);
		if(c >= 10)
			c/=10;
		else
			c=0;

		if(c>b)
		{
			a/=100;
			a*=10;
			a-=b;
		}
		else
			a/=10;
	}
	cout << a;
	return 0;
}