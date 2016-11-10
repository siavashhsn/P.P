#include <bits/stdc++.h>
using namespace std;

#define ff(i, k, n, c)   for(decltype(k+n) i=k; i<n; i c)
#define fr(i, k, n, c)  for(decltype(k+n) i=k; i>n; i c)
#define f(i, n)        for(decltype(n)   i=0; i<n; i++)
typedef long long ll;
typedef pair<ll, ll> pp;



int main()
{
	// std::ios::sync_with_stdio(false);
	ll t, n, m;
	cin >> t;
	f(i, t){
		vector<pp> vv;
		cin >> n;
		f(j,n){
			cin >> m;
			fr(k, vv.size()-1, j-1, --){
				ll x=vv[k].second, y=vv[k].first;
				vv.push_back({y+m, min(x,m)});
			}
			vv.push_back({m, m});
		}
	}

	f(i, vv.size()){
		cout << "sum : " << vv[i].first << " min : " << vv[i].second << endl;
	}

	return 0;
}