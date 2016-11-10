#include <iostream>
#include <string>

using namespace std;
int main()
{
	string s="";
	int n;
	cin >> n;
	for(int i=1; i<=1000; i++) {
		s+=to_string(i);
		if(s.length()-1 >= n){
			cout << s[n-1];
			return 0;
		}
	}
	return 0;
}