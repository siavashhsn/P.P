#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
string s;
map<char, int> m;
cin >> s;
for(int i=0; i < s.length(); i++){
	char x = s[i];	m[x]++;
}
if(m.size()%2==0) cout << "CHAT WITH HER!";
else cout << "IGNORE HIM!";

return 0;
}
