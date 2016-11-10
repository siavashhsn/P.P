#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main()
{
	ll n, k, m, t=0;
	vector<ll> v;
	cin >> n >> k;
	ll i;
	for(i=1; i<=n; i++) {
		cin >> m;
		v.push_back(m);
		t+=i;
		if(k<=t)
			break;
	}
	t = (i--) - t%k;
	cout << v[t-1];
	return 0;
}