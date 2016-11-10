#include <map>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
#define f(i, k, n, c) 	for(decltype(k+n) i=k; i<n; i c)
#define fr(i, k, n, c)	for(decltype(k+n) i=k; i>n; i c)
#define ff(i, n)      	for(decltype(n)   i=0; i<n; i++)
typedef long long ll;

string _itos(ll n) 
{
	string s="";
	while(n>0){
		s+=n%10 + 48;
		n/=10;
		cout << n;
	}
	cout << endl << s << endl;
	string ss="";
	fr(i, s.length()-1, -1, --)
		ss+=s[i];
	return ss;
}

ll _stoi(string s) 
{
	ll n=0;
	if(n>0) {
		f(i, 0, s.length(), ++) {
			n+=s[i]-48;
			if(i!=s.length()-1)
				n*=10;
		}
	}
	return n;
}

int main()
{
	ll n; cin >> n;
	string s;cin >> s;
	cout << _itos(n) << endl;
	cout << _stoi(s) << endl;

	return 0;
}