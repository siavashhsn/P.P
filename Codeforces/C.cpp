#include <bits/stdc++.h>
#include <cmath>
using namespace std;

#define f(i, k, n, c)   for(decltype(k+n) i=k; i<n; i c)
#define fr(i, k, n, c)  for(decltype(k+n) i=k; i>n; i c)
#define ff(i, n)        for(decltype(n)   i=0; i<n; i++)
typedef long long ll;



int main()
{
	std::ios::sync_with_stdio(false);
	int n, m, l, k;
	cin >> n >> m;
	vector<pair<int, int>> v;
	f(i, 0, n, ++) {
		cin >> l >> k;
		v.push_back({l, k});
	}
	int max=-200000000;
	ff(j, m){
		cin >> l;
		ff(h, v.size()) {
			int ass = v[h].second*l + v[h].first;
			if(max < ass)
			{
				max=ass;
			}
		}
		cout << max << " ";
		max=-200000000;
	}
	return 0;
}