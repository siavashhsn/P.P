#include <iostream>
using namespace std;

typedef long long int ll;
int main()
{
	ll n, count=0; cin >> n;
	count = (n/3)*2;
	if(n%3!=0) count++;
	cout << count;
	return 0;
}