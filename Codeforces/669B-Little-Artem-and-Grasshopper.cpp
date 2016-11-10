#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;

int main()
{
	int n; cin >> n;
	string s; cin >> s;
	vector<ll> v;
	ll m, b=0;
	v.push_back(0);
	for(int i=0; i<n; i++) {
		cin >> m;
		v.push_back(m);
	}
	set<ll> a;
	int i=1;

	while(true) {
		if(s[i-1]=='>') {
			if(i+v[i]>n) {
				cout << "FINITE";
				return 0;
			}
			else {
				if(a.count(i+v[i])) {
					cout << "INFINITE";
					return 0;
				}
				a.insert(i+v[i]);
				i+=v[i];
			}
		}
		else {
			if(i-v[i]<1) {
				cout << "FINITE";
				return 0;
			}
			else {
				if(a.count(i-v[i])) {
					cout << "INFINITE";
					return 0;
				}
				a.insert(i-v[i]);
				i-=v[i];
			}
		}
	}
	return 0;
}