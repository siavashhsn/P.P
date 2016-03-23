#include <bits/stdc++.h>
using namespace std;

int main()
{
	multiset<unsigned long> s1, s2;
	int n, a;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		cin >> a;
		s1.insert(a);
		s2.insert(a);
	}
	//for(set<unsigned long>::iterator i = s1.begin(); i != s1.end(); i++)
	//    cout << *i << endl;
	for(int i=0; i<n-1; i++)
	{
	        cin >> a;
	        s1.erase(s1.find(a));
	}
	cout << *s1.begin() << endl;
	unsigned long aa = *s1.begin();
	s2.erase(s2.find(aa));
	for(int i=0; i<n-2; i++)
	{
	        cin >> a;
	        s2.erase(s2.find(a));
	}
        cout << *s2.begin();
return 0;
}

