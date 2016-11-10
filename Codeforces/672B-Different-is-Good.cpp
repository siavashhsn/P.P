#include <iostream>
#include <string>
using namespace std;
int a[26]={0};
int main()
{
	string s="";
	int n;
	long long cz=26, c=0;
	cin >> n >> s;
	for (int i = 0; i < n; ++i) {
		a[s[i]-97]++;
	}
	for(int i=0; i<s.length();i++) {
		if(a[s[i]-97]>1) {
			int k=-1;
			for (int j = 0; j < 26; j++) {
				if(a[j]==0) {
					k=j;
				}
			}
			if(k==-1) {
				cout << -1;
				return 0;
			}
			else {
				a[k]++;
				a[s[i]-97]--;
				c++;
			}
		}
	}
	cout << c;
	return 0;
}