#include <iostream>
using namespace std;

int main()
{
	int a;cin >> a;
	int b=0,j;
	int sum=0;
	//if(a==1){cout << 1; return 0;}
	for(j=1; ; j++){
		b+=j;
		sum+=b;
		if(sum>=a){
			if(sum==a)
				cout<<j;
			else
				cout << j-1;
			break;
		}
	}
	return 0;
}