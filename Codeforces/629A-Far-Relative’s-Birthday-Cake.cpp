#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll f(int n) {
	return n*(n-1)/2;
}

int main()
{
	int n;
	cin >> n;
	string s;
	vector<ll> r;
	vector<ll> c;
	for (int i = 0; i < n; ++i)
	{
		r.push_back(0);
		c.push_back(0);
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> s;
		for (int j = 0; j < n; ++j)
		{
			if(s[j] == 'C') {
				r[i]++;
				c[j]++;
			}
		}
	}
	ll count=0;
	for (int i = 0; i < n; ++i)
	{
		if(r[i] > 1)
			count += f(r[i]);
		if(c[i] > 1)
			count += f(c[i]);
	}
	cout << count;
	return 0;
}