#include <iostream>
#include <string>
using namespace std;

#define f(i, n) for(int i=0; i<n; i++)

int main()
{
	string s;
	cin >> s;
	long long a=0;
	for(int i=0; i<s.length(); i++){
		if(s[i]<='Z')
			a++;
	}
	if(a>s.length()-a)
		f(i, s.length()){
			if(s[i]>='a')
				s[i]-='a'-'A';
		}
	else
		f(i, s.length()){
			if(s[i]<='Z')
				s[i]+='a'-'A';
		}
	cout << s;
	return 0;
}