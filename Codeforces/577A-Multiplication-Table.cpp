#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a;
	int b;
	cin >> a >> b;
	int k=0;
	for (int i=1; i<=a; i++){
		if(b%i == 0 && b/i <= a)
			k++;
	}
	cout << k;
	return 0;

}
