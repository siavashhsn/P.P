#include <iostream>
#include <string>
using namespace std;

int main()
{
string s, ss;
int a=0, aa=0;

cin >> s >> ss;
for(int i = 0; i < s.length(); i++)
{	
	if(s[i] >= 'A' && s[i] <= 'Z') s[i]+=32;
	if(ss[i] >= 'A' && ss[i] <= 'Z') ss[i]+=32;
	if(s[i] != ss[i])
	{
		if(s[i] < ss[i])
        		cout << -1;
		else
		        cout << 1;
		return 0;
	}
}
cout << 0;

return 0;
}
