#include <iostream>
#include <string>
using namespace std;

int main()
{
string s, ss;	
cin >> s;
for(int i = 0; i< s.length(); i++)
{
	if(i <= s.length()-3 &&  s[i] == 'W' && s[i+1] == 'U' && s[i+2] == 'B')
	{	i+=2; if( ss[0] >= 'A' && ss[0] <= 'z') ss+=' ';  }
	else
	{
		ss+=s[i];
	}
}
cout << ss;
}//end main
