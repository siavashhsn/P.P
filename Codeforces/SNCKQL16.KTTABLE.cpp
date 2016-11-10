#include <bits/stdc++.h>
using namespace std;

// #define f(i, k, n, c)   for(decltype(k+n) i=k; i<n; i c)
// #define fr(i, k, n, c)  for(decltype(k+n) i=k; i>n; i c)
// #define ff(i, n)        for(decltype(n)   i=0; i<n; i++)
// typedef long long ll;
// typedef pair<ll, ll> pp;



int main()
{
	// std::ios::sync_with_stdio(false);
	long long t, n, p, c=0;
	vector<long long> vv;
	cin >> t;
	for(long long i=0; i<t; i++){
		vector<pair<long long, long long> > v;
		v.push_back(make_pair(0,0));
		cin >> n;
		for(long long l=1; l<n+1; l++){
			cin >> p;
			v.push_back(make_pair(p,0));
		}
		for(long long l=1; l<n+1; l++){
			cin >> p;
			v[l].second=p;
		}

		c=0;
		for(long long l=1; l<n+1; l++){
			long long b = v[l].first-v[l-1].first;
			if(b >= v[l].second)
				c++;
		}
		vv.push_back(c);
	}
	for(long long i=0; i<vv.size(); i++) {
		cout << vv[i] << endl;
	}

	return 0;
}