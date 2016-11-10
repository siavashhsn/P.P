#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cmath>
using namespace std;

#define f(i, k, n, c) for(decltype(k + n) i = k; i < n; i c)
typedef long long LL;

int main()
{
	LL a, b, c;
	cin >> a >> b >> c;
	
	if(a<b && c<=0) {
		cout << "NO";
		return 0;
	}
	if(a>b && c>=0) {
		cout << "NO";
		return 0;
	}
	if(a==b) {
		cout << "YES";
		return 0;
	}

	if((a<b && c>0)||(a>b && c<0)) {
		if(abs(a-b)%abs(c)==0){
			cout << "YES";
		}
		else
			cout << "NO";
		return 0;
	}
	return 0;
}