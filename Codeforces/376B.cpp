#include <bits/stdc++.h>
using namespace std;

#define ff(i, k, n, c)  for(decltype(k+n) i=k; i<n; i c)
#define fr(i, k, n, c)  for(decltype(k+n) i=k; i>n; i c)
#define f(i, n)        	for(decltype(n)   i=0; i<n; i++)			
typedef long long ll;
typedef pair<int, int> pp;
typedef vector<pp> vp;
vector<pp> a[105];

int main()
{
	std::ios::sync_with_stdio(false);
	set<int> s;
	int n, m, p, q, l, sum=0;
	cin >> n >> m;
	f(i, m){
		cin >> p >> q >> l;
		a[p].push_back({l, q});
		sum+=l;
		s.insert(p);
	}
	for(auto& i:s){
		vp v = a[i];
		f(j, v.size()){
			if(v[j].first){
				vp vv=a[v[j].second];
				sort(vv.begin(), vv.end());
				int b=v[j].first;
				f(k, vv.size()){
					int bb = vv[k].first;
					if(vv[k].first){
						if(bb<=b){
							sum -= bb;
							vv[k].first = 0;
							v[j].first -= bb;
							b-=bb;
							if(b==0)
								break;
						}
						else {
							sum -= b;
							vv[k].first -= b;
							v[j].first = 0;
							b=0;
							break;
						}
					}
				}
			}
		}
	}
	cout << sum;


	return 0;
}