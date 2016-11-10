#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(0);
	int n, k, m=0, i; cin >> n;
	for (i = 0; i < n; ++i)
	{
		cin >> k;
		if(k-m>15) {
			cout << m+15;
			return 0;
		}
		else
			m=k;
	}
	if(k+15 >= 90) cout << 90;
	else cout << k+15;
	return 0;
}