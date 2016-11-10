#include <bits/stdc++.h>
using namespace std;

#define ff(i, k, n, c)   for(decltype(k+n) i=k; i<n; i c)
#define fr(i, k, n, c)  for(decltype(k+n) i=k; i>n; i c)
#define f(i, n)        for(decltype(n)   i=0; i<n; i++)
typedef long long ll;
typedef pair<ll, ll> pp;



int main()
{
	std::ios::sync_with_stdio(false);
	int n ;cin >> n;
	string s;
	cin >> s;
	string ss="";
	if(n%2==0)
	{
		f(i, n){
			cout<<s[i];
			if(i%2 && i!=n-1)
				cout<<"-";

		}
	}
	else{
		f(i, n-3){
			cout << s[i];
			if(i%2)
				cout << "-";
		}
		cout<<s[n-3]<<s[n-2]<<s[n-1];
	}

	return 0;
}