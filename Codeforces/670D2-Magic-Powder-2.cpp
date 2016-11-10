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
	ll min=10000000000, min2=0;
	for (ll i = 0; i < n; ++i) {
		cin >> m;
		ll s = m/v[i].first;	
		v[i].second = m%v[i].first;
		d.push_back(make_pair(s,v[i].second));
	}

	ll ind=0, ind2=0;
	while(k!=0) {
		for (ll i = 0; i < n; ++i)
		{
			if(d[i].first <= min) {
				if(n>1)
					min2 = min;
				min = d[i].first;
				ind2 = ind;
				ind = i;
			}
		}
		ll f;
		if(min2-min != 0){
			if(n>1)
				f=min2-min;
			else
				f=min;
		}
		else
			f=1;
		if(f>=k){
			d[ind].second+=k;
			k=0;
		}
		else {
			d[ind].second+=f;
			k-=f;
		}
		ll g=d[ind].second/v[ind].first;
		if(g>=1)
		{
			d[ind].first+=g;
			d[ind].second+=d[ind].second%v[ind].first;
		}
		min = 10000000000;
		min2=0;
	}

	min = 10000000000;	
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