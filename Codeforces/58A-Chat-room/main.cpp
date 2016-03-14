#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    cin >> s;
    size_t i=0, j=0;
    string ss = "hello";
    while(s[i] != ss[j])
        i++;
    while(i < s.length())
    {
        if(s[i] == ss[j])
        {
            i++;
            j++;
            if(j==ss.length())
            {
                cout << "YES";
                return 0;
            }
        }
        else if(s[i] != ss[j])
        {
            i++;
        }
    }
    if(j!= ss.length())
        cout << "NO";
    return 0;
}
