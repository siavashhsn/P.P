#include <iostream>
#include <string>
using namespace std;

int main()
{

	string s;
	cin >> s;
	int counter =0;
	for (int i = 0; i < s.length(); i++){
		if( i+1 < s.length() &&  s[i] == s[i+1]){
			counter++;
			if(counter == 6){
                        	cout << "YES";
                      		return 0;
			}
		}
		else
                        counter = 0;
		if(i == s.length()-1 &&  s[i] == s[i-1])
		{	counter++; if(counter == 6) {cout << "YES"; return 0;}}
	}
cout << "NO";
return 0;
}
