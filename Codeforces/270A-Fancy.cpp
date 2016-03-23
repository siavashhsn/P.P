#include <iostream>
using namespace std;

int main()
{
	int a, b;
	cin >> a;

	for(int i = 0; i < a; i++)
	{
		cin >> b;
		if(360%( 180 - b ) == 0)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
return 0;
}
