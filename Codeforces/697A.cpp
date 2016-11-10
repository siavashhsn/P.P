#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
	ll t, x, s;
	cin >> t >> s >> x;

	if(x<t||(x>t&&x<s))
		cout << "NO";
	else if(x==t)
		cout << "YES";
	else if((x-t) != 0 && (x-t-1)!= 0 && ((x-t)%s == 0 || (x-t-1)%s == 0))
		cout << "YES";
	else
		cout << "NO";

	return 0;
}