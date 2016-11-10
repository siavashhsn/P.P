#include <map>
#include <vector>
#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(0);
	ll n, a;cin >> n;
	map<ll, ll> t;
	for(ll i=0; i<n; i++) {
		cin >> a;
		t[a]++;
	}
	
	ll m, b; cin >> m;
	vector<pair<ll, ll>> v;
	
	for(ll i=0; i<m; i++) {
		cin >> b;
		v.push_back(make_pair(b, 0));
	}
	pair<ll, ll> p=make_pair(0,0), q;
	ll k=0;
	for(ll i=0; i<m; i++) {
		cin >> b;
		v[i].second=b;
		q=pair<ll, ll>(t[v[i].first],t[v[i].second]);
	
		if(q > p)
		{
			k=i;
			p=q;
		}
	}
	cout << k+1;

	return 0;
}