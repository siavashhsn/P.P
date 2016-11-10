#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef long long ll;

int main()
{
	ll n, k, m;
	cin >> n >> k;
	vector<pair<ll, ll> > v,vv;
	for (ll i = 0; i < n; ++i) {
		cin >> m;
		v.push_back(make_pair(m, 0));
	}
	vector<pair<ll, ll> > d;
	ll min=10000;
	for (ll i = 0; i < n; ++i) {
		cin >> m;
		ll s = m/v[i].first;	
		v[i].second = m%v[i].first;
		d.push_back(make_pair(s,v[i].second));
	}

	ll ind=0;
	while(k!=0) {
		for (ll i = 0; i < n; ++i)
		{
			if(d[i].first < min) {
				min = d[i].first;
				ind = i;
			}
		}
		d[ind].second++;
		k--;
		if(d[ind].second%v[ind].first==0)
		{
			d[ind].first++;
			d[ind].second=0;
		}
		min = 10000;
	}

	min = 10000;	
	for (ll i = 0; i < n; ++i)
	{
		if(d[i].first < min) {
				min = d[i].first;
				ind = i;
			}
	}
	cout << min;
	return 0;
}