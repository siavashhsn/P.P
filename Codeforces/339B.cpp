#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
	int n, m;
	cin >> n >> m;
	ll a, b=0, c=0;
	for(int i=1; i<=m; i++){
		cin >> a;
		if(c!=0){
			if(a!=c){
				if(a>c)
					b+=a-c;
				else
					b+=(n-c)+1+(a-1);
			}
		}
		else
			b+=a-1;
		c=a;
	}
	cout << b;
	return 0;
}
