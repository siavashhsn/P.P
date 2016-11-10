#include <iostream>

using namespace std;

int main()
{
	int a , b;
	cin >> a >> b;
	int c = min(a, b);
	int d = max(a, b);
	int e = d - c;
	cout << c << " ";
	if(e%2==0)
		cout << e/2;
	else
		cout << (e-1)/2;
	//cout << c << " " << (e/2 ? e%2==0 : (e-1)/2);

	return 0;
}