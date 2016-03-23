#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b;
	int c, d;
	int count=0;
	cin >> a >> b;
	for (int i=0; i<a; i++){
		for(int j=0; j<b; j++){
			cin >> c >> d;
			if(c==1 || d==1)
				count++;
		}
	}
	cout << count;
return 0;
}
