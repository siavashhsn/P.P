#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;cin >> n;
	if(n%4==0||n%7==0||n%77==0||n%74==0||n%44==0||n%47==0)cout << "YES";
	else if(n==47||n==74||n==77||n==44||n==777||n==477||n==447||
			n==444||n==747||n==474||n==744||n==774)
		cout << "YES";
	else cout << "NO";
return 0;
}
