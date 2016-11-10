#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

#define f(i, k, n, c)   for(decltype(k+n) i=k; i<n; i c)
#define fr(i, k, n, c)  for(decltype(k+n) i=k; i>n; i c)
#define ff(i, n)        for(decltype(n)   i=0; i<n; i++)


vector<int> sti(string s){
	vector<int> v;
	for(int i=0; i<s.length(); i++){
		v.push_back(s[i]-48);	
	}
	return v;
}

int main()
{
	int a;
	cin >> a;
	string s, ss;
	cin >> s >> ss;
	vector<int> v, vv;
	v = sti(s);
	vv = sti(ss);
	int c=0;
	int b=0;
	ff(i, v.size()){	
		b = abs(v[i] - vv[i]);
		if(b>5)
			b-=10;
		b=abs(b);
		c+=b;
	}

	cout<<c;

	return 0;	
}